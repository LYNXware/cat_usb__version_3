#include "MPU6050_mod.h"


Adafruit_MPU6050 mpu;

MPU6050 mpu6050;


void MPU6050::initialize()
{
    mpu.begin();
    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
    mpu.setGyroRange(MPU6050_RANGE_500_DEG);
    mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);
}



void MPU6050::read()
{  
    mpu.getEvent(&accel, &gyro, &temp);

    axis_val[0] = accel.acceleration.y;
    axis_val[1] = accel.acceleration.x;

    // Serial.print("nf:");
    // Serial.print(layouts_manager.events_bank[layer_control.active_layer][EVENT_GA_NF]);

    // Serial.print("  m:");
    // Serial.print(layouts_manager.events_bank[layer_control.active_layer][EVENT_GA_M]);

    // Serial.print("  ar:");
    // Serial.print(layouts_manager.events_bank[layer_control.active_layer][EVENT_GA_AR]);

    // Serial.print("   ");

    if (layouts_manager.events_bank[layer_control.active_layer][EVENT_GA_M] == "1")
    {   
        if (layouts_manager.events_bank[layer_control.active_layer][EVENT_GA_AR] == "0")
        {
            absolute_event_trigger_with_mouse();
        }
        else
        {
            relative_event_trigger_with_mouse();
        }
        // trigger_event_with_mouse();
        // Serial.println("trigger_event_with_mouse");
    }
    else
    {
        if (layouts_manager.events_bank[layer_control.active_layer][EVENT_GA_AR] == "0")
        {
            absolute_event_trigger();
        }
        else
        {
            relative_event_trigger();
        }
        // trigger_event();
        // Serial.println("trigger_event");
    }
}





void MPU6050::absolute_event_trigger()
{ 
    // Serial.println("absolute_event_trigger");
    absolute();
}


void MPU6050::absolute_event_trigger_with_mouse()
{
    // Serial.println("absolute_event_trigger_with_mouse");
    absolute();
    move_mouse(axis_val[1], axis_val[0]);
}


void MPU6050::relative_event_trigger()
{
    // Serial.println("relative_event_trigger");
    calc_relative_axis_val();
    relative();
}


void MPU6050::relative_event_trigger_with_mouse()
{   
    // Serial.println("relative_event_trigger_with_mouse");
    calc_relative_axis_val();
    relative();
    move_mouse(axis_val_relative[1], axis_val_relative[0]);
}


void MPU6050::calc_relative_axis_val()
{
    for (uint8_t i = 0; i < 2; i++)
    {
        axis_val_relative[i] = axis_val[i] - axis_val_prev[i];
        axis_val_prev[i] = axis_val[i];
    }
}


void MPU6050::absolute()
{
    for (uint8_t i = 0; i < 2; i++)
    {   
        if (axis_val[i] > treshold_absolute)
        {
            actuate_event(i,1);
            // Serial.println(axis_val[i]);
        }
        else
        {
            deactuate_event(i,1);
        }
        
        if (axis_val[i] < -treshold_absolute)
        {
            actuate_event(i,0);
            // Serial.println(axis_val[i]);
        }
        else
        {
            deactuate_event(i,0);
        }
    }
}


void MPU6050::relative()
{
    for (uint8_t i = 0; i < 2; i++)
    {
        // if (axis_val[i] > axis_val_prev[i] )
        if (axis_val_relative[i] > 0)
        {
            actuate_event(i,1);
            // Serial.print(axis_val[i]);
            // Serial.print("  ");
            // Serial.println(axis_val_prev[i]);
        }
        // else if (axis_val[i] < axis_val_prev[i])
        else if (axis_val_relative[i] < 0)
        {
            actuate_event(i,0);
            // Serial.print(axis_val[i]);
            // Serial.print("  ");
            // Serial.println(axis_val_prev[i]);
        }
        else
        {
            deactuate_event(i,0);
            deactuate_event(i,1);
        }
    }
    // axis_val_prev[0] = axis_val[0];
    // axis_val_prev[1] = axis_val[1];
}



void MPU6050::actuate_event(byte axis, byte side){

  if (!gyro_state[axis][side]) 
  {
    event.actuate(gyro_event_map[axis][side]);
    gyro_state[axis][side] = true;

    // Serial.print("press--");
    // Serial.print(axis);
    // Serial.print("-");
    // Serial.println(axis_event);

  }
}



void MPU6050::deactuate_event(byte axis, byte side){

  if (gyro_state[axis][side]) 
  {
    event.deactuate(gyro_event_map[axis][side]);
    gyro_state[axis][side] = false;
    // Serial.print("rr--");
    // Serial.print(axis);
    // Serial.print("-");
    // Serial.println(axis_event);
  }
}


void MPU6050::move_mouse(int8_t x, int8_t y)
{
    Serial.print("x1: ");
    Serial.print(x);
    Serial.print("  y1: ");
    Serial.print(y);

    y = y * layouts_manager.gyro_mouse_speed[layer_control.active_layer] * layouts_manager.gyro_mouse_y_direction[layer_control.active_layer];
    x = x * layouts_manager.gyro_mouse_speed[layer_control.active_layer] * layouts_manager.gyro_mouse_x_direction[layer_control.active_layer];

    Mouse.move(x, y);

    Serial.print("  x2: ");
    Serial.print(x);
    Serial.print("  y2: ");
    Serial.print(y);

    

    Serial.print("  xf: ");
    Serial.print(layouts_manager.gyro_mouse_x_direction[layer_control.active_layer]);
    Serial.print("  yf: ");
    Serial.print(layouts_manager.gyro_mouse_y_direction[layer_control.active_layer]);
    Serial.print("  s: ");
    Serial.print(layouts_manager.gyro_mouse_speed[layer_control.active_layer]);

    Serial.println();
    delay(100);
}




// void MPU6050::trigger_event_with_mouse(){

//     for (uint8_t i = 0; i < 2; i++)
//     {
//         if (axis_val[i] > 0)
//         {
//             gyro_state[i][1] = true;
//             event.actuate(gyro_event_map[i][1]);
//         }
//         else if (axis_val[i] < 0)
//         {
//             gyro_state[i][0] = true;
//             event.actuate(gyro_event_map[i][0]);
//         }
//         else
//         {
//             gyro_state[i][0] = false;
//             gyro_state[i][1] = false;
//             event.deactuate(gyro_event_map[i][0]);
//             event.deactuate(gyro_event_map[i][1]);
//         }
//     }
//     Mouse.move(axis_val[1]*-1,  axis_val[0]*-1);
// }














// void MPU6050::trigger_event(){
//     // accel_x = accel.acceleration.x;
//     // accel_y = accel.acceleration.y;
//     // accel_z = accel.acceleration.z;

//     // axis_val[0] = accel.acceleration.y;
//     // axis_val[1] = accel.acceleration.x;

//     for (uint8_t i = 0; i < 2; i++){
//         if (axis_val[i] > axis_val_prev[i]){
//             // trigger_event(i,1);
//         }
//         else if (axis_val[i] < axis_val_prev[i]){
//             // trigger_event(i,0);
//         }
//     }

//     axis_val_prev[0] = axis_val[0];
//     axis_val_prev[1] = axis_val[1];
// }







// // if (layouts_manager.events_bank[layer_control.active_layer][EVENT_GA_M] == "1")



// void MPU6050::trigger_event_with_mouse(uint8_t axis, uint8_t gyro_event)
// {
//     Mouse.move(accel_x*-2, accel_y*-2);
//     // Mouse.move(y_mouse, x_mouse);
// }




    // if (accel_y != accel_y_prev){
    //     if (accel_y > 0){ // forward
    //         trigger_event(0,1);
    //         // trigger_event(EVENT_GA_B);
    //     }
    //     else{ // backward
    //         trigger_event(0,0);
    //         // trigger_event(EVENT_GA_F);
    //     }
    // }


    // if (accel_x != accel_x_prev){
    //     if (accel_x > 0){ // left
    //         trigger_event(1,1);
    //         // trigger_event(EVENT_GA_L);
    //     }
    //     else{ // right
    //         trigger_event(1,0);
    //         // trigger_event(EVENT_GA_R);66
    //     }
    // }


    // if (accel_y != accel_y_prev){
    //     if (accel_y > 0){ // forward
    //         trigger_event(0,1);
    //         // trigger_event(EVENT_GA_B);
    //     }
    //     else{ // backward
    //         trigger_event(0,0);
    //         // trigger_event(EVENT_GA_F);
    //     }
    // }

    // if (accel_y == 0){
    //     gyro_state[0][0] = false;
    //     gyro_state[0][1] = false;
    // }

    // if (accel_x != accel_x_prev){
    //     if (accel_x > 0){ // left
    //         trigger_event(1,1);
    //         // trigger_event(EVENT_GA_L);
    //     }
    //     else{ // right
    //         trigger_event(1,0);
    //         // trigger_event(EVENT_GA_R);66
    //     }
    // }

    // if (accel_x == 0){
    //     gyro_state[1][0] = false;
    //     gyro_state[1][1] = false;
    // }

    // if (accel_z != accel_z_prev){
    //     Serial.print("Accel Z: ");
    //     Serial.println(accel_z);
    // }
//     accel_x_prev = accel_x;
//     accel_y_prev = accel_y;
//     accel_z_prev = accel_z;
// }










// void MPU6050::read_gyro(){
//     // /* Get new sensor events with the readings */
//     // sensors_event_t gyro;
//     // mpu.getEvent(NULL, &gyro, NULL);

//     gyro_x = gyro.gyro.x;
//     gyro_y = gyro.gyro.y;   
//     gyro_z = gyro.gyro.z;

//     if (gyro_x != gyro_x_prev){
//         Serial.print("Gyro X: ");
//         Serial.println(gyro_x);
//     }
//     // if (gyro_y != gyro_y_prev){
//     //     Serial.print("Gyro Y: ");
//     //     Serial.println(gyro_y);
//     // }
//     // if (gyro_z != gyro_z_prev){
//     //     Serial.print("Gyro Z: ");
//     //     Serial.println(gyro_z);
//     // }

//     gyro_x_prev = gyro_x;
//     gyro_y_prev = gyro_y;
//     gyro_z_prev = gyro_z;
// }




// void MPU6050::readSensor(){
//     /* Get new sensor events with the readings */
//     // sensors_event_t accel, gyro, temp;
//     mpu.getEvent(&accel, &gyro, &temp);

//     accel_x = accel.acceleration.x;
//     accel_y = accel.acceleration.y;
//     accel_z = accel.acceleration.z;

//     gyro_x = gyro.gyro.x;
//     gyro_y = gyro.gyro.y;   
//     gyro_z = gyro.gyro.z;
    
//     Serial.print("Accel X: ");
//     Serial.print(accel_x);
//     Serial.print("  Y: ");
//     Serial.print(accel_y);
//     Serial.print("  Z: ");
//     Serial.print(accel_z);
//     Serial.print("  Gyro X: ");
//     Serial.print(gyro_x);
//     Serial.print("  Y: ");
//     Serial.print(gyro_y);
//     Serial.print("  Z: ");
//     Serial.println(gyro_z);
//     delay(100);

// }



// // MPU6050::MPU6050() {
// void MPU6050::initialize(){

//     // Serial.begin(115200);
//     while (!Serial)
//     delay(10); // will pause Zero, Leonardo, etc until serial console opens

//     Serial.println("Adafruit MPU6050 test!");

//     // Try to initialize!
//     if (!mpu.begin()) {
//     Serial.println("Failed to find MPU6050 chip");
//     while (1) {
//         delay(10);
//     }
//     }
//     Serial.println("MPU6050 Found!");

//     mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
//     Serial.print("Accelerometer range set to: ");
//     switch (mpu.getAccelerometerRange()) {
//     case MPU6050_RANGE_2_G:
//     Serial.println("+-2G");
//     break;
//     case MPU6050_RANGE_4_G:
//     Serial.println("+-4G");
//     break;
//     case MPU6050_RANGE_8_G:
//     Serial.println("+-8G");
//     break;
//     case MPU6050_RANGE_16_G:
//     Serial.println("+-16G");
//     break;
//     }
//     mpu.setGyroRange(MPU6050_RANGE_500_DEG);
//     Serial.print("Gyro range set to: ");
//     switch (mpu.getGyroRange()) {
//     case MPU6050_RANGE_250_DEG:
//     Serial.println("+- 250 deg/s");
//     break;
//     case MPU6050_RANGE_500_DEG:
//     Serial.println("+- 500 deg/s");
//     break;
//     case MPU6050_RANGE_1000_DEG:
//     Serial.println("+- 1000 deg/s");
//     break;
//     case MPU6050_RANGE_2000_DEG:
//     Serial.println("+- 2000 deg/s");
//     break;
//     }

//     mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);
//     Serial.print("Filter bandwidth set to: ");
//     switch (mpu.getFilterBandwidth()) {
//     case MPU6050_BAND_260_HZ:
//     Serial.println("260 Hz");
//     break;
//     case MPU6050_BAND_184_HZ:
//     Serial.println("184 Hz");
//     break;
//     case MPU6050_BAND_94_HZ:
//     Serial.println("94 Hz");
//     break;
//     case MPU6050_BAND_44_HZ:
//     Serial.println("44 Hz");
//     break;
//     case MPU6050_BAND_21_HZ:
//     Serial.println("21 Hz");
//     break;
//     case MPU6050_BAND_10_HZ:
//     Serial.println("10 Hz");
//     break;
//     case MPU6050_BAND_5_HZ:
//     Serial.println("5 Hz");
//     break;
//     }

//     Serial.println("");
//     delay(100);
// }


// void MPU6050::readSensor(){
//   /* Get new sensor events with the readings */
//   sensors_event_t a, g, temp;
//   mpu.getEvent(&a, &g, &temp);

//   /* Print out the values */
//   Serial.print("Acceleration X: ");
//   Serial.print(a.acceleration.x);
//   Serial.print(", Y: ");
//   Serial.print(a.acceleration.y);
//   Serial.print(", Z: ");
//   Serial.print(a.acceleration.z);
//   Serial.println(" m/s^2");

//   Serial.print("Rotation X: ");
//   Serial.print(g.gyro.x);
//   Serial.print(", Y: ");
//   Serial.print(g.gyro.y);
//   Serial.print(", Z: ");
//   Serial.print(g.gyro.z);
//   Serial.println(" rad/s");

//   Serial.print("Temperature: ");
//   Serial.print(temp.temperature);
//   Serial.println(" degC");

//   Serial.println("");
//   delay(500);
// }