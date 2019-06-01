//
//  main.cpp
//  ZigZagArray
//
//  Created by Zhivko Georgiev on 6.12.18.
//  Copyright © 2018 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int length = 0;
    cin >> length;
    const int ARR_SIZE = length;
    
    int arr[ARR_SIZE];
    for(int i = 0; i < ARR_SIZE; i++){
        cin >> arr[i];
    }
    bool isZigZag = true;
    for(int i = 0; i < ARR_SIZE - 1; i++){
        if(i % 2 == 0){
            if(arr[i] > arr[i + 1]){
                isZigZag = false;
            }
        }
        else{
            if(arr[i] < arr[i + 1]){
                isZigZag = false;
            }
        }
    }
    cout << isZigZag;
    return 0;
}
