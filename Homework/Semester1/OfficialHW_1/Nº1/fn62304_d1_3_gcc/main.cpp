#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int firstNum = 0, secondNum = 0, operation = 0;
    cin >> firstNum >> secondNum >> operation;
    int answer;
    switch(operation)
    {
        case 0 :
            if(firstNum + secondNum > 15){
                answer = abs(16 - (firstNum + secondNum));
            }
            else {
                answer = firstNum + secondNum;
            }
            break;

        case 1 :
            if(firstNum - secondNum < 0){
                answer = 16 + (firstNum - secondNum);
            }
            else {
                answer = firstNum - secondNum;
            }
            break;
        case 2 :
            if(firstNum * secondNum > 15){
                answer = (firstNum * secondNum) % 16;
            }
            else {
                answer = firstNum * secondNum;
            }
            break;
        case 3:
            answer = firstNum / secondNum;
            break;

    }

    cout << answer << endl;
    return 0;
}
