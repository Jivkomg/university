//
//  main.cpp
//  StringTest3
//
//  Created by Zhivko Georgiev on 20.12.18.
//  Copyright © 2018 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    char str1[15] = "abcd";
    char* str2 = "accd";
    cout << strcmp(str1,str2) << endl;
    cout << str1 << endl;
    cout << str2 << endl;
    strcat(str1, str2);
    cout << str1 << endl;
    cout << str2 << endl;
    
    return 0;
}
