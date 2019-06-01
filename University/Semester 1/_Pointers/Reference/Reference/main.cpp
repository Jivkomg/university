//
//  main.cpp
//  Reference
//
//  Created by Zhivko Georgiev on 22.11.18.
//  Copyright © 2018 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
using namespace std;
int square(int &num){
    num *= num;
    return num;
}
int main() {
    int number = 10;
    int &number_ref = number;
//    cout << square(number) << endl;
    cout << number << endl;
    cout << number_ref << endl;
    number_ref = 50;
    cout << number << endl;
    cout << number_ref << endl;
    return 0;
}

