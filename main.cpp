/* 
 * File:   main.cpp
 * Author: Ihsan Younes
 */

#include "DeviceManager.h"
#include "devices/KeyboardDevice.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;

//Setup the device manager on "shared_ptr" in this way the memory
//free-up is automatic
shared_ptr<DeviceManager> deviceManager(new DeviceManager());

/**
 * On finish this handler will be executed, 
 * printig the total number of messages received
 */
void exit_handler(int s){
    
    //Stop monitoring
    deviceManager->stopMonitoring();
    
    //Get the total messages
    int n = deviceManager->messagesReceived();
    
    printf("Total messages received from devices: %d\n", n);

    //exit
    abort();

}


int main(int argc, char** argv) {
       
    
    //Program exit delegation to our handler
    struct sigaction sigIntHandler;
    sigIntHandler.sa_handler = exit_handler;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    sigaction(SIGINT, &sigIntHandler, NULL);

    
    //Setup a new device
    shared_ptr<KeyboardDevice> keyboardDevice(new KeyboardDevice());
    
    //Add keyboard device to manager
    deviceManager->addDevice(keyboardDevice);
    //.. You can here more devices
    
    //Start the devices manager monitor
    deviceManager->startMonitoring();
    

    return 0;
}

