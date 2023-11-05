#ifndef USB_COMMS_CAT_H
#define USB_COMMS_CAT_H

#include <Arduino.h>

#include "config.h"
#include "layouts_manager_cat.h"



class USB_Comms {

public:
    String incoming_raw_layouts = "empty";
    void get_layouts();

private:

    // String incoming_raw_layouts = "empty";
    String comms_message = "are_you_a_cat";

};


extern USB_Comms usb_comms;

#endif



