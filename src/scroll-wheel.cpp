#include "scroll-wheel.h"


void Scroll_Wheel::initialize()
{
    pinMode(PIN_FINGER_MOD_WHEEL_GND,OUTPUT);
    digitalWrite(PIN_FINGER_MOD_WHEEL_GND,LOW);

    if (config.device_side == LEFT) {
        encoder_a = PIN_FINGER_MOD_WHEEL_B;
        encoder_b = PIN_FINGER_MOD_WHEEL_A; 
    }
    else if (config.device_side == RIGHT) {
        encoder_a = PIN_FINGER_MOD_WHEEL_A; 
        encoder_b = PIN_FINGER_MOD_WHEEL_B; 
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