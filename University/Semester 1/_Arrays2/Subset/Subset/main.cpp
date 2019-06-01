//
//  main.cpp
//  Subset
//
//  Created by Zhivko Georgiev on 6.12.18.
//  Copyright © 2018 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    const int ARR1_SIZE = 3;
    const int ARR2_SIZE = 5;
    int arr1[ARR1_SIZE]{1, 2, 4};
    int arr2[ARR2_SIZE]{1,2,3,4,5};
    int cnt = 0;
    for(int i = 0; i < ARR1_SIZE; i++){
        for(int j = 0; j < ARR2_SIZE; j++){
            if(arr1[i] == arr2[j]){
                cnt++;
            }
        }
    }
    if(cnt == ARR1_SIZE){
        cout << "Subset!\n";
    }
    else cout << "Not a subset!\n";
    
    return 0;
}
