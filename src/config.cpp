#include "config.h"

/*
    Variant Legend:
    C  0  -  0  0  0  -  0  0  0  -  0  0  0 - v  0 . 0 . 0
    0  1  2  3  4  5  6  7  8  9  10 11 12 13
    C(side)-(thumb modules)-(finger modules)-(additional modules) - v(version)
*/


void Config::set_variant() {      

    #if side == 0
        variant.setCharAt(1,'L');
    #elif side == 1
        variant.setCharAt(1,'R');
    #endif


    #if thumb_module == 0
        variant.setCharAt(3,'B');
    #elif thumb_module == 1
        variant.setCharAt(3,'J');
        variant.setCharAt(4,'B');
    #elif thumb_module == 2
        variant.setCharAt(3,'T');
    #endif


    #if finger_module == 0
        variant.setCharAt(7,'B');     
    #elif finger_module == 1
        variant.setCharAt(7,'B');
        variant.setCharAt(8,'W');
    #endif

    
    #if additional_modules == 0
           variant.setCharAt(11,'0');
    #elif additional_modules == 1
        variant.setCharAt(11,'M');
    #endif    
        
}

Config config;
