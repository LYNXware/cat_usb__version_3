#include "scroll-wheel.h"

Scroll_Wheel scroll_wheel;


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


void Scroll_Wheel::read_encoder()
{
    state_a = digitalRead(encoder_a);
    state_b = digitalRead(encoder_b);

    // Clockwise
    if (state_a != state_a_prev
        && state_a == HIGH
        && state_b == LOW)
    {
        event.actuate(EVENT_WF);
        event.deactuate(EVENT_WF);
    }

    // Counterclockwise
    if (state_b != state_b_prev
        && state_b == HIGH
        && state_a == LOW)
    {
        event.actuate(EVENT_WB);
        event.deactuate(EVENT_WB);
    }

    state_a_prev = state_a;
    state_b_prev = state_b;
} 


// void Scroll_Wheel::read_encoder()
// {
//     state_a = digitalRead(encoder_a);
//     state_b = digitalRead(encoder_b);

//     if (state_a != state_a_prev)
//     {
//         if (state_a == HIGH) 
//         {
//             if (state_b == LOW)
//             {
//                 // Clockwise
//                 event.actuate(EVENT_WF);
//                 event.deactuate(EVENT_WF);
//             } 
//         }
//     }
//     if (state_b != state_b_prev)
//     {
//         if (state_b == HIGH) 
//         {
//             if (state_a == LOW)
//             {
//                 // Counterclockwise
//                 event.actuate(EVENT_WB);
//                 event.deactuate(EVENT_WB);
//             } 
//         }
//     }
//     state_a_prev = state_a;
//     state_b_prev = state_b;
// } 


// void Scroll_Wheel::read_encoder(){

//     state = digitalRead(encoder_a);

//     if (state != previous_state) {
//         // Check if the rising edge of the encoder signal has occurred
//         if (state == HIGH) {
//             if (digitalRead(encoder_b) != state) {   
//                 // Clockwise
//                 event.actuate(EVENT_WF);
//                 event.deactuate(EVENT_WF);
//             } 
//             else {                                 
//                 // Counterclockwise
//                 event.actuate(EVENT_WB);
//                 event.deactuate(EVENT_WB);
//             }
//         }
//     } 
//     previous_state = state;
// } 


