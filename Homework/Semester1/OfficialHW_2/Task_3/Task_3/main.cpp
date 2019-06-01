/**
 *
 * Solution to homework assignment 2
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
using namespace std;
//validation
int readInput()
{
    int input = -1;
    bool valid = false;
    do{
        cin >> input;
        if (cin.good()){
            valid = true;
        }
        else{
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid input, please enter again." << endl;
        }
    } while (!valid);
    
    return (input);
}

const int MATRIX_SIZE = 6;

bool isMatrixSimplified(int matrix[MATRIX_SIZE][MATRIX_SIZE]){
    for(int i = 0; i < MATRIX_SIZE; i++){
        for(int j = 0; j < MATRIX_SIZE; j++){
            if(matrix[i][j] < 0 || matrix[i][j] > 9){
                return false;
            }
        }
    }
    return true;
}

//  finding the number of digits
int numDigits(int number)
{
    int digits = 0;
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}

int timesNumberMet(int matrix[MATRIX_SIZE][MATRIX_SIZE], int number){
//   validation
    if(!isMatrixSimplified(matrix)){
        cout << "Error" << endl;
        return -1;
    }
    if(number > 999999 || number < 0){
        return 0;
    }
    
//    one counter for all searchings
    int counter = 0;
    
//    optimisation if number is one digit
    if(number <= 9 && number >= 0){
        for(int i = 0; i < MATRIX_SIZE; i++){
            for(int j = 0; j < MATRIX_SIZE; j++){
                if(matrix[i][j] == number){
                    counter++;                }
            }
        }
        return counter * 4;
    }
    
//    converting number to array
    int size = numDigits(number);
    int arrNumber[MATRIX_SIZE];
    
    for(int i = size - 1; i >= 0; i--){
        arrNumber[i] = number % 10;
        number /= 10;
    }
    
//    left to right rows
    for(int row = 0; row < MATRIX_SIZE; row++){
        for (int col = 0; col < MATRIX_SIZE; col++) {
            for (int i = 0; i < size; i++) {
                if(matrix[row][col + i] == arrNumber[i]){
                    if(i == size - 1 && col + i < MATRIX_SIZE){
                        counter++;
                    }
                }
                else break;
            }
        }
    }

//    right to left rows
    for(int row = 0; row < MATRIX_SIZE; row++){
        for (int col = MATRIX_SIZE - 1; col >= 0; col--) {
            for (int i = 0; i < size; i++){
                if(matrix[row][col - i] == arrNumber[i]){
                    if(i == size - 1 && col - i >= 0){
                        counter++;
                    }
                }
                else break;
            }
        }
    }
    
//    ut to down columns
    for (int col = 0; col < MATRIX_SIZE; col++) {
        for (int row = 0; row < MATRIX_SIZE; row++) {
            for(int i = 0; i < size; i++){
                if(matrix[row + i][col] == arrNumber[i]){
                    if(i == size - 1 && row + i < MATRIX_SIZE){
                        counter ++;
                    }
                }
                else break;
            }
        }
    }
    
//    down to up columns
    for (int col = 0; col < MATRIX_SIZE; col++) {
        for (int row = MATRIX_SIZE - 1; row >= 0; row--) {
            for(int i = 0; i < size; i++){
                if(matrix[row - i][col] == arrNumber[i]){
                    if(i == size - 1 && row - i >= 0){
                        counter ++;
                    }
                }
                else break;
            }
        }
    }

    return counter;
}
int main(int argc, const char * argv[]) {
    int matrix[MATRIX_SIZE][MATRIX_SIZE] = {
        {5, 4, 3, 8, 0, 6},
        {9, 4, 5, 1, 0, 2},
        {8, 5, 8, 0, 6, 1},
        {0, 9, 6, 8, 4, 2},
        {6, 1, 0, 2, 6, 1},
        {2, 1, 8, 4, 2, 6},
    };
    int number = readInput();

    cout << timesNumberMet(matrix, number) << endl;
    return 0;
}
