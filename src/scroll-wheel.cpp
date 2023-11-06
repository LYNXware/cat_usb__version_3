#include "scroll-wheel.h"


void Scroll_Wheel::initialize()
{
    pinMode(encoder_GND,OUTPUT);
    digitalWrite(encoder_GND,LOW);

    if (config.device_side == LEFT) {
        encoder_a = encoder_pinB;
        encoder_b = encoder_pinA; 
    }
    else if (config.device_side == RIGHT) {
        encoder_a = encoder_pinA; 
        encoder_b = encoder_pinB; 
    }

    pinMode (encoder_a,INPUT_PULLUP);
    pinMode (encoder_b,INPUT_PULLUP);
    
    previous_state = digitalRead(encoder_a);   
} 



void Scroll_Wheel::read_encoder(){

    state = digitalRead(encoder_a);

    if (state != previous_state) {
        // Check if the rising edge of the encoder signal has occurred
        if (state == HIGH) {
            if (digitalRead(encoder_b) != state) {   
                // Clockwise
                event.actuate(EVENT_WF);
                event.deactuate(EVENT_WF);
                // delay(1);
            } 
            else {                                 
                // Counterclockwise
                event.actuate(EVENT_WB);
                event.deactuate(EVENT_WB);
                // delay(1);    
            }
        }
    } 
    previous_state = state;
} 


Scroll_Wheel scroll_wheel;