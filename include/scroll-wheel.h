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

        #if side == 0
            //left side          
            #define forward_scroll 43
            #define backward_scroll 41

        #elif side == 1  
            //right side
            #define forward_scroll 41
            #define backward_scroll 43
        #endif

        byte previous_state;  
        byte state;
        // byte value = 0; 
        // int scroll_value = 0;
    

}; 

extern Scroll_Wheel scroll_wheel;





#endif