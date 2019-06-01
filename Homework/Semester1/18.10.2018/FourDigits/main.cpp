#include <iostream>

using namespace std;

int main()
{
    int a = 0;
    cin >> a;
    int d1 = a / 1000;
    int d2 = (a / 100) % 10;
    int d3 = (a % 100) / 10;
    int d4 = a % 10;
    int num1 = d1 * 10 + d4;
    int num2 = d2 * 10 + d3;
    if(num1 > num2){
        cout << num1 << " < " << num2;
    }
    else if(num1 == num2){
        cout << num1 << " = " << num2;
    }
    else {
        cout << num1 << " > " << num2;
    }
    return 0;
}
