//
//  main.cpp
//  MyString
//
//  Created by Zhivko Georgiev on 29.03.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
#include "MyString.h"

int main(int argc, const char * argv[]) {
    MyString a = MyString("asd");
    a.append('f');
    MyString b = a;
    std::cout << a << std::endl;
    std::cout << b<< std::endl;
    
    MyString c = MyString("xcxcx");
    std::cin >> c;
    std::cout << c << std::endl;
    return 0;
}
