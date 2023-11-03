#include "neopixel-LED.h"

// creating led strip object
Adafruit_NeoPixel strip_layer_switch(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// creating an instance of the NeopixelLED class
NeopixelLED neopixelled;



void NeopixelLED::initialize(){

    // power suply for the led strip
    pinMode(LED_power,OUTPUT);    
    digitalWrite(LED_power,HIGH);

    // initializing the led strip
    strip_layer_switch.begin();
    strip_layer_switch.show(); 

}



void NeopixelLED::layer_witch(byte active_layer){

    switch (active_layer){

        case 0:
            strip_layer_switch.setPixelColor(0, 0, 0, 50); //blue
            strip_layer_switch.setPixelColor(1, 0, 0, 0);
            strip_layer_switch.show();
            break;
            
        case 1:
            strip_layer_switch.setPixelColor(0, 50, 0, 0); // red
            strip_layer_switch.setPixelColor(1, 0, 0, 0);
            strip_layer_switch.show();
            break;

        case 2:
            strip_layer_switch.setPixelColor(1, 0, 50, 0); //green
            strip_layer_switch.setPixelColor(0, 0, 0, 0);
            strip_layer_switch.show();
            break;
            
        case 3:
            strip_layer_switch.setPixelColor(1, 50, 0, 0); //yealow
            strip_layer_switch.setPixelColor(0, 0, 0, 0);
            strip_layer_switch.show();
            break;            
    }
}







