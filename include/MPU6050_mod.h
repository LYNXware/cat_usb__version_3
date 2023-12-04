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
    bool trigger_state = false;

private:
    sensors_event_t accel, gyro, temp;

    int8_t axis_val[2];
    int8_t axis_val_prev[2];
    int8_t axis_val_relative[2];

    uint8_t treshold_absolute = 1;
    uint8_t treshold_relative = 2;

    uint8_t gyro_event_map[2][2] = {{EVENT_GA_F, EVENT_GA_B}, 
                                    {EVENT_GA_R, EVENT_GA_L}};

    bool gyro_state[2][2] = {{false, false}, 
                            {false, false}};


    void absolute_event_trigger();
    void absolute_event_trigger_with_mouse();
    void relative_event_trigger();
    void relative_event_trigger_with_mouse();

    void calc_relative_axis_val();

    void absolute();
    void relative();

    void actuate_event(uint8_t axis, uint8_t side);
    void deactuate_event(uint8_t axis, uint8_t side);

    void move_mouse(int8_t x, int8_t y);
};


extern MPU6050 mpu6050;
#endif

    

    
    // int8_t accel_x, accel_y, accel_z;
    // int8_t gyro_x, gyro_y, gyro_z;

    // int8_t accel_x_prev, accel_y_prev, accel_z_prev;
    // int8_t gyro_x_prev, gyro_y_prev, gyro_z_prev;
        // void trigger_event();
    // void trigger_event_with_mouse();

    // void trigger_event(uint8_t axis, uint8_t gyro_event);
    // void trigger_event_with_mouse(uint8_t axis, uint8_t gyro_event);
