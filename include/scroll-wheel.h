#ifndef SCROLL_WHEEL_H
#define SCROLL_WHEEL_H

#include <Arduino.h>

#include "events.h"
#include "config.h"
#include "PINs.h"


// #define encoder_GND 0 //a1
// #define encoder_pinA 45 //a2
// #define encoder_pinB 48 //a3


class Scroll_Wheel {

public:

    void initialize();
    void read_encoder();



private:

    uint8_t encoder_a;   
    uint8_t encoder_b;    

    byte previous_state;  
    byte state;

    bool state_a;
    bool state_b;
    bool state_a_prev;
    bool state_b_prev;


    // uint8_t aSet;
    // uint8_t bSet;
    // uint8_t aSetPrev = 0;
    // uint8_t bSetPrev = 0;

    bool aSet = false;
    bool bSet = false;
    bool aSetPrev = false;
    bool bSetPrev = false;

}; 

extern Scroll_Wheel scroll_wheel;

#endif