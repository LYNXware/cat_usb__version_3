#ifndef LAYOUTS_MANAGER_CAT_H
#define LAYOUTS_MANAGER_CAT_H

#include <Arduino.h>

#include "config.h"
#include "constants.h"

#include <Preferences.h>
extern Preferences preferences;



class Layouts_Manager {

    public:


        String layouts_package = "empty";

        String events_bank[4][53];



        void split_events_package(String events_package);

        void save_events_package(String events_package);

        void load_events_package();


        float mouse_factor[4][2];




    private:

        byte layer;
        byte event_index;
        int front_of_events;

        String loaded_events_package = "loaded_events_package";

        void adjust_mouse_speed();

};


extern Layouts_Manager layouts_manager;

#endif