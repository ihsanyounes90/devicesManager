/* 
 * File:   Device.h
 * Author: Ihsan Younes
 */

#ifndef DEVICE_H
#define DEVICE_H

/**
 * The Device class is an abstract definition of a generic device, 
 * any new device must implement start() and stop() methods.
 */
class Device {
public:
    Device();
    virtual ~Device();
    
    /**
     * start the device binding
     */
    virtual void start() = 0;
    
    /**
     * stop the device binding
     */
    virtual void stop() = 0;
    
    /**
     * This method must be called during the binding of a device upon
     * receiving a message
     */
    void messageReceived();
        
    /**
     * Get the number of received messages
     */
    int getMessagesNumber();
    
    
private:
    //actual number of received messages
    int messages;
};

#endif /* DEVICE_H */

