/*
Version: 0.2.0
Date: 01.09.2023
Developer: Stanislaw Kirpicnikow (Ape Devil)
Remark: 
*/

// dev




#include <Arduino.h>

// module to define the cat variant
#include "config.h"

// module to control the Neopixel LEDs
#include "neopixel-LED.h"

// module to control the ESP-NOW communication
#include "cat-now.h"

// module to control the layers
#include "layer_control.h"

// module to manage the layouts
#include "layouts_manager.h"

// module to check the finger events
#include "finger_module.h"

// module to check the thumb events
#include "thumb_module.h"

// module to control the scroll wheel
#include "scroll-wheel.h"

// module to control the mouse sensor
#include "mouse-sensor.h"

// module to control the joystick
#include "joystick.h"

// module for the execution of the events
#include "events.h"

#include "MPU6050_mod.h"






//test button
#define pI 46
int bRead;





void setup() {


  //test buton
  pinMode(pI, INPUT_PULLUP);



  // Activation of required libraries
  Serial.begin(115200);
  Keyboard.begin();
  Mouse.begin();
  

  // setting up the cat variant for the communication with the LYNXapp
  config.set_variant();

  neopixelled.initialize();

  catnow.initialize();

  // set the layer to major-main and initialize the LEDs
  layer_control.initialize();

  // loading the layouts
  layouts_manager.load_layouts();



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

}



void loop() {

  // Serial.println(config.variant);
  bRead = digitalRead(pI);
  if (bRead == 0) {

    // catnow.test();
    catnow.scan_for_slave();
    catnow.send_switch_layer(66);
  }




  // checking if the LYNXapp is connected and sends new layouts
  layouts_manager.get_layouts(config.variant);
  

  // checking if key of thumb and fingers are triggered
  fingerModule.read_keystate();
  thumbModule.read_keystate();

  if (config.finger_module == KEYS_AND_WHEEL) {
    scroll_wheel.read_encoder();
  }
  if (config.thumb_module == KEYS_AND_JOYSTICK) {
    joystick.read_joystick();
  }
    
//   // included according to config.h 
// #if finger_module == 1
//   // check if the scroll wheel is triggered
//   scroll_wheel.read_encoder();
// #endif  

// #if thumb_module == 1  
//   // check if the joystick is triggered
//   joystick.read_joystick();
// #endif
  
// #if additional_modules == 1  
//   // checking if the mouse sensor is triggered
//   adns5050.read_mouse_sensor();
// #endif

  if (config.additional_modules == MOUSE_MODULE_ADNS_5050) {
    adns5050.read_mouse_sensor();
  } 
  else if (config.additional_modules == GYROSCOPE_MODULE_MPU_6050) {
    mpu6050.readSensor();
  }

}//end loop
