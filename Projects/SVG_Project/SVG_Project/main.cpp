//
//  main.cpp
//  SVG_Project
//
//  Created by Zhivko Georgiev on 29.05.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
#include "MyString.h"
int main(int argc, const char * argv[]) {
    MyString str;
    str = "bla";
    MyString str1 = "lmao";
    MyString str2 = str.concatenate(str1);
    std::cout << str2.indexOf('l');
    std::cout << str2;
    std::cin >> str;
    std::cout << str;
    return 0;
}
