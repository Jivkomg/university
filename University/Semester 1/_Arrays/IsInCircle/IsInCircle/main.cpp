//
//  main.cpp
//  IsInCircle
//
//  Created by Zhivko Georgiev on 3.12.18.
//  Copyright © 2018 Zhivko Georgiev. All rights reserved.
//
#include <math.h>
#include <iostream>
using namespace std;
void InFirstCircle(double x, double y){
    if(sqrt(x * x + y * y) <= 2){
        if(sqrt(x * x + y * y) == 2){
            cout << "Inside";
        }
        else cout << "On the circle";
    }
    else cout << "Outside";
}
void InSecondCircle(double x, double y){
    if(sqrt(x * x -  + (y - 3) * (y - 3)) <= 1){
        if(sqrt(x * x + y * y) == 1){
            cout << "Inside";
        }
        else cout << "On the circle";
    }
    else cout << "Outside";
}

int main(int argc, const char * argv[]) {
    return 0;
}
