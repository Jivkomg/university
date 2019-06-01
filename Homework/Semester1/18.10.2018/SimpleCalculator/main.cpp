#include <iostream>
using namespace std;

int main()
{
    double num1, num2;
    cout << "Enter first number: "<< endl;
    cin >> num1;
    cout << "Enter a second number: " << endl;
    cin >> num2;

    char operation;
    cout << "Choose an operation \n (+  -   *   :)" << endl;
    cin >> operation;
    if(operation == '+'){
        cout << "Num1 + Num2 = " << num1 + num2 << endl;
    }
    else if(operation == '-'){
        cout << "Num1 + Num2 = " << num1 - num2 << endl;
    }
    else if(operation == '*'){
        cout << "Num1 + Num2 = " << num1 * num2 << endl;
    }
    else if(operation == ':'){
        if(num2 == 0){
            cout << "You can't devide by zero!" << endl;
        }
        else{
            cout << "Num1 + Num2 = " << num1 / num2 << endl;
        }
    }
    else {
        cout << "This is not a valid operation!" << endl;
    }

    return 0;
}
