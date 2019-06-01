//
//  main.cpp
//  Pointers
//
//  Created by Zhivko Georgiev on 22.11.18.
//  Copyright © 2018 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    //this is better
    int *p = nullptr;
//    int *p = 0;
    
    int i_number = 15;
    double d_number = 3.1415;
    short s_number = 15;
    char c_char = '*';

    int *i_ptr = &i_number;
    double *d_ptr = &d_number;
    char *c_ptr;
    
    
    cout << i_number << endl;
    cout << d_number << endl;
    cout << *d_ptr << endl;
    return 0;
}
