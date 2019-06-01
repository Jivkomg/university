//
//  main.cpp
//  MyPair
//
//  Created by Zhivko Georgiev on 16.04.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
#include "MyPair.hpp"

int main(int argc, const char * argv[]) {
    MyPair<int, double> p1;
    p1.setFirst(1);
    p1.setSecond(1.2);
    
    MyPair<int, double> p2;
    p1.setFirst(3);
    p1.setSecond(9.2);
    
    if(p1 == p2){
        std::cout << "Equal\n";
    }
    else std::cout << "Not equal\n";
    
//    std::cout << p1.getFirst();
    std::cout << p1 << std::endl;
    return 0;
}
