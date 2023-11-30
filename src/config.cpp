#include "config.h"


Config config;


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
        variant.setCharAt(3,'K');
    } else if (thumb_module == KEYS_AND_JOYSTICK) {
        variant.setCharAt(3,'K');
        variant.setCharAt(4,'J');
    } else if (thumb_module == TRACKBALL) {
        variant.setCharAt(3,'T');
    }

    if (finger_module == ONLY_KEYS) {
        variant.setCharAt(7,'K');     
    } else if (finger_module == KEYS_AND_WHEEL) {
        variant.setCharAt(7,'K');
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


void Config::print_kayboard_scan_codes()    
{
    if (fingerModule.trigger_print_scan_codes() == true) {

        for (int i = 0; i <= 190; i++) {
            Keyboard.write('0' + (i / 1000 % 10)); // Write thousands place
            Keyboard.write('0' + (i / 100 % 10)); // Write hundreds place
            Keyboard.write('0' + (i / 10 % 10));  // Write tens place
            Keyboard.write('0' + (i % 10));       // Write ones place
            Keyboard.write('\t'); // Tab for separation
            Keyboard.write(i);    // Write the corresponding character
            Keyboard.write('\n'); // Newline for separation
            delay(50); // Delay between each character (adjust as needed)
        }   
    }
}


