#ifndef FINGER_MODULE_H
#define FINGER_MODULE_H

#include <Arduino.h>

#include "PINs.h"
#include "events.h"
#include "events_map.h"


class Finger_Module {

public:

    // initializing the finger module
    void initialize();

    // read the state of the finger module events
    void read_keystate();

    bool trigger_print_scan_codes();

private:

    const byte outPin_f_count = 6;
    const byte inPin_f_count = 4;

    const uint8_t outPin_f[6] = {PIN_FINGER_MOD_OUTPUT_1,
                                PIN_FINGER_MOD_OUTPUT_2,
                                PIN_FINGER_MOD_OUTPUT_3,
                                PIN_FINGER_MOD_OUTPUT_4,
                                PIN_FINGER_MOD_OUTPUT_5,
                                PIN_FINGER_MOD_OUTPUT_6};
    
    const uint8_t inPin_f[4] = {PIN_FINGER_MOD_INPUT_1,
                                PIN_FINGER_MOD_INPUT_2,
                                PIN_FINGER_MOD_INPUT_3,
                                PIN_FINGER_MOD_INPUT_4};


    uint8_t f_index;
    
    // events map of the finger module keys
                            // u1  u2  u3  u4  u5  u6     
    const byte f_map[4][6] = {{ EVENT_I7, EVENT_I4, EVENT_M4, EVENT_R4, EVENT_P3, EVENT_P5},   // j1      // button layout for left side
                              { EVENT_I6, EVENT_I3, EVENT_M3, EVENT_R3, EVENT_P2, EVENT_P4},   // j2 
                              { EVENT_I5, EVENT_I2, EVENT_M2, EVENT_R2, EVENT_P1, EVENT_EMPTY},   // j3 
                              { EVENT_WM, EVENT_I1, EVENT_M1, EVENT_R1, EVENT_EMPTY, EVENT_EMPTY}};  // j4      // case 99 will never happen

    // state (pressed/released) of the finger module keys
    bool f_state[4][6] = {{0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0}};

};


// creating an instance of the Finger_Module class
extern Finger_Module fingerModule;

#endif

    // declaring inputs and outputs for finger buttons moudule
    //                         // u1  u2  u3  u4  u5  u6
    // const byte outPin_f[6] = {1, 2, 42, 41, 40, 39}; //declaring output pins for finger buttons moudule

    //                         // j1  j2  j3  j4    
    // const byte inPin_f[4] = {38, 37, 36, 35};  //declaring inputs pins for finger buttons moudule   



    // internal variables
    // byte fo;
    // byte fi;