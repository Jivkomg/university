//
//  main.cpp
//  MatrixSum
//
//  Created by Zhivko Georgiev on 5.02.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
using namespace std;
int sumMatrix(size_t N, double** matrix){
    if (matrix == nullptr) {
        return 0;
    }
    int sum = 0;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            sum += matrix[i][j];
        }
    }
    return sum;
}
int main() {

//    size_t n = 5;
//    double** array = new double *[5];
//    for(int i = 0; i < 5 ; i++){
//        array[i] = new double[5];
//    }
    double arr[4][4]={1,  2,  3,  4,
                      2,  3,  1,  0,
                      1,  2,  4,  -1,
                      4,  5,  6,  1
    };
//    delete[] array;
//   cout << sumMatrix(4, arr) << endl;
    return 0;
}
