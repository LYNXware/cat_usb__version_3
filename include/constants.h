#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <Arduino.h>

const char LEFT_CAT = 0x0c;
const char RIGHT_CAT = 0x0b;

const char DELIMITER_EVENT = 0x01;
const char DELIMITER_LAYOUT = 0x02;


const char MOUSE_FUNCTION = 0x10;
const char MOUSE_LEFT_CLICK = 0xf1;
const char MOUSE_MIDDLE_CLICK = 0xf2;
const char MOUSE_RIGHT_CLICK = 0xf3;
const char MOUSE_SCROLL_UP = 0xf4;
const char MOUSE_SCROLL_DOWN = 0xf5;


const char CAT_FUNCTION = 0x1a;

const char CAT_LAYER_SWITCH = 0xfa;
const char CAT_MAJOR_MINOR = 0xfb;
const char CAT_MAIN_SUB = 0xfc;

const char CAT_GYRO = 0xfd;

const char CAT_NONE = 0xf0;


// const char DELIMITER_DEVICE = 0x01;
// 
// 
// const char LAST_BYTE = 0x04;


// const char MOUSE_EVENT_LEFT_CLICK = 0x0a;
// const char MOUSE_EVENT_RIGHT_CLICK = 0x0b;
// const char MOUSE_EVENT_MIDDLE_CLICK = 0x0c;
// const char MOUSE_EVENT_SCROLL_UP = 0x0d;
// const char MOUSE_EVENT_SCROLL_DOWN = 0x0e;

// const char CAT_EVENT_MAIN_SUB = 0x10;
// const char CAT_EVENT_MAJOR_MINOR = 0x11;

#endif