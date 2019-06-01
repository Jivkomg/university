//
//  main.cpp
//  nth_prime
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

//int nth_prime(int n){
//    int cnt = 0;
//    int number = 1;
//    while(cnt != n){
//        if(is_prime(number)){
//            cnt++;
//        }
//        number++;
//    }
//    return number - 1;
//}
//TODO recursion
int nth_prime(int n){
    return 0;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << nth_prime(8) << std::endl;
    return 0;
}
