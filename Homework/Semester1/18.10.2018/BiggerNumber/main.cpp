#include <iostream>

using namespace std;

int main()
{
    int a = 0, b = 0;
    cout << "Enter two different numbers:"<< endl;
    cin >> a >> b;
    if(a == b){
        cout << "They are equal";
        return 0;
    }
    int biggerNum = (a > b)? a : b;
    cout << "The bigger number is: " << biggerNum;
    return 0;
}
