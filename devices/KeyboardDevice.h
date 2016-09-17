/* 
 * File:   Device.h
 * Author: Ihsan Younes
 */
#ifndef KEYBOARDDEVICE_H
#define KEYBOARDDEVICE_H

#include "Device.h"

/**
 * The KeyboardDevice class is an implementation of the abstract class Device, 
 * It provides the binings for the Keyboard events
 */
class KeyboardDevice : public Device{
public:
    KeyboardDevice();
    virtual ~KeyboardDevice();
    
    /**
     * @see Device.start()
     */
    void start();
    
    /**
     * @see Device.stop()
     */
    void stop();
        
   
private:
    /**
     * The main method that binds the keyboard events
     */
    void keyListener();
    
     //indicates if current device is active
     bool active ;
};

#endif /* KEYBOARDDEVICE_H */

