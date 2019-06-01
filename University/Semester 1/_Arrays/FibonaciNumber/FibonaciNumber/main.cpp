//
//  main.cpp
//  FibonaciNumber
//
//  Created by Zhivko Georgiev on 29.11.18.
//  Copyright © 2018 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
using namespace std;
// 0 1 1 2 3 5 8 13 21 34
int fibonaci(int index){
    int currentNumber = 1;
    int prevNumber = 0;
    for(int i = 0; i < index - 1; i++){
        int temp = currentNumber;
        currentNumber += prevNumber;
        prevNumber = temp;
    }
    return prevNumber;
}
int main(int argc, const char * argv[]) {
    int index = 0;
    cin >> index;
    cout << endl;
    cout << fibonaci(index);
    return 0;
}
