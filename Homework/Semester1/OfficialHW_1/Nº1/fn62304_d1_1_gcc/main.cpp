#include <iostream>

using namespace std;

int main()
{
    int minNumber = INT_MAX;
    int maxNumber = 0;
    int inputNumber  = 0;

    do{
        cin >> inputNumber;
        if(minNumber > inputNumber && sinputNumber >= 0)
        {
            minNumber = inputNumber;
        }
        else if(maxNumber < inputNumber)
        {
            maxNumber = inputNumber;
        }
    }
    while (inputNumber >= 0);

    int answer = maxNumber - minNumber;
    cout << answer << endl;
    return 0;
}
