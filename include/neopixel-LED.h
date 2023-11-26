#ifndef NEOPIXEL_LED_H
#define NEOPIXEL_LED_H

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#include "PINs.h"

#define LED_COUNT 2
// #define LED_PIN    44
// #define LED_power 43

// creating an instance of the Adafruit_NeoPixel class
extern Adafruit_NeoPixel strip_layer_switch;


class NeopixelLED {

    public:

        // initialization of led strip
        void initialize();

        // function to change led colors to show selected layer
        void layer_witch(byte active_layer);
};

// creating an instance of the NeopixelLED class
extern NeopixelLED neopixelled;

#endif