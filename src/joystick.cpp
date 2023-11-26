#include "joystick.h"

// creating an instance of the Joystick class
Joystick joystick;



void Joystick::initialize(){

    // pin to read the joystick values
    pinMode(PIN_THUMB_MOD_JOYSTICK_X, INPUT_PULLUP);     
    pinMode(PIN_THUMB_MOD_JOYSTICK_Y, INPUT_PULLUP);  
    
    // power supply for the joystick
    pinMode(PIN_THUMB_MOD_JOYSTICK_V,OUTPUT);
    digitalWrite(PIN_THUMB_MOD_JOYSTICK_V,HIGH); 
} 

  


void Joystick::read_joystick(){

    // read the analog joystick values
    joystickValues[0] = analogRead(PIN_THUMB_MOD_JOYSTICK_Y); 
    joystickValues[1] = analogRead(PIN_THUMB_MOD_JOYSTICK_X);

    // check how many steps the joystick has
    if (layouts_manager.events_bank[layer_control.active_layer][32][0] == '0'){
        one_step();
    }
    else{
        two_step();
    }
}



void Joystick::one_step() {

  for (byte a = 0; a < 2; a++) {

    if (joystickValues[a] < threshold_l1) {
      // Serial.println(joystickValues[a]);
      actuate_event(a,0);
    }
    else{
      deactuate_event(a,0);
    }

    if (joystickValues[a] > threshold_h1) {
      // Serial.println(joystickValues[a]);
      actuate_event(a,2);
    }
    else{
      deactuate_event(a,2);
    }
  }
}



void Joystick::two_step() {

  for (byte a = 0; a < 2; a++) {

    if (threshold_l1 > joystickValues[a] && joystickValues[a] > threshold_l2) {
      // Serial.println(joystickValues[a]);
      actuate_event(a,0);
    }
    else{
      deactuate_event(a,0);
    }

    if (joystickValues[a] < threshold_l2) {
      // Serial.println(joystickValues[a]);
      actuate_event(a,1);
    }
    else{
      deactuate_event(a,1);
    }

    if (threshold_h1 < joystickValues[a] && joystickValues[a] < threshold_h2) {
      // Serial.println(joystickValues[a]);
      actuate_event(a,2);
    }
    else{
      deactuate_event(a,2);
    }

    if (joystickValues[a] > threshold_h2) {
      // Serial.println(joystickValues[a]);
      actuate_event(a,3);
    }
    else{
      deactuate_event(a,3);
    }
  }
}




void Joystick::actuate_event(byte axis, byte axis_event){

  if (!joystick_state[axis][axis_event]) {

    joystick_state[axis][axis_event] = true;

    event.actuate(joystick_event_map[axis][axis_event]);

    // Serial.print("press--");
    // Serial.print(axis);
    // Serial.print("-");
    // Serial.println(axis_event);

  }
}



void Joystick::deactuate_event(byte axis, byte axis_event){

  if (joystick_state[axis][axis_event]) {

    joystick_state[axis][axis_event] = false;

    event.deactuate(joystick_event_map[axis][axis_event]);

    // Serial.print("rr--");
    // Serial.print(axis);
    // Serial.print("-");
    // Serial.println(axis_event);
  }
}



