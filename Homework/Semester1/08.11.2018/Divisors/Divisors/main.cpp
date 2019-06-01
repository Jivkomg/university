//
//  main.cpp
//  Divisors
//
//  Created by Zhivko Georgiev on 17.11.18.
//  Copyright © 2018 Zhivko Georgiev. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int number = 0;
    std::cout<<"Enter a number \n1";
    std::cin >> number;
    for(int i = 1; i <= number; i++){
        if(number % i == 0){
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}
