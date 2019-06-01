/**
 *
 * Solution to homework task 1
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
//validation
int readInput(int uppBound)
{
    int input = -1;
    bool valid = false;
    do{
        cin >> input;
        if (cin.good() && input <= uppBound){
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

int main()
{
    cout << "Enter series of numbers: " <<endl;
    //65535 = 2^16 - 1
    unsigned const short USHORT_MAX = 65535;
    unsigned short int minNumber = USHORT_MAX;
    unsigned short int maxNumber = 0;
    int inputNumber  = 0;

    do{
        inputNumber = readInput(USHORT_MAX);
        if(minNumber > inputNumber && inputNumber >= 0){
            minNumber = inputNumber;
        }
        else if(maxNumber < inputNumber){
            maxNumber = inputNumber;
        }
    }
    while (inputNumber >= 0);
    
    unsigned short answer = maxNumber - minNumber;
    
    if(maxNumber == 0 || minNumber == USHORT_MAX){
        cout << "You entered less than 2 numbers!" << endl;
    }
    else{
        cout << "The difference between the largest and the smallest is " << answer << endl;
    }
    return 0;
}
