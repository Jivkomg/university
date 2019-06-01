/**
 *
 * Solution to homework assignment 3
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2018/2019
 *
 * @author Zhivko Georgiev
 * @idnumber 62304
 * @task 2
 * @compiler GCC
 *
 */


#include <iostream>
using namespace std;
const int MATRIX_SIZE = 3;

//multiply a matrix by scalar
void multiplyByNumber(double matrix[][MATRIX_SIZE], int number){
    for(int i = 0; i < MATRIX_SIZE; i++){
        for(int j = 0; j < MATRIX_SIZE; j++){
            matrix[i][j] *= number;
        }
    }
}

//transpose matrix A
void transposeMatrix(double matrix[MATRIX_SIZE][MATRIX_SIZE], double transMatrix[MATRIX_SIZE][MATRIX_SIZE]){
    for(int i = 0; i < MATRIX_SIZE; i++){
        for(int j = 0; j < MATRIX_SIZE; j++){
            transMatrix[i][j] = matrix[j][i];
        }
    }
    for(int i = 0; i < MATRIX_SIZE; i++){
        for(int j = 0; j < MATRIX_SIZE; j++){
            matrix[i][j] = transMatrix[i][j];
        }
    }
}


//sum two matricies
void sumMatrix(double firstMatrix[][MATRIX_SIZE], double secondMatrix[][MATRIX_SIZE], double sumMatrix[][MATRIX_SIZE]){
    for(int i = 0; i < MATRIX_SIZE; i++){
        for(int j = 0; j < MATRIX_SIZE; j++){
            sumMatrix[i][j] = firstMatrix[i][j] + secondMatrix[i][j];
        }
    }
}

//multiply matrix by another matrix
void multiplyMatrix(double firstMatrix[][MATRIX_SIZE], double secondMatrix[][MATRIX_SIZE],
                    double multiMatrix[][MATRIX_SIZE]){
    for(int i = 0; i < MATRIX_SIZE; i++){
        for(int j = 0; j < MATRIX_SIZE; j++){
            for(int k = 0; k < MATRIX_SIZE; k++){
                multiMatrix[i][j]  += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}
//flag if there is no solution
bool error = false;

// find inverse matrix with formula, without using Gauss
void inverseMatrix(double matrix[MATRIX_SIZE][MATRIX_SIZE], double inverseMatrix[MATRIX_SIZE][MATRIX_SIZE]){
    double determinant = 0;
    for(int i = 0; i < 3; i++){
        determinant = determinant + (matrix[0][i] * (matrix[1][(i + 1) % 3] * matrix[2][(i + 2) % 3]
                                  - matrix[1][(i + 2) % 3] * matrix[2][(i + 1) % 3]));
        
    }
    //if the determinant is 0
    if(determinant < 0.000000001 && determinant > -0.000000001){
        error = true;
        return;
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
            inverseMatrix[i][j] = ((matrix[(j + 1) % 3][(i + 1) % 3] * matrix[(j + 2) % 3][(i + 2) % 3])
                                   - (matrix[(j + 1) % 3][(i + 2) % 3] * matrix[(j + 2) % 3][(i + 1) % 3]))/ determinant;
        }
    }

//matrix printer
void printMatrix(double matrix[MATRIX_SIZE][MATRIX_SIZE]){
    for(int i = 0; i < MATRIX_SIZE; i++){
        for(int j = 0; j < MATRIX_SIZE; j++){
            cout << matrix[i][j]<<'\t';
        }
        cout << endl;
    }
}

//solve the equation
//the equation is solved with inverse matrix, not with Gaussian Elimination
void matrixEquationSolver(double matrix_A[MATRIX_SIZE][MATRIX_SIZE],double matrix_C[MATRIX_SIZE][MATRIX_SIZE],
                         double answerMatrix[MATRIX_SIZE][MATRIX_SIZE]){
    double identityMatrix[MATRIX_SIZE][MATRIX_SIZE] = {1, 0, 0,
                                                       0, 1, 0,
                                                       0, 0, 1};
    
    double transA[MATRIX_SIZE][MATRIX_SIZE];
    transposeMatrix(matrix_A, transA);
    
    multiplyByNumber(transA, -3);
    
    double firstMatrix[MATRIX_SIZE][MATRIX_SIZE];
    multiplyMatrix(transA, matrix_C,firstMatrix);
    
    multiplyByNumber(identityMatrix, 5);
    double secondMatrix[MATRIX_SIZE][MATRIX_SIZE];
    sumMatrix(matrix_A, identityMatrix, secondMatrix);
    
    double secondInverse[MATRIX_SIZE][MATRIX_SIZE];
    inverseMatrix(secondMatrix, secondInverse);
    
    multiplyMatrix(firstMatrix, secondInverse, answerMatrix);
}

int main(int argc, const char * argv[]) {
    double A[MATRIX_SIZE][MATRIX_SIZE] = {-4,  1,  1,
                                           1, -3,  2,
                                           1,  2, -4};
    
    double C[MATRIX_SIZE][MATRIX_SIZE] = {-1, -2, -2,
                                          -1, -3, -4,
                                          -1, -3, -5};
    
    double answerMatrix[MATRIX_SIZE][MATRIX_SIZE];
    matrixEquationSolver(A, C, answerMatrix);
    
    //error means infinite solutions or no solution at all
    if(error){
        cout << "Error" << endl;
        return 0;
    }

    printMatrix(answerMatrix);

    
    return 0;
}
