//
//  main.cpp
//  SmartDevices
//
//  Created by Zhivko Georgiev on 18.05.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
#include "SmartPhone.h"
int main(int argc, const char * argv[]) {

    SmartPhone s1;
    s1.setName("bla");
    s1.setRAM(8);
    s1.setCores(2);
    s1.setSpeed(45);
    s1.setProductNumber(456);
    s1.setRes(8);
    s1.setNumber(56789876);
    s1.setScreenSize(6);
    s1.print();
    std::cout << "Hello, World!\n";
    return 0;
}
