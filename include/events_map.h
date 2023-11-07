#ifndef EVENTS_MAP_H
#define EVENTS_MAP_H

#include <Arduino.h>



// index finger events
#define EVENT_I1 0
#define EVENT_I2 1
#define EVENT_I3 2
#define EVENT_I4 3
#define EVENT_I5 4
#define EVENT_I6 5
#define EVENT_I7 6

// middle finger events
#define EVENT_M1 7
#define EVENT_M2 8
#define EVENT_M3 9
#define EVENT_M4 10

// ring finger events
#define EVENT_R1 11
#define EVENT_R2 12
#define EVENT_R3 13
#define EVENT_R4 14

// pinky finger events
#define EVENT_P1 15
#define EVENT_P2 16
#define EVENT_P3 17
#define EVENT_P4 18
#define EVENT_P5 19

// thumb events
#define EVENT_TA1 20
#define EVENT_TA2 21
#define EVENT_TA3 22
#define EVENT_TA4 23
#define EVENT_TA5 24
#define EVENT_TB1 25
#define EVENT_TB2 26
#define EVENT_TB3 27
#define EVENT_TB4 28
#define EVENT_TB5 29
#define EVENT_TC3 30

// joystick events
#define EVENT_JM 31 // middle button
#define EVENT_JS 32 // steps

#define EVENT_JF1 33 // forward 1
#define EVENT_JF2 34 // forward 2
#define EVENT_JB1 35 // backward 1
#define EVENT_JB2 36 // backward 2
#define EVENT_JL1 37 // left/up 1
#define EVENT_JL2 38 // left/up 2
#define EVENT_JR1 39 // right/down 1
#define EVENT_JR2 40 // right/down 2

// scroll wheel events
#define EVENT_WM 41 // scroll wheel button
#define EVENT_WF 42 // forward
#define EVENT_WB 43 // backward
#define EVENT_WS 44 // speed

// mouse 
#define EVENT_M_NF 45 // on/off
#define EVENT_MH 46 // horizontal speed
#define EVENT_MV 47 // vertical speed


// GA-module (gyroscope accelerometer module)
#define EVENT_GA_NF 48 // on/off
#define EVENT_GA_M 49 // include mouse fuctionality
#define EVENT_GA_MSF 50 // mouse speed factor
#define EVENT_GA_MXD 51 // mouse x direction
#define EVENT_GA_MYD 52 // mouse y direction
#define EVENT_GA_F 51 // forward
#define EVENT_GA_B 52 // backward
#define EVENT_GA_L 53 // left
#define EVENT_GA_R 54 // right  

#define EVENT_EMPTY 99 // empty event

#endif
