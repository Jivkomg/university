//
//  main.cpp
//  LargestPrime
//
//  Created by Zhivko Georgiev on 15.11.18.
//  Copyright © 2018 Zhivko Georgiev. All rights reserved.
//
#include <math.h>
#include <iostream>
bool is_prime(int n){
    if(n == 1){
        return false;
    }
    for(int i = 2; i <= sqrt((double)n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
int largest_prime(int start, int end){
    for(int i = end; i >= start; i--){
        if(is_prime(i)){
            return i;
        }
    }
    return -1;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << largest_prime(2, 14) << std::endl;
    return 0;
}
