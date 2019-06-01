//
//  SmartDevice.h
//  SmartDevices
//
//  Created by Zhivko Georgiev on 18.05.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef SmartDevice_h
#define SmartDevice_h

class SmartDevice{
protected:
    int productNumber;
    int RAM;
    int speed;
    int cores;
public:
    SmartDevice();
    SmartDevice(int, int, int, int);
    void setProductNumber(int);
    void setRAM(int);
    void setSpeed(int);
    void setCores(int);
    
    const int getProductNumber() const;
    const int getRAM() const;
    const int getSpeed() const;
    const int getCores() const;
    
    void print() const;
};
#endif /* SmartDevice_h */
