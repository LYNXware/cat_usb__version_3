#ifndef SCROLL_WHEEL_H
#define SCROLL_WHEEL_H

#include <Arduino.h>

#include "events.h"
#include "config.h"


#define encoder_GND 0 //a1
#define encoder_pinA 45 //a2
#define encoder_pinB 48 //a3


class Scroll_Wheel {

public:

    void initialize();
    void read_encoder();

private:

    uint8_t encoder_a;   
    uint8_t encoder_b;    

    byte previous_state;  
    byte state;
}; 

extern Scroll_Wheel scroll_wheel;

#endif