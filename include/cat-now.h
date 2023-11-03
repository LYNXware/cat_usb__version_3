#ifndef CAT_NOW_H
#define CAT_NOW_H

#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>

#include "config.h"
#include "layer_control.h"



class CatNow {

    public:

        // turn on wifi and CatNow
        void initialize();

        void scan_for_slave();

        void send_switch_layer(uint8_t layer);

    private:

        // wife credentials
        #define CHANNEL 1
        String wifi_name = "LYNX-"; // + cat_variant;

        // slave mac address
        esp_now_peer_info_t peerInfo;
        // peer is available
        bool peer_available = false;

        // esp-now callbacks
        static void OnDataSent(const uint8_t* mac_addr, esp_now_send_status_t status);
        static void OnDataReceived(const uint8_t* mac_addr, const uint8_t* data, int data_len); 

};

//instance of the class 
extern CatNow catnow;

#endif