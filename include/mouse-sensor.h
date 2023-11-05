#ifndef MOUSE_SENSOR_H
#define MOUSE_SENSOR_H

#include <Arduino.h>

#include "events.h"
#include "layer_control.h"
#include "layouts_manager_cat.h"


// code is taken form this forum: https://forum.arduino.cc/t/adns5050/67599/9

class ADNS5050  {
    
    public:

        // initialize the pins for the mouse sensor
        void initialize();

        // read the mouse sensor
        void read();
                


    private:

        //pins conections
        #define SCLK                14
        #define SDIO                13
        #define NRESET              12
        #define NCS                 11

        //stuff for adsn5050
        #define PRODUCT_ID          0x00 // should be 0x12
        #define PRODUCTID2          0x3e
        #define REVISION_ID         0x01
        #define DELTA_Y_REG         0x03
        #define DELTA_X_REG         0x04
        #define SQUAL_REG           0x05
        #define MAXIMUM_PIXEL_REG   0x08
        #define MINIMUM_PIXEL_REG   0x0a
        #define PIXEL_SUM_REG       0x09
        #define PIXEL_DATA_REG      0x0b
        #define SHUTTER_UPPER_REG   0x06
        #define SHUTTER_LOWER_REG   0x07
        #define RESET               0x3a
        #define CPI500v             0x00
        #define CPI1000v            0x01

        #define NUM_PIXELS          361

        byte pix[360];

        int y_sensor;
        int x_sensor;

        int y_mouse;
        int x_mouse;


        int  convert(byte twoscomp);

        void sync();

        void ADNS_write(unsigned char addr, unsigned char data);

        byte ADNS_read(unsigned char addr);

        void pixelGrab();


};//class end

extern ADNS5050 adns5050;

#endif