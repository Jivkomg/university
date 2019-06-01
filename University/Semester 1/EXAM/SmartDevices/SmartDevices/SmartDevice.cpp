//
//  SmartDevice.cpp
//  SmartDevices
//
//  Created by Zhivko Georgiev on 18.05.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
#include "SmartDevice.h"

SmartDevice::SmartDevice() {
    productNumber = 0;
    RAM = 0;
    speed = 0;
    cores = 0;
}

SmartDevice::SmartDevice(int num, int ram, int speed, int cores):productNumber(num), RAM(ram), speed(speed), cores(cores) {
}

void SmartDevice::setProductNumber(int num) {
    productNumber = num;
}

void SmartDevice::setRAM(int ram) {
    RAM = ram;
}

void SmartDevice::setSpeed(int s) {
    speed = s;
}

void SmartDevice::setCores(int c) {
    cores = c;
}

const int SmartDevice::getProductNumber() const { 
    return productNumber;
}

const int SmartDevice::getRAM() const { 
    return RAM;
}

const int SmartDevice::getSpeed() const { 
    return speed;
}

const int SmartDevice::getCores() const { 
    return cores;
}

void SmartDevice::print() const {
    std::cout << productNumber << " " << RAM << " " <<
    speed << " " << cores << std::endl;
}



