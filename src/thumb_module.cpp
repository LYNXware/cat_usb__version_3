#include "thumb_module.h"


void Thumb_Module::initialize(){

    for(byte j=0; j<outPin_count; j++){
        pinMode(outPin[j],OUTPUT);
        digitalWrite(outPin[j],HIGH);  
    }
    for(byte j=0; j<inPin_count; j++){
        pinMode(inPin[j],INPUT_PULLUP);
    }
}


void Thumb_Module::read_keystate() {

    // looping through Outputpins and setting them to LOW
    for (to=0; to<outPin_count; to++){            
        digitalWrite(outPin[to],LOW);   
        
        // looping through Inputpins and checking tor the LOW state of outputpins
        for (ti=0; ti<inPin_count; ti++){          

            t_index = t_map[ti][to];

            if (digitalRead(inPin[ti]) == LOW && t_state[ti][to] == 0){
                                          
                event.actuate(t_index);
                t_state[ti][to] = 1;
            }
            else if (digitalRead(inPin[ti]) == HIGH && t_state[ti][to] == 1){
                
                event.deactuate(t_index);
                t_state[ti][to] = 0;

            }
            else {
                // do nothing
            }
        }
        //setting the Outputpin back to HIGH state
        digitalWrite(outPin[to],HIGH);
    }
}


// creating an instance of the Thumb_Module class
Thumb_Module thumbModule;

