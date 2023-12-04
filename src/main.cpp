/*
Version: 0.3.0
Date: 01.12.2023
Developer: Stanislaw Kirpicnikow (Ape Devil)
Remark: 
*/


#include <Arduino.h>


// module to define the cat variant
#include "config.h"

// module to control the Neopixel LEDs
#include "neopixel-LED.h"

// module to control the ESP-NOW communication
#include "cat-now.h"

// module to control the layers
#include "layer_control.h"

// communication module with the LYNXapp
#include "usb_comms_cat.h"

// module to manage the layouts
#include "layouts_manager_cat.h"

// module to check the finger events
#include "finger_module.h"

// module to check the thumb events
#include "thumb_module.h"

// module to control the scroll wheel
#include "scroll-wheel.h"

// module to control the mouse sensor
#include "mouse-sensor.h"

// module to control the gyroscope
#include "MPU6050_mod.h"

// module to control the joystick
#include "joystick.h"

// module for the execution of the events
#include "events.h"




//test button
// #define pI 46
// int bRead;


void setup()
{
    //test buton
    // pinMode(pI, INPUT_PULLUP);


    // Activation of required libraries
    Serial.begin(115200);
    Keyboard.begin();
    Mouse.begin();

      // initialize the modules
    fingerModule.initialize();
    thumbModule.initialize();

    // included according to config.h
    if (config.finger_module == KEYS_AND_WHEEL) {
      scroll_wheel.initialize();
    }

    if (config.thumb_module == KEYS_AND_JOYSTICK) {
      joystick.initialize();
    }

    if (config.additional_modules == MOUSE_MODULE_ADNS_5050) {
      adns5050.initialize();
    } 
    else if (config.additional_modules == GYROSCOPE_MODULE_MPU_6050) {
      mpu6050.initialize();
    }

    neopixelled.initialize();
    catnow.initialize();
    layer_control.initialize();

    // loading the layouts package
    layouts_manager.load_events_package();

    // setting up the cat variant for the communication with the LYNXapp
    config.set_variant();
    config.print_kayboard_scan_codes();
}





void loop()
{
  // bRead = digitalRead(pI);
  // if (bRead == 0) {
  //   Serial.println("button pressed");
  // }


  // checking if the LYNXapp is sending new layouts
  usb_comms.get_layouts();


  // checking if any event is triggered
  fingerModule.read_keystate();
  thumbModule.read_keystate();


  if (config.finger_module == KEYS_AND_WHEEL) {
    scroll_wheel.read_encoder();
  }
  if (config.thumb_module == KEYS_AND_JOYSTICK) {
    joystick.read_joystick();
  }



  if (config.additional_modules == MOUSE_MODULE_ADNS_5050)
  {
    adns5050.read();
  } 
  else if (config.additional_modules == GYROSCOPE_MODULE_MPU_6050)
  {
    mpu6050.read();
  }
}
