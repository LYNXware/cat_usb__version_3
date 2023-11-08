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

    // String layouts_package = "***";

    String events_bank[4][EVENTS_COUNT];
    
    float mouse_factor[4][2];


    void split_events_package(String events_package);

    void save_events_package(String events_package);

    void load_events_package();


private:

    byte layer;
    byte event_index;
    int front_of_events;
    int package_length;

    String loaded_events_package = "loaded_events_package";

    void adjust_mouse_speed();

};


extern Layouts_Manager layouts_manager;

#endif