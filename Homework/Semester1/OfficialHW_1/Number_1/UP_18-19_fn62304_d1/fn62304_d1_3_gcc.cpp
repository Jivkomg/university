/**
 *
 * Solution to homework task 3
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
    do
    {
        cin >> input;
        if (cin.good())
        {
            valid = true;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid input, please enter again." << endl;
        }
    } while (!valid);
    
    return (input);
}

int main()
{
    //4-bit calculator
    int firstNum = 0, secondNum = 0, operation = 0;
    cout << "Enter the first operand:" << endl;
    firstNum = readInput();
    cout << "Enter the second operand:" << endl;
    secondNum = readInput();
    cout << "Enter the operation 0(+) 1(-) 2(*) 3(:):" << endl;
    operation = readInput();
    
    
    //mod = 2^4 = 16
    const unsigned short int MOD = 16;
    int answer = 0;
    
    //validation
    if((firstNum < 0 || firstNum > 15) || (secondNum < 0 || secondNum > 15)){
        cout << "Wrong input" << endl;
        return 1;
    }
    switch(operation)
    {
        case 0 :
            answer = (firstNum + secondNum) % MOD;
            break;
            
        case 1 :
            answer = (firstNum - secondNum) % MOD;
            if (answer < 0){
                answer += MOD;
            }
            break;
        case 2 :
            answer = (firstNum * secondNum) % MOD;
            break;
        case 3:
            if(secondNum == 0){
                //You can't divide by zero
                cout << "Wrong input" << endl;
                return 1;
            }
            else {
                answer = firstNum / secondNum;
            }
            break;
        default: cout << "You enter an invalid operation" << endl; return 1;
    }
    cout << "The result is: "<< answer << endl;
    return 0;
}
