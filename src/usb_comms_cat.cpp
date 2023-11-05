#include "usb_comms_cat.h"


void USB_Comms::get_layouts() {

    if (Serial.available()){

        incoming_raw_layouts = Serial.readString();

        if (incoming_raw_layouts == comms_message){
            Serial.println(config.variant);
            incoming_raw_layouts = "0";
        }
        else{

            layouts_manager.split_events_package(incoming_raw_layouts);
            layouts_manager.save_events_package(incoming_raw_layouts);
            // incoming_raw_layouts = "1";
        }
    }
}  



// // Preferences preferences;
USB_Comms usb_comms;