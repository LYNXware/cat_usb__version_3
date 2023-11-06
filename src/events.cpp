#include "events.h"




void Event::actuate(byte event){
    
    passing_event = layouts_manager.events_bank[layer_control.active_layer][event];
   
    if (passing_event[0] == MOUSE_FUNCTION){
        mouse_press(passing_event[1]);
    }
    else if (passing_event[0] == CAT_FUNCTION){
        cat_actuate(passing_event);
        // layer_control.switch_layer(passing_event[1]);
    }      
    else{
        keyboard_press(passing_event);
        delay(1);
    }  
}



void Event::deactuate(byte event){

    passing_event = layouts_manager.events_bank[layer_control.active_layer][event];
    
    if (passing_event[0] == MOUSE_FUNCTION){
        mouse_release(passing_event[1]);
    }
    else if (passing_event[0] == CAT_FUNCTION){
        cat_deactuate(passing_event);
        // layer_control.switch_layer_back(passing_event[1]);
    }    
    else{
        keyboard_release(passing_event);
    } 
}



void Event::cat_actuate(String passingEvent)
{
    if (passingEvent[1] == CAT_LAYER_SWITCH){
        layer_control.switch_layer(passingEvent[2]);
    }
    else if (passingEvent[1] == CAT_GYRO)
    {
        /* code */
    }
    
}


void Event::cat_deactuate(String passingEvent)
{
    if (passingEvent[1] == CAT_LAYER_SWITCH){
        layer_control.switch_layer_back(passingEvent[2]);
    }
    else if (passingEvent[1] == CAT_GYRO)
    {
        /* code */
    }
}



void Event::keyboard_press(String passingEvent){

    pel = passing_event.length();

    for(k=0; k < pel; k++){ 

        switch (passing_event[k]){

            case 0x80: // 0x80 is the left control key
                Keyboard._keyReport.modifiers |= 1;
                Keyboard.sendReport(&Keyboard._keyReport);
                break;

            case 0x81: // 0x81 is the left shift key
                Keyboard._keyReport.modifiers |= 2;
                Keyboard.sendReport(&Keyboard._keyReport);
                break;

            case 0x82: // 0x82 is the left alt key
                Keyboard._keyReport.modifiers |= 4;
                Keyboard.sendReport(&Keyboard._keyReport);
                break;    

            case 0x83: // 0x83 is the left GUI/super key
                Keyboard._keyReport.modifiers |= 8;
                Keyboard.sendReport(&Keyboard._keyReport);
                break;

            case 0x84: // 0x84 is the right control key
                Keyboard._keyReport.modifiers |= 16;
                Keyboard.sendReport(&Keyboard._keyReport);
                break;

            case 0x85: // 0x85 is the right shift key
                Keyboard._keyReport.modifiers |= 32;
                Keyboard.sendReport(&Keyboard._keyReport);
                break;
            
            case 0x86: // 0x86 is the right alt key
                Keyboard._keyReport.modifiers |= 64;
                Keyboard.sendReport(&Keyboard._keyReport);
                break;

            case 0x87: // 0x87 is the right GUI/super key
                Keyboard._keyReport.modifiers |= 128;
                Keyboard.sendReport(&Keyboard._keyReport);
                break;

            default:
                event_component = passing_event[k];
                Keyboard.press(event_component);
                break;
            }
    }
}



void Event::keyboard_release(String passingEvent){

    pel = passing_event.length();

    for(k=0; k < pel; k++){ 

        switch (passing_event[k]){

            case 0x80: // 0x80 is the left control key
                Keyboard._keyReport.modifiers &= ~1;
                Keyboard.sendReport(&Keyboard._keyReport);
                break;

            case 0x81: // 0x81 is the left shift key
                Keyboard._keyReport.modifiers &= ~2;
                Keyboard.sendReport(&Keyboard._keyReport);
                break;

            case 0x82: // 0x82 is the left alt key
                Keyboard._keyReport.modifiers &= ~4;
                Keyboard.sendReport(&Keyboard._keyReport);
                break;

            case 0x83: // 0x83 is the left GUI/super key
                Keyboard._keyReport.modifiers &= ~8;
                Keyboard.sendReport(&Keyboard._keyReport);;
                break; 
            
            case 0x84: // 0x84 is the right control key
                Keyboard._keyReport.modifiers &= ~16;
                Keyboard.sendReport(&Keyboard._keyReport);
                break;

            case 0x85: // 0x85 is the right shift key
                Keyboard._keyReport.modifiers &= ~32;
                Keyboard.sendReport(&Keyboard._keyReport);
                break;
            
            case 0x86: // 0x86 is the right alt key
                Keyboard._keyReport.modifiers &= ~64;
                Keyboard.sendReport(&Keyboard._keyReport);
                break;

            case 0x87: // 0x87 is the right GUI/super key
                Keyboard._keyReport.modifiers &= ~128;
                Keyboard.sendReport(&Keyboard._keyReport);
                break;    


            default:
                event_component = passing_event[k];
                Keyboard.release(event_component);
                break;
        }
    }
}


void Event::mouse_press(char m){

    switch (m) {
               
        case 0xf1:
            Mouse.press(MOUSE_LEFT);
            break;
        
        case 0xf2:
            Mouse.press(MOUSE_MIDDLE);
            break;
        
        case 0xf3:
            Mouse.press(MOUSE_RIGHT);
            break;   
        
        case 0xf4:
            Mouse.move(0, 0, 1);
            break;
        
        case 0xf5:
            Mouse.move(0, 0, -1);
            break;    
        
        default:
            // do nothing
            break;
    }
}



void Event::mouse_release(char m){
    
    switch (m) {
        
        case 0xf1:
            Mouse.release(MOUSE_LEFT);
            break;
        
        case 0xf2:
            Mouse.release(MOUSE_MIDDLE);
            break;
        
        case 0xf3:
            Mouse.release(MOUSE_RIGHT);
            break;  
                
        default:
            // do nothing
            break;
    }
}


Event event;

USBHIDKeyboard Keyboard;
USBHIDMouse Mouse;


