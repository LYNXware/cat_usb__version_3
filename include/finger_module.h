#ifndef FINGER_MODULE_H
#define FINGER_MODULE_H

#include <Arduino.h>

#include "events.h"


class Finger_Module {

    public:

        // initializing the finger module
        void initialize();

        // read the state of the finger module events
        void read_keystate();


    private:




        // declaring inputs and outputs for finger buttons moudule
                               // u1  u2  u3  u4  u5  u6
        const byte outPin_f[6] = {1, 2, 42, 41, 40, 39}; //declaring output pins for finger buttons moudule

                                // j1  j2  j3  j4    
        const byte inPin_f[4] = {38, 37, 36, 35};  //declaring inputs pins for finger buttons moudule   



        // // declaring inputs and outputs for finger buttons moudule
        //                        // u1  u2  u3  u4  u5  u6
        // const byte outPin_f[6] = {42, 41, 40, 39, 38, 37}; //declaring output pins for finger buttons moudule

        //                         // j1  j2  j3  j4    
        // const byte inPin_f[4] = {45, 48, 47, 21};  //declaring inputs pins for finger buttons moudule   

        const byte outPin_f_count = 6;
        const byte inPin_f_count = 4;

        // internal variables
        byte fo;
        byte fi;
        byte f_index;

        // events map of the finger module keys
                                // u1  u2  u3  u4  u5  u6     
        const byte f_map[4][6] = {{ 6,  3, 10, 14, 17, 19},   // j1      // button layout for left side
                                  { 5,  2,  9, 13, 16, 18},   // j2 
                                  { 4,  1,  8, 12, 15, 99},   // j3 
                                  {42,  0,  7, 11, 99, 99}};  // j4      // case 99 will never happen

        // state (pressed/released) of the finger module keys
        bool f_state[4][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0}};

};

// creating an instance of the Finger_Module class
extern Finger_Module fingerModule;

#endif