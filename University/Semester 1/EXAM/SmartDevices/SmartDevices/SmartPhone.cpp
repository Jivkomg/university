//
//  SmartPhone.cpp
//  SmartDevices
//
//  Created by Zhivko Georgiev on 18.05.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
#include "SmartPhone.h"

SmartPhone::SmartPhone(){
    camaraResolution = 0;
}

SmartPhone::SmartPhone(int c) {
    camaraResolution = c;
}
void SmartPhone::setRes(int res) {
    camaraResolution = res;
}

const int SmartPhone::getRes() const { 
    return camaraResolution;
}

void SmartPhone::print() const {
    Phone::print();
    SmartDevice::print();
    std::cout << camaraResolution;
}



