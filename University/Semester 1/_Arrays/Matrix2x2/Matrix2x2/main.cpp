//
//  main.cpp
//  Matrix2x2
//
//  Created by Zhivko Georgiev on 29.11.18.
//  Copyright © 2018 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
using namespace std;
int determinant(int arr[2][2]){
    return (arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0]);
}
int main(int argc, const char * argv[]) {
    int array[2][2];
    int number;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cin >> number;
            array[i][j] = number;
        }
    }
    cout << endl;
    cout << determinant(array) << endl;
    return 0;
}
