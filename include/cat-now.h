#ifndef CAT_NOW_H
#define CAT_NOW_H

#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>

#include "config.h"
#include "layer_control.h"



class CatNow {

public:

    void initialize();

    void scan_for_partner();

    void send_switch_layer(uint8_t layer);

    void send_layer_latch();

    void send_gyto_state(uint8_t state);

    
private:

    // wife credentials
    #define CHANNEL 1
    String cat_wifi = "LYNX-"; // + cat_variant;

    // mac address of the receiver/partner
    int mac[6];
    // peer = receiver/partner
    esp_now_peer_info_t peerInfo;

    bool peer_checked = false;
    bool peer_available = false;


    // esp-now callbacks
    static void OnDataSent(const uint8_t* mac_addr, esp_now_send_status_t status);
    static void OnDataReceived(const uint8_t* mac_addr, const uint8_t* data, int data_len); 
};


//instance of the class 
extern CatNow catnow;

#endif