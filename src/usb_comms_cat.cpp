#include "usb_comms_cat.h"


void USB_Comms::get_layouts() {

    if (Serial.available() > 0){

        incoming_raw_layouts = Serial.readString();

        if (comms_message == incoming_raw_layouts){
            Serial.println(config.variant);
        }
        else{

            layouts_manager.split_events_package(incoming_raw_layouts);
            layouts_manager.save_events_package(incoming_raw_layouts);

            // Serial.print("usb: ");
            // Serial.println(incoming_raw_layouts);

        }
        // incoming_raw_layouts = "empty";
        // Serial.println(incoming_raw_layouts);
    }
}  



// // Preferences preferences;
USB_Comms usb_comms;