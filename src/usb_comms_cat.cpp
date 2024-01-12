#include "usb_comms_cat.h"

USB_Comms usb_comms;


void USB_Comms::get_layouts()
{
    if (Serial.available())
    {
        incoming_raw_layouts = Serial.readString();
        delay(10); // wait for the serial buffer to fill up (weird bug)

        if (incoming_raw_layouts == comms_message)
        {
            // sent the variant to LYNXapp
            Serial.println(config.variant);

            while (Serial.available())
            {
                delay(10);
            }
        }
        else
        {
            layouts_manager.split_events_package(incoming_raw_layouts);
            layouts_manager.save_events_package(incoming_raw_layouts);
        }
        incoming_raw_layouts = "";
    }
}  


