#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>


/* CONFIG - here you can define your cat variant */

#define side                0   // 0-(left) || 1-(right)
#define thumb_module        1   // 0-(only keys) || 1-(keys+joystick) || 2-(trackball) 
#define finger_module       1   // 0-(only keys) || 1-(keys+wheel) 
#define additional_modules  0   // 0-(none) || 1-(mouse moudule)



class Config {

    public:

        //the variant variable is used to communicate with the LYNXapp
        String variant = "C0-000-000-000-v0.2.0";

        // the setup function is used to set the variant variable
        void set_variant();
};

// create an instance
extern Config config;

#endif