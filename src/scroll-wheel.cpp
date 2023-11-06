#include "scroll-wheel.h"



    
void Scroll_Wheel::initialize(){

    pinMode(encoder_GND,OUTPUT);
    digitalWrite(encoder_GND,LOW);

    pinMode (encoder_a,INPUT_PULLUP);
    pinMode (encoder_b,INPUT_PULLUP);
    
    previous_state = digitalRead(encoder_a);   

    if (config.device_side == LEFT) {
        forward_scroll = EVENT_WF;
        backward_scroll = EVENT_WB;
    }
    else if (config.device_side == RIGHT) {
        forward_scroll = EVENT_WB;
        backward_scroll = EVENT_WF;
    }

} 



void Scroll_Wheel::read_encoder(){

    state = digitalRead(encoder_a);

    if (state != previous_state) {
        // Check if the rising edge of the encoder signal has occurred
         // Add a small delay for debouncing
        // delay(5);

        // if (digitalRead(encoder_a) == state) {
        if (state == HIGH) {
            if (digitalRead(encoder_b) != state) {   
                // Clockwise
                event.actuate(forward_scroll);
                event.deactuate(forward_scroll);
                // delay(1);
            } 
            else {                                 
                // Counterclockwise
                event.actuate(backward_scroll);
                event.deactuate(backward_scroll);
                // delay(1);    
            }
        }
    } 
    previous_state = state;
} 

Scroll_Wheel scroll_wheel;