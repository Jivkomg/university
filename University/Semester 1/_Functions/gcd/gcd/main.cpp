//
//  main.cpp
//  gcd
//
//  Created by Zhivko Georgiev on 15.11.18.
//  Copyright © 2018 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
int gcd(int a, int b){
    int min = (a <= b) ? a : b;
    int gcd = 1;
    for(int i = 1; i <= min; i++){
        if(a % i == 0 && b % i == 0){
            gcd = i;
        }
    }
    return gcd;
}
//TODO recursion
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << gcd(25,5) << std::endl;
    return 0;
}
