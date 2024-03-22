#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <Arduino.h>

#include "layer_control.h"
#include "layouts_manager_cat.h"
#include "events.h"



class Joystick {

public:

    void initialize();
    void read_joystick();

private:
       
    int joystickValues[2];

    // declaring the joystick thresholds
    // const int threshold_l1 = 1600;
    const int threshold_l1 = 1600;
    const int threshold_l2 = 50;
    // const int threshold_h1 = 2300;
    const int threshold_h1 = 2300;
    const int threshold_h2 = 4045;
    
    // declaring the joystick events
                                    //  JF1, JF2, JB1,  JB2,  JL1,  JL2, JR1, JR2
    byte joystick_event_map[2][4] = {{33,  34,  35,  36},  {39,  40,  37,  38}};

    bool joystick_state[2][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}};

    void one_step();
    void two_step();

    void actuate_event(byte axis, byte axis_event);
    void deactuate_event(byte axis, byte axis_event);
};

extern Joystick joystick;
#endif


