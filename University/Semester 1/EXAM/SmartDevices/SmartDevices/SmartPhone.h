//
//  SmartPhone.h
//  SmartDevices
//
//  Created by Zhivko Georgiev on 18.05.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef SmartPhone_h
#define SmartPhone_h
#include "SmartDevice.h"
#include "Phone.h"
class SmartPhone: public SmartDevice, public Phone{
private:
    int camaraResolution;
public:
    SmartPhone();
    SmartPhone(int);
    void setRes(int);
    const int getRes() const;
    void print() const;
};
#endif /* SmartPhone_h */
