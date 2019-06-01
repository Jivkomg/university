//
//  main.cpp
//  SumOfDigits
//
//  Created by Zhivko Georgiev on 29.11.18.
//  Copyright © 2018 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int sumDigits (long long number, int divisor){
    int sum = 0;
    int numberOfDigits = (int)(log10((double)abs(number)) + 1);
    int currentNumber = 0;
    for (int i = 1; i <= numberOfDigits; i++){
        currentNumber = number % 10;
        number /= 10;
        if(i % divisor == 0){
            sum += currentNumber;
        }
    }
    return sum;
    
}
int main(int argc, const char * argv[]) {
    long long input = 123456789;
    cout << sumDigits(input, 3) << endl;
    return 0;
}
