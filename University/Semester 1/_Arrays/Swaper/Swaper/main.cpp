//
//  main.cpp
//  Swaper
//
//  Created by Zhivko Georgiev on 29.11.18.
//  Copyright © 2018 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
using namespace std;
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
int main(int argc, const char * argv[]) {
    int firstNum, secondNum;
    cin >> firstNum;
    cin >> secondNum;
    swap(firstNum, secondNum);
    cout << "First number " << firstNum << endl;
    cout << "Second number " << secondNum << endl;

    
    return 0;
}
