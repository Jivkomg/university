//
//  main.cpp
//  Average
//
//  Created by Zhivko Georgiev on 17.11.18.
//  Copyright © 2018 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    cout << "Enter numbers \n";
    double number = 0;
    int counter = 0;
    double sum = 0;
    do{
        cin >> number;
        counter++;
        sum+= number;
    }
    while(number != 0);
    std::cout << sum / (counter - 1);
    cout << endl;
    return 0;
}
