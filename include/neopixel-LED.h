#ifndef NEOPIXEL_LED_H
#define NEOPIXEL_LED_H

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#include "PINs.h"


#define LED_COUNT 2

// creating an instance of the Adafruit_NeoPixel class
extern Adafruit_NeoPixel strip_layer_switch;



class NeopixelLED {

public:

    void initialize();
    void layer_witch(byte active_layer);
};


extern NeopixelLED neopixelled;
#endif