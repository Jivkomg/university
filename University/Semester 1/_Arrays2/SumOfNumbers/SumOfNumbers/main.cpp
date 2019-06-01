//
//  main.cpp
//  SumOfNumbers
//
//  Created by Zhivko Georgiev on 6.12.18.
//  Copyright © 2018 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    const int ARR_SIZE = 10;
    int arr[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 0;
    for (int i = 0; i < ARR_SIZE; i++){
        if(arr[i] % 2 == 0 && (arr[i] / 2) * 2 == arr[i] && (arr[i] / 2) % 2 != 0){
            sum += arr[i];
        }
    }
    cout << sum << endl;
    return 0;
}
