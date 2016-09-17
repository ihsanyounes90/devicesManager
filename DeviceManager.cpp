/* 
 * File:   KeyboardDevice.cpp
 * Author: Ihsan Younes
 */

#include "DeviceManager.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//An array containing all the devices
vector< shared_ptr<Device> > devices;

DeviceManager::DeviceManager() {
    monitoring = false;
}

DeviceManager::~DeviceManager() {

}


void DeviceManager::addDevice(shared_ptr<Device> device) {
    //Add the device to our array
    devices.push_back(device);
    
    //If we are already monitoring we must start the device manually
    if(monitoring){
        device->start();
    }
}

void DeviceManager::startMonitoring() {
    monitoring = true;
    //Start all devices in the array
    for(int ii=0; ii < devices.size(); ii++){
        devices[ii]->start();
   }
}

void DeviceManager::stopMonitoring() {
    monitoring = false;
   //Stop all devices in the array
   for(int ii=0; ii < devices.size(); ii++){
      devices[ii]->stop();
   }
}


int DeviceManager::messagesReceived() {
    
    //Compute the total number of messages on all devices
    int msg = 0;
    for(int ii=0; ii < devices.size(); ii++){
      msg += devices[ii]->getMessagesNumber();
   }
    return msg;
}
