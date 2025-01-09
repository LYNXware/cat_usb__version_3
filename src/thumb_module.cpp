#include "thumb_module.h"


void Thumb_Module::initialize()
{
    for(byte j=0; j<outPin_count; j++)
    {
        pinMode(outPin[j],OUTPUT);
        digitalWrite(outPin[j],HIGH);  
    }
    for(byte j=0; j<inPin_count; j++)
    {
        pinMode(inPin[j],INPUT_PULLUP);
    }

    if (config.thumb_module == JUST_KEYS) {
        t_map[0][0] = EVENT_TB5;
        t_map[0][1] = EVENT_TC3;
        t_map[0][2] = EVENT_TB1;
        t_map[1][0] = EVENT_TB4;
        t_map[1][1] = EVENT_JM;
        t_map[1][2] = EVENT_TB2;
        t_map[2][0] = EVENT_TA5;
        t_map[2][1] = EVENT_TB3;
        t_map[2][2] = EVENT_TA1;
        t_map[3][0] = EVENT_TA4;
        t_map[3][1] = EVENT_TA3;
        t_map[3][2] = EVENT_TA2;
    }
    else if (config.thumb_module == KEYS_AND_JOYSTICK) {
        t_map[0][0] = EVENT_TB5;
        t_map[0][1] = EVENT_TC3;
        t_map[0][2] = EVENT_TB1;
        t_map[1][0] = EVENT_TA5;
        t_map[1][1] = EVENT_JM;
        t_map[1][2] = EVENT_TA1;
        t_map[2][0] = EVENT_TB4;
        t_map[2][1] = EVENT_TB3;
        t_map[2][2] = EVENT_TB2;
        t_map[3][0] = EVENT_TA4;
        t_map[3][1] = EVENT_TA3;
        t_map[3][2] = EVENT_TA2;
    }
}


void Thumb_Module::read_keystate()
{
    // looping through Outputpins and setting them to LOW
    for (to=0; to<outPin_count; to++)
    {         
        digitalWrite(outPin[to],LOW);   
        
        for (ti=0; ti<inPin_count; ti++)
        {
            t_index = t_map[ti][to];

            if (digitalRead(inPin[ti]) == LOW && t_state[ti][to] == 0)
            {
                event.actuate(t_index);
                t_state[ti][to] = 1;
                delay(debounceDelay);
                // Serial.print("a.: ");
                // Serial.println(t_index);
            }
            else if (digitalRead(inPin[ti]) == HIGH && t_state[ti][to] == 1)
            {
                event.deactuate(t_index);
                t_state[ti][to] = 0;
                // Serial.print("d.: ");
                // Serial.println(t_index);
            }
        }
        digitalWrite(outPin[to],HIGH);
    }
}


// creating an instance of the Thumb_Module class
Thumb_Module thumbModule;

