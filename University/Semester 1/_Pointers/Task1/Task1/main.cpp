//
//  main.cpp
//  Task1
//
//  Created by Zhivko Georgiev on 22.11.18.
//  Copyright © 2018 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int number = 76;
    int *int_ptr = &number;
    cout << int_ptr << endl;
    cout << *int_ptr << endl;
    cout << number << endl;
    
    *int_ptr = 10;
    cout << int_ptr << endl;
    cout << *int_ptr << endl;
    cout << number << endl;
    return 0;
}
