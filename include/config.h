#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>    

#include "events.h"
#include "finger_module.h"


enum DeviceSide { 
    LEFT = 0,
    RIGHT = 1
};

enum ThumbModule {
    JUST_KEYS = 0,
    KEYS_AND_JOYSTICK = 1,
    TRACKBALL = 2
};

enum FingerModule {
    ONLY_KEYS = 0,
    KEYS_AND_WHEEL = 1
};

enum AdditionalModules {
    NONE = 0,
    MOUSE_MODULE_ADNS_5050 = 1,
    GYROSCOPE_MODULE_MPU_6050 = 2
};



class Config {

public:

    /* CONFIG - here you can define your cat variant */ 

    // enum DeviceSide device_side = LEFT;
    enum DeviceSide device_side = RIGHT;

    enum ThumbModule thumb_module = JUST_KEYS;
    // enum ThumbModule thumb_module = KEYS_AND_JOYSTICK;
    // enum ThumbModule thumb_module = TRACKBALL;

    enum FingerModule finger_module = ONLY_KEYS;
    // enum FingerModule finger_module = KEYS_AND_WHEEL;

    enum AdditionalModules additional_modules = NONE;
    // enum AdditionalModules additional_modules = MOUSE_MODULE_ADNS_5050;
    // enum AdditionalModules additional_modules = GYROSCOPE_MODULE_MPU_6050;



    //the variant variable is used to communicate with the LYNXapp
    String variant = "C0-000-000-000_v0.3.0";

    // the setup function is used to set the variant variable
    void set_variant();

    void print_kayboard_scan_codes(); 
};


extern Config config;
#endif




// #define CAT_SIDE_LEFT
// // #define CAT_SIDE_RIGHT

// // #ifdef CAT_SIDE_LEFT
// //     // String TTT = "left"; 
// // #endif  

// // #ifdef CAT_SIDE_RIGHT
// //     #define SIDE "left"; 
// // #endif  

// #ifdef CAT_SIDE_LEFT
//     #define SIDE "left";
// #elif defined(CAT_SIDE_RIGHT)
//     #define SIDE "right";
// #endif  