//
//  main.cpp
//  PointerDouble
//
//  Created by Zhivko Georgiev on 29.11.18.
//  Copyright © 2018 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
using namespace std;
void addressChanger(double **varPtr){
    double newDouble = **varPtr;
    *varPtr = new double(newDouble);
}
int main(int argc, const char * argv[]) {
    double var = 30;
    double *varPtr = &var;
    cout << varPtr << endl;
    addressChanger(&varPtr);
    cout << varPtr << endl;
    return 0;
}
