/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Device.cpp
 * Author: iss
 * 
 * Created on 17 settembre 2016, 7.58
 */

#include "Device.h"

Device::Device() {
    messages = 0;
}

Device::~Device() {
}

void Device::messageReceived() {
    messages++;
}

int Device::getMessagesNumber() {
    return messages;
}
