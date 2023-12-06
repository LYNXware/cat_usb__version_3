#ifndef LAYOUTS_MANAGER_CAT_H
#define LAYOUTS_MANAGER_CAT_H

#include <Arduino.h>

#include "config.h"
#include "constants.h"
#include "events_map.h"

#include <Preferences.h>
extern Preferences preferences;



class Layouts_Manager {

public:

    String events_bank[4][EVENTS_COUNT];
    
    // mouse_factor[layer][mouse_horizontal / mouse_vertical / wheel_speed]
    float mouse_factor[4][2];

    uint8_t wheel_speed[4];

    uint8_t gyro_dead_zone[4];
    uint8_t gyro_mouse_speed[4];
    int8_t gyro_mouse_x_direction[4];
    int8_t gyro_mouse_y_direction[4];


    void split_events_package(String events_package);

    void save_events_package(String events_package);

    void load_events_package();


private:

    byte layer;
    byte event_index;
    int front_of_events;
    int package_length;

    String loaded_events_package = "loaded_events_package";

    void convert_to_numbers();

};


extern Layouts_Manager layouts_manager;
#endif