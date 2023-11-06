#ifndef THUMB_MODULE_H
#define THUMB_MODULE_H

#include <Arduino.h>
#include "events.h"
#include "config.h"
#include "events_map.h"



class Thumb_Module {

public:

    // initialize the thumb module
    void initialize();

    // read the state of the thumb module events
    void read_keystate();

private:

    //declaring inputs and outputs tor thumb buttons moudule
    const byte outPin[3] = {6, 5, 4};         
    const byte inPin[4] = {7, 15, 16, 17};    
    const byte outPin_count = 3;
    const byte inPin_count = 4;

    // internal variables
    byte to;
    byte ti;
    byte t_index;

    byte t_map[4][3];

    // state of the thumb module keys
    bool t_state[4][3] = {{0, 0, 0},
                            {0, 0, 0},
                            {0, 0, 0},
                            {0, 0, 0}};


};

// creating an instance of the Thumb_Module class
extern Thumb_Module thumbModule;

#endif





// #if thumb_module == 0            
// // events map of the thumb module keys
//     const byte t_map[4][3] = {{29,  30,   25},
//                                 {28,  31,   26},
//                                 {24,  27,   20},
//                                 {23,  22,   21}};

// #elif thumb_module == 1  
// // events map of the thumb module keys
//     const byte t_map[4][3] = {{29,  30,   25},
//                                 {24,  31,   20},
//                                 {28,  27,   26},
//                                 {23,  22,   21}};
// #endif


    // void define_t_map() {
    //     if (config.thumb_module == JUST_KEYS) {
    //         t_map[4][3] = {{EVENT_TB5, EVENT_TC3, EVENT_TB1},
    //                        {EVENT_TB4, EVENT_JM, EVENT_TB2},
    //                        {EVENT_TA5, EVENT_TB3, EVENT_TA1},
    //                        {EVENT_TA4, EVENT_TA3, EVENT_TA2}};
    //     } else if (config.thumb_module == KEYS_AND_JOYSTICK) {
    //         t_map[4][3] = {{EVENT_TB5, EVENT_TC3, EVENT_TB1},
    //                        {EVENT_TA5, EVENT_JM, EVENT_TA1},
    //                        {EVENT_TB4, EVENT_TB3, EVENT_TB2},
    //                        {EVENT_TA4, EVENT_TA3, EVENT_TA2}};
    //     }
    // }
    // Declare t_map as a member variable
    // int t_map[4][3];  // Adjust the data type accordingly

    // if (config.thumb_module == JUST_KEYS) {
    //     t_map[4][3] = {{EVENT_TB5,  EVENT_TC3,   EVENT_TB1},
    //                     {EVENT_TB4,  EVENT_JM,   EVENT_TB2},
    //                     {EVENT_TA5,  EVENT_TB3,   EVENT_TA1},
    //                     {EVENT_TA4,  EVENT_TA3,   EVENT_TA2}};
    // }
    // else if (config.thumb_module == KEYS_AND_JOYSTICK) {
    //     t_map[4][3] = {{EVENT_TB5,  EVENT_TC3,   EVENT_TB1},
    //                     {EVENT_TA5,  EVENT_JM,   EVENT_TA1},
    //                     {EVENT_TB4,  EVENT_TB3,   EVENT_TB2},
    //                     {EVENT_TA4,  EVENT_TA3,   EVENT_TA2}};
    // }




