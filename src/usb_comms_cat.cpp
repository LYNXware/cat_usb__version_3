#include "usb_comms_cat.h"

USB_Comms usb_comms;


void USB_Comms::get_layouts()
{
    if (Serial.available())
    {
        incoming_raw_layouts = Serial.readString();

        if (incoming_raw_layouts == comms_message)
        {
            // sent the variant to LYNXapp
            Serial.println(config.variant);

            while (Serial.available())
            {
                delay(10);
            }
            incoming_raw_layouts = "";
        }
        else
        {
            layouts_manager.split_events_package(incoming_raw_layouts);
            layouts_manager.save_events_package(incoming_raw_layouts);
        }
        incoming_raw_layouts = "";
    }
}  


