//
//  main.cpp
//  Recursion
//
//  Created by Zhivko Georgiev on 15.11.18.
//  Copyright © 2018 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
int factorial(int n){
    if(n == 0){
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << factorial(6) << std::endl;
    return 0;
}
