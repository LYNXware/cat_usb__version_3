#ifndef THUMB_MODULE_H
#define THUMB_MODULE_H

#include <Arduino.h>
#include "events.h"
#include "config.h"




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

        
        #if thumb_module == 0            
        // events map of the thumb module keys
            const byte t_map[4][3] = {{29,  30,   25},
                                      {28,  31,   26},
                                      {24,  27,   20},
                                      {23,  22,   21}};

        #elif thumb_module == 1  
        // events map of the thumb module keys
            const byte t_map[4][3] = {{29,  30,   25},
                                      {24,  31,   20},
                                      {28,  27,   26},
                                      {23,  22,   21}};
        #endif



        // state of the thumb module keys
        bool t_state[4][3] = {{0, 0, 0},
                              {0, 0, 0},
                              {0, 0, 0},
                              {0, 0, 0}};

};

// creating an instance of the Thumb_Module class
extern Thumb_Module thumbModule;

#endif