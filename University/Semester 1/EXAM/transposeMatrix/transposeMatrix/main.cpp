//
//  main.cpp
//  transposeMatrix
//
//  Created by Zhivko Georgiev on 6.02.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
using namespace std;

double** transposeMatrix(int N, double** matrix){
    double** transMatrix = new double*[N];
    for(int i = 0; i < N; i++){
        transMatrix[i] = new double[N];
    }                               
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            transMatrix[i][j] = matrix[j][i];
        }
    }
    return transMatrix;
}
int main() {
//    double** matrix = new double*[3];
//    for(int i = 0; i < 3; i++){
//        matrix[i] = new double[3];
//    }
//    double m[3][3] = {1,2,3,4,5,6,7,8,9};
//    for(int i = 0; i < 3; i++){
//        for(int j = 0; j < 3; j++){
//            matrix[i][j] = m[i][j];
//        }
//    }
//    matrix = transposeMatrix(3, matrix);
//    for(int i = 0; i < 3; i++){
//        for(int j = 0; j < 3; j++){
//            cout << matrix[i][j] << " ";
//        }
//        cout << endl;
//    }
    return 0;
}
