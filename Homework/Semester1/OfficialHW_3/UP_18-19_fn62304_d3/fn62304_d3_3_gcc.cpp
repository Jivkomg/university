/**
 *
 * Solution to homework assignment 3
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2018/2019
 *
 * @author Zhivko Georgiev
 * @idnumber 62304
 * @task 3
 * @compiler GCC
 *
 */

#include <iostream>
#include <math.h>

using namespace std;
const int SIZE = 4;

const int n = 4;
const int m = 2;

void gaussianElimination(double matrix[][SIZE], int rowsCnt){
    double elementToDevide = 0;
    int row = 0;
    int col = 0;
 
    for (int i = 0; i < SIZE; i++) {
        for(int j = 0; j < rowsCnt - 1; j++){
            if(matrix[i][j] != 0){
                elementToDevide = matrix[i][j];
                row = j;
                col = i;
                break;
            }
        }
    }

    for(int j = col; j < rowsCnt - 1; j ++){
        matrix[row][col] /= elementToDevide;
    }
//    eliminate
    for (int i = 0; i < SIZE; i++) {
        for (int k = i + 1; k < SIZE; k++) {
            double c = - matrix[k][i]/matrix[i][i];
            for (int j = i; j < SIZE + 1; j++) {
                if (i == j) {
                    matrix[k][j] = 0;
                } else {
                matrix[k][j] += c * matrix[i][j];
                }
            }
        }
    }
//    swap
    for(int i = 0; i < SIZE; i ++){
        for (int j = 0; j < rowsCnt - 1; j++){
            if(matrix[j][j] == 0)
            {
                double temp;
                temp = matrix[j][i];
                matrix[j + 1][i] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
//    divide
    for(int j = 0; j < rowsCnt - 1; j++){
        if(matrix[j][j] != 0){
            int divisor = matrix[j][j];
            for(int i = 0; i < SIZE; i++){
                matrix[j][i] /= divisor;
            }
        }
    }
}

bool isRowZero(double matrix[][SIZE], int rowIndex){
    for(int i = 0; i < SIZE; i++){
        if(matrix[rowIndex][i] != 0){
            return false;
        }
    }
    return true;
}

// U + W
void concatinateTwoArrays(double firstMatrixA[][SIZE], double secondMatrixB[][SIZE], double matrix[][SIZE]){
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < SIZE; j++){
            matrix[i][j] = firstMatrixA[i][j];
        }
    }
    for(int i = n; i < n + m; i++){
        for(int j = 0; j < SIZE; j++){
            matrix[i][j] = secondMatrixB[i][j];
        }
    }
}

void findingSumOfSpans(double matrixAi[][SIZE], double matrixBi[][SIZE]){
    double matrix[n + m][SIZE];
    
    //it should not be matrixB but a fundamental system of solutions of matrixB
    concatinateTwoArrays(matrixAi, matrixBi, matrix);
    gaussianElimination(matrix, n + m);
    for(int i = 0; i < n + m; i++){
        if(isRowZero(matrix, i)){
            continue;
        }
        for(int j = 0; j < SIZE; j++){
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    double vectorsAi [n][SIZE] = {2, 8, -3, 14,
                                 -1, 2, 3, 5,
                                 -1, 14, 6, 29,
                                 0, 12, 3, 24};
    
    double systemBi [m][SIZE] = {0, 1, 1, 0,
                                 1, 7, 0, -8};
    
    gaussianElimination(systemBi, 2);
    findingSumOfSpans(vectorsAi, systemBi);
    return 0;
}
