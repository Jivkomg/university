//
//  main.cpp
//  StringTest2
//
//  Created by Zhivko Georgiev on 20.12.18.
//  Copyright © 2018 Zhivko Georgiev. All rights reserved.
//
#include <iostream>
#include<cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    cout << endl;
    char str[10];
    cin >> str;
    str[1] = '^';
    str[2] = '\0';
    cout << str << endl;
    cout << strlen(str) << endl;
    
    return 0;
}
