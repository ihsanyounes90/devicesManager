/* 
 * File:   DeviceManager.h
 * Author: Ihsan Younes
 */

#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include "devices/Device.h"
#include <memory>

/**
 * The DeviceManager is the class that monitor all the current devices
 */
class DeviceManager {
public:
    DeviceManager();
    virtual ~DeviceManager();
    
    /**
     * Add a device to the manager
     * @param device the device to add
     */
    void addDevice(std::shared_ptr<Device> device);
        
    /**
     * Start the bining of all the devices
     */
    void startMonitoring();
    
    /**
     * Stop the bining of all the devices
     */
    void stopMonitoring();

    /**
     * Get the total messages received on all devices
     */
    int messagesReceived();
    
private:
    bool monitoring;
};

#endif /* DEVICEMANAGER_H */

