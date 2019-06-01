//
//  main.cpp
//  SumOfPairs
//
//  Created by Zhivko Georgiev on 6.12.18.
//  Copyright © 2018 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    const int ARR_SIZE = 10;
    int arr[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 7;
    int cnt = 0;
    for(int i = 0; i < ARR_SIZE; i++){
        for(int j = i; j < ARR_SIZE; j++){
            if(arr[i] + arr[j] == n){
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
