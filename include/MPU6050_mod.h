#ifndef MPU6050_MOD_H
#define MPU6050_MOD_H

#include <Arduino.h>

// Basic demo for accelerometer readings from Adafruit MPU6050
// ESP32 Guide: https://RandomNerdTutorials.com/esp32-mpu-6050-accelerometer-gyroscope-arduino/
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>


extern Adafruit_MPU6050 mpu;


class MPU6050 {
public:
    // MPU6050();
    void initialize();
    void readSensor();
    void read_accel();
    void read_gyro();
    // void readAccelerometer(int16_t* ax, int16_t* ay, int16_t* az);
    // void readGyroscope(int16_t* gx, int16_t* gy, int16_t* gz);
private:
    sensors_event_t accel, gyro, temp;
    
    int accel_x, accel_y, accel_z;
    int gyro_x, gyro_y, gyro_z;

    int accel_x_prev, accel_y_prev, accel_z_prev;
    int gyro_x_prev, gyro_y_prev, gyro_z_prev;

};

extern MPU6050 mpu6050;

#endif
