#include "cat-now.h"


//instance of the class
CatNow catnow;



void CatNow::initialize() 
{
    // Initialize Wi-Fi: simultanious (Station Mode) and WIFI_AP (Access Point Mode)
    WiFi.mode(WIFI_AP_STA);

    // set up an Access Point 
    WiFi.softAP(cat_wifi + config.variant, "Slave_1_Password", CHANNEL, 0);

    // Initialize ESP-NOW
    esp_now_init();

    // Register callback functions
    esp_now_register_send_cb(OnDataSent);
    esp_now_register_recv_cb(OnDataReceived);
}



void CatNow::scan_for_partner()
{
    // scan for recievers
    int8_t scanResults = WiFi.scanNetworks(false, false, false, 300, CHANNEL);
    
    // reset mac address
    memset(&peerInfo, 0, sizeof(peerInfo));

    for (int i = 0; i < scanResults; ++i) {

        // get SSID and RSSI for each device found
        String SSID = WiFi.SSID(i);
        int32_t RSSI = WiFi.RSSI(i);
        String BSSIDstr = WiFi.BSSIDstr(i);

        // Serial.printf("%d: %s (%d) %s\n", i + 1, SSID.c_str(), RSSI, BSSIDstr.c_str());
        // delay(10);

        // Check if the current device is a partner
        if (SSID.indexOf(cat_wifi) == 0) {

            // Get BSSID => Mac Address of the receiver/partner
            if ( 6 == sscanf(BSSIDstr.c_str(), "%x:%x:%x:%x:%x:%x%c", 
                &mac[0], &mac[1], &mac[2], &mac[3], &mac[4], &mac[5]))
            {
                for (int ii = 0; ii < 6; ++ii) {
                    peerInfo.peer_addr[ii] = (uint8_t) mac[ii];
                }
            }

            peerInfo.channel = CHANNEL; // pick a channel
            peerInfo.encrypt = false; // no encryption

            // Add peer        
            esp_now_add_peer(&peerInfo);
            peer_available = true;
        }
    }
    // clean up ram
    WiFi.scanDelete();
}


// Callback function for sending data
void CatNow::OnDataSent(const uint8_t* mac_addr, esp_now_send_status_t status)
{
//   Serial.println("OnDataSent");
}


// Callback function for receiving data
void CatNow::OnDataReceived(const uint8_t* mac_addr, const uint8_t* data, int data_len)
{       

    // Serial.print("Received data from: ");
    // Serial.print(data[0]);
    // Serial.print(" ");
    // Serial.print(data[1]);
    // Serial.print(" ");
    // Serial.println(data[2]);


    if (data[0] == 'c' && data[1] == 'l') 
    {
        uint8_t dynamicValue = data[2];
        layer_control.received_layer_switch(dynamicValue);
    }

    else if (data[0] == 'c' && data[1] == 'g')
    {
        if (data[2] == 1)
        {
            mpu6050.trigger_state = true;
        }
        else if (data[2] == 0)
        {
            mpu6050.trigger_state = false;
        }
    }
}


void CatNow::send_switch_layer(uint8_t layer)
{
    if (peer_available == false) 
    {
        scan_for_partner();
        // scan_for_slave();
    }

    uint8_t data[] = {'c', 'l', layer};

    // Serial.print(data[0]);
    // Serial.print(" ");
    // Serial.print(data[1]);
    // Serial.print(" ");
    // Serial.println(data[2]);

    // Send the data using ESP-NOW
    esp_now_send(peerInfo.peer_addr, data, sizeof(data));
}



void CatNow::send_gyto_state(uint8_t state)
{
    if (peer_available == false) 
    {
        scan_for_partner();
        // scan_for_slave();
    }

    uint8_t data[] = {'c', 'g', state};

    // Send the data using ESP-NOW
    esp_now_send(peerInfo.peer_addr, data, sizeof(data));
}




// void CatNow::scan_for_slave()
// {
//     int8_t scanResults = WiFi.scanNetworks(false, false, false, 300, CHANNEL);
    
//     // reset mac address
//     memset(&peerInfo, 0, sizeof(peerInfo));

//     if (scanResults == 0) {
//         Serial.println("No ESP32 devices nearby found");

//     } else {

//         Serial.print("Found ");
//         Serial.print(scanResults);
//         Serial.println(" device(s)");

//         for (int i = 0; i < scanResults; ++i) {

//             // Print SSID and RSSI for each device found
//             String SSID = WiFi.SSID(i);
//             int32_t RSSI = WiFi.RSSI(i);
//             String BSSIDstr = WiFi.BSSIDstr(i);

//             Serial.printf("%d: %s (%d) %s\n", i + 1, SSID.c_str(), RSSI, BSSIDstr.c_str());
//             delay(10);

//             // Check if the current device starts with `Slave`
//             if (SSID.indexOf(cat_wifi) == 0) {
//                 // SSID of interest
//                 Serial.println("Found a Slave.");
//                 // Get BSSID => Mac Address of the Slave
//                 int mac[6];
//                 if ( 6 == sscanf(BSSIDstr.c_str(), "%x:%x:%x:%x:%x:%x%c", 
//                     &mac[0], &mac[1], &mac[2], &mac[3], &mac[4], &mac[5])) {
//                     for (int ii = 0; ii < 6; ++ii) {
//                         peerInfo.peer_addr[ii] = (uint8_t) mac[ii];
//                     }
//                 }

//                 peerInfo.channel = CHANNEL; // pick a channel
//                 peerInfo.encrypt = false; // no encryption

//                 // Add peer        
//                 esp_now_add_peer(&peerInfo);
//                 peer_available = true;
//             }
//         }
//     }
//     // clean up ram
//     WiFi.scanDelete();
// }







