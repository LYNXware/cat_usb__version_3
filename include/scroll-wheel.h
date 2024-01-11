#ifndef SCROLL_WHEEL_H
#define SCROLL_WHEEL_H

#include <Arduino.h>

#include "events.h"
#include "config.h"
#include "PINs.h"



class Scroll_Wheel {

public:

    void initialize();
    void read_encoder();


private:

    uint8_t encoder_a;   
    uint8_t encoder_b;    

    bool state_a;
    bool state_b;
    bool state_a_prev;
    bool state_b_prev;
    
}; 


extern Scroll_Wheel scroll_wheel;
#endif