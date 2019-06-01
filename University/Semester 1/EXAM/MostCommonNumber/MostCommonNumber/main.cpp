//
//  main.cpp
//  MostCommonNumber
//
//  Created by Zhivko Georgiev on 7.02.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
using namespace std;
void mostCommon(int number){
    if(number < 0){
        number = -number;
    }
    int digits[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    do {
        int tmp = number % 10;
        number /= 10;
        digits[tmp]++;
    }
    while(number / 10 > 0);
    
    int leftOver = number % 10;
    digits[leftOver] ++;
    
    int max = -1;
    int cnt = 0;
    for(int i = 0; i < 10; i++){
        if(digits[i] > max){
            max = digits[i];
            cnt++;
        }
    }
}
int main(int argc, const char * argv[]) {
    int a = 1234310;
    mostCommon(a);
    return 0;
}
