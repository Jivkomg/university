//
//  main.cpp
//  RecursionTest
//
//  Created by Zhivko Georgiev on 3.01.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
using namespace std;

int fib(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

long long rec(int n){
    if (n == 0){
        return 3;
    }
    if (n == 1){
        return 2;
    }
    long long rec_n_minus_1 = rec(n - 1);
    return rec_n_minus_1 * rec_n_minus_1 + 7 - rec(n - 2);
}
int main() {
    cout << rec(5) << endl;
    return 0;
}
