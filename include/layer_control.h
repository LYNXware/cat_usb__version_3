#ifndef LAYER_CONTROL_H
#define LAYER_CONTROL_H

#include <Arduino.h>

#include "constants.h"
#include "neopixel-LED.h"
#include "cat-now.h"


class Layer_Control {

public:

    // varable for the active layer
    byte active_layer; 

    // initialize  the pins for leds and set the layer to major-main
    void initialize();

    // function to switch the layers
    void switch_layer(char c);

    // switch back to the previous layer 
    // if the key is pressed longer than min_hold_time
    void switch_layer_back(char c);


    void received_layer_switch(u8_t layer);


private:
    // variables for switch_layer_back function
    unsigned long press_start;
    unsigned long hold_time;
    // the layer will be switch back if the key is pressed longer than min_hold_time
    const int min_hold_time = 500;

};

extern Layer_Control layer_control;

#endif