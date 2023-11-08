#include "finger_module.h"



void Finger_Module::initialize(){

    //initializing outputpins of finger module
    for(byte j=0; j<outPin_f_count; j++){    
        pinMode(outPin_f[j],OUTPUT);
        digitalWrite(outPin_f[j],HIGH);  
    }
    //initializing inputpins of finger module
    for(byte j=0; j<inPin_f_count; j++){     
        pinMode(inPin_f[j],INPUT_PULLUP);
    }
}



void Finger_Module::read_keystate()
{
    //looping through Outputpins and setting one at a time to LOW 
    for (uint8_t fo=0; fo<outPin_f_count; fo++){     

        digitalWrite(outPin_f[fo],LOW);
        // delay(100);   
        
        // looping through Inputpins and checking for the LOW state of outputpins
        for (uint8_t fi=0; fi<inPin_f_count; fi++)
        {
            f_index = f_map[fi][fo];

            if (digitalRead(inPin_f[fi]) == LOW && f_state[fi][fo] == 0)
            {                
                event.actuate(f_index); 
                f_state[fi][fo] = 1;

                Serial.print("ac.: ");
                Serial.println(f_index);   
            }
            else if (digitalRead(inPin_f[fi]) == HIGH && f_state[fi][fo] == 1)
            {                
                event.deactuate(f_index); 
                f_state[fi][fo] = 0;

                Serial.print("de.: "); 
                Serial.println(f_index);
            }


        }      
         //setting the Outputpin back to HIGH state
        digitalWrite(outPin_f[fo],HIGH);             
    }
}

// creating an instance of the Finger_Module class
Finger_Module fingerModule;



            // if (digitalRead(inPin_f[fi]) == LOW && f_state[fi][fo] == 0){
                
            //     event.actuate(f_index); 
            //     f_state[fi][fo] = 1;
                
            // }
            // else if (digitalRead(inPin_f[fi]) == HIGH && f_state[fi][fo] == 1){
                
            //     event.deactuate(f_index); 
            //     f_state[fi][fo] = 0;
 
            // }
            // else {     
            //     // if(f_state[fi][fo] == 1){
            //     //     event.deactuate(f_index);
            //     //     f_state[fi][fo] = 0;
            //     // }
            //     // do nothing   
            // }