/**
 *
 * Solution to homework assignment 2
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2018/2019
 *
 * @author Zhivko Georgiev
 * @idnumber 62304
 * @task 1
 * @compiler GCC
 *
 */

#include <iostream>
using namespace std;
const int MAX_ARRAY_SIZE = 100;
//validation for shifter
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

void arrayShifting(int array[], int length, int shifter){
//  validation
    if(shifter >= 5 || shifter <= -5){
        cout << "Error!" << endl;
        return;
    }

    int answer[MAX_ARRAY_SIZE];
    
//  this adjustment is done, because the algorithm is
//  identical for left and right shifting
    if(shifter < 0){
        shifter = length + shifter;
    }
    
    if(shifter >= 0 && shifter < length){
        for(int i = length - shifter, j = 0; i < length; i++, j++){
            answer[j] = array[i];
        }
        for(int i = 0, j = shifter; i < length - shifter; i++, j++){
            answer[j] = array[i];
        }
    }
    
    for(int i = 0; i < length; i++){
        cout << answer[i] <<' ';
    }
    cout << endl;
}
int main() {
    int length = 5;
    int inputArray[]{6, 5, 6, 0, 3};
    
    //validation
    int arrSize = sizeof(inputArray) / sizeof(inputArray[0]);
    if(length != arrSize || arrSize > MAX_ARRAY_SIZE){
        cout << "Wrong input" << endl;
        return 0;
    }

    int shifter = readInput();
    
    arrayShifting(inputArray, length, shifter);
    return 0;
}
