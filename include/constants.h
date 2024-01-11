#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <Arduino.h>


const char LEFT_CAT = 0x0c;
const char RIGHT_CAT = 0x0b;

const char DELIMITER_EVENT = 0xff; // b'\xff\xff'
const char DELIMITER_LAYOUT = 0xfe; // b'\xfe\xfe'

// const char DELIMITER_EVENT = 0x01;
// const char DELIMITER_LAYOUT = 0x02;


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


#endif