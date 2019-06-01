//
//  main.cpp
//  MultiPlication
//
//  Created by Zhivko Georgiev on 7.02.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
using namespace std;
int** matrixMulpiplication(int** firstMatrix, const int N, const int M, int** secondMatrix, const int M1, const int K){
    if(M1 != M){
        return nullptr;
    }
    int** result = new int*[N];
    for(int i = 0; i < N; i++){
        result[i] = new int[K];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < K; j++){
            for(int k = 0; k < M; k++){
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
    return result;
}
int main() {
    return 0;
}
