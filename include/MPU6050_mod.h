#ifndef MPU6050_MOD_H
#define MPU6050_MOD_H

#include <Arduino.h>

// Basic demo for accelerometer readings from Adafruit MPU6050
// ESP32 Guide: https://RandomNerdTutorials.com/esp32-mpu-6050-accelerometer-gyroscope-arduino/
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

#include "events_map.h"
#include "events.h"


extern Adafruit_MPU6050 mpu;


class MPU6050 {
public:
    void initialize();

    void read();
    void read_on_trigger();

    void readSensor();
    void read_accel();
    void read_gyro();
    // void readAccelerometer(int16_t* ax, int16_t* ay, int16_t* az);
    // void readGyroscope(int16_t* gx, int16_t* gy, int16_t* gz);
private:
    sensors_event_t accel, gyro, temp;
    
    int8_t accel_x, accel_y, accel_z;
    int8_t gyro_x, gyro_y, gyro_z;

    int8_t accel_x_prev, accel_y_prev, accel_z_prev;
    int8_t gyro_x_prev, gyro_y_prev, gyro_z_prev;


    uint8_t axis_val[2];
    uint8_t axis_val_prev[2];



    uint8_t gyro_event_map[2][2] = {{EVENT_GA_F, EVENT_GA_B}, 
                                    {EVENT_GA_R, EVENT_GA_L}};

    bool gyro_state[2][2] = {{false, false}, 
                            {false, false}};


    void trigger_event(uint8_t axis, uint8_t gyro_event);

    void actuate_event(uint8_t axis, uint8_t gyro_event);
    void deactuate_event(uint8_t axis, uint8_t gyro_event);

    void move_nouse();

};

extern MPU6050 mpu6050;

#endif
