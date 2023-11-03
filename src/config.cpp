#include "config.h"

/*
    Variant Legend:
    C  0  -  0  0  0  -  0  0  0  -  0  0  0 - v  0 . 0 . 0
    0  1  2  3  4  5  6  7  8  9  10 11 12 13
    C(side)-(thumb modules)-(finger modules)-(additional modules) - v(version)
*/



void Config::set_variant() {      

    if (device_side == LEFT) {
        variant.setCharAt(1,'L');
    } else if (device_side == RIGHT) {
        variant.setCharAt(1,'R');
    }

    if (thumb_module == JUST_KEYS) {
        variant.setCharAt(3,'B');
    } else if (thumb_module == KEYS_AND_JOYSTICK) {
        variant.setCharAt(3,'J');
        variant.setCharAt(4,'B');
    } else if (thumb_module == TRACKBALL) {
        variant.setCharAt(3,'T');
    }

    if (finger_module == ONLY_KEYS) {
        variant.setCharAt(7,'B');     
    } else if (finger_module == KEYS_AND_WHEEL) {
        variant.setCharAt(7,'B');
        variant.setCharAt(8,'W');
    }

    if (additional_modules == NONE) {
        variant.setCharAt(11,'0');
    } else if (additional_modules == MOUSE_MODULE_ADNS_5050) {
        variant.setCharAt(11,'M');
    } else if (additional_modules == GYROSCOPE_MODULE_MPU_6050) {
        variant.setCharAt(11,'G');
    }
         
}

Config config;


