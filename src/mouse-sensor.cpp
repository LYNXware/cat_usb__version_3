#include "mouse-sensor.h"

// code is taken form this forum: https://forum.arduino.cc/t/adns5050/67599/9


void ADNS5050::initialize() {

    pinMode(SDIO, OUTPUT);
    pinMode(SCLK, OUTPUT);
    pinMode(NCS, OUTPUT);

//  pinMode(RESET, OUTPUT);
//  digitalWrite(RESET, LOW);
    
    sync();
    
    ADNS_write(RESET, 0x5a);
    delay(50);                // From NRESET pull high to valid motion, assuming VDD and motion is present.

    pinMode(NRESET,OUTPUT);
    digitalWrite(NRESET,HIGH);
}



void ADNS5050::read()
{
    if (layouts_manager.events_bank[layer_control.active_layer][EVENT_M_NF] == "1")
    {
        y_sensor = convert(ADNS_read(DELTA_Y_REG));
        x_sensor = convert(ADNS_read(DELTA_X_REG));

        y_mouse = y_sensor * layouts_manager.mouse_factor[layer_control.active_layer][0] * (-1); // Y horizontal 
        x_mouse = x_sensor * layouts_manager.mouse_factor[layer_control.active_layer][1]; // X vertical

        Mouse.move(y_mouse, x_mouse);
    }
}


        
int  ADNS5050::convert(byte twoscomp)
{
    int value;

    twoscomp = twoscomp << 1;

    if (bitRead(twoscomp,7)){
        value = -128 + (twoscomp & B01111111 );
    }
    else{
        value = twoscomp;
    }
    return value;
}



void ADNS5050::sync() {
    digitalWrite(NCS, LOW);
    delayMicroseconds(2);
    digitalWrite(NCS, HIGH);
}
        
        
         
void ADNS5050::ADNS_write(unsigned char addr, unsigned char data) {
    char temp;
    int n;

    digitalWrite(NCS, LOW);//nADNSCS = 0; // select the chip

    temp = addr;
    digitalWrite(SCLK, LOW);//SCK = 0;          // start clock low
    pinMode(SDIO, OUTPUT);//DATA_OUT; // set data line for output
    for (n=0; n<8; n++) {
        digitalWrite(SCLK, LOW);//SCK = 0;
        pinMode(SDIO, OUTPUT);
        delayMicroseconds(1);
        if (temp & 0x80)
            digitalWrite(SDIO, HIGH);//SDOUT = 1;
        else
            digitalWrite(SDIO, LOW);//SDOUT = 0;
        temp = (temp << 1);
        digitalWrite(SCLK, HIGH);//SCK = 1;
        delayMicroseconds(1);//delayMicroseconds(1);      // short clock pulse
    }
    temp = data;
    for (n=0; n<8; n++) {
        digitalWrite(SCLK, LOW);//SCK = 0;
        delayMicroseconds(1);
        if (temp & 0x80)
            digitalWrite(SDIO, HIGH);//SDOUT = 1;
        else
            digitalWrite(SDIO, LOW);//SDOUT = 0;
        temp = (temp << 1);
        digitalWrite(SCLK, HIGH);//SCK = 1;
        delayMicroseconds(1);     // short clock pulse
    }
    delayMicroseconds(20);
    digitalWrite(NCS, HIGH);//nADNSCS = 1; // de-select the chip
}



        
byte ADNS5050::ADNS_read(unsigned char addr) {
    
    byte temp;
    int n;

    digitalWrite(NCS, LOW);//nADNSCS = 0;       // select the chip
    temp = addr;
    digitalWrite(SCLK, OUTPUT); //SCK = 0;          // start clock low
    pinMode(SDIO, OUTPUT); //DATA_OUT;          // set data line for output
    
    for (n=0; n<8; n++) {

        digitalWrite(SCLK, LOW);//SCK = 0;
        pinMode(SDIO, OUTPUT); //DATA_OUT;
        if (temp & 0x80) {
            digitalWrite(SDIO, HIGH);//SDOUT = 1;
        } 

        else {
            digitalWrite(SDIO, LOW);//SDOUT = 0;
        }

        temp = (temp << 1);
        delayMicroseconds(1);
        digitalWrite(SCLK, HIGH); //SCK = 1;
        delayMicroseconds(1);     // short clock pulse
    }

    temp = 0; // This is a read, switch to input
    pinMode(SDIO, INPUT); //DATA_IN;
    for (n=0; n<8; n++) {   // read back the data
        digitalWrite(SCLK, LOW);
        if(digitalRead(SDIO)) {// got a '1'
            temp |= 0x1;
        }
        if( n != 7) temp = (temp << 1); // shift left
        digitalWrite(SCLK, HIGH);
    }

    digitalWrite(NCS, HIGH);// de-select the chip
    return temp;
}


void ADNS5050::pixelGrab(){
    int grabCount = 0; 
    while( grabCount < NUM_PIXELS )
    {
        pix[grabCount] = ADNS_read(PIXEL_DATA_REG);
        grabCount++;
    }
}

ADNS5050 adns5050;

