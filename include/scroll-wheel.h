#ifndef SCROLL_WHEEL_H
#define SCROLL_WHEEL_H

#include <Arduino.h>

#include "events.h"
#include "config.h"


class Scroll_Wheel {

public:

    void initialize();
    void read_encoder();

private:

    // // encoder pins
    #define encoder_a 45    //a2
    #define encoder_b 48    //a1
    #define encoder_GND 0   //a1

    uint8_t forward_scroll;
    uint8_t backward_scroll;

    byte previous_state;  
    byte state;

    

}; 

extern Scroll_Wheel scroll_wheel;





#endif