#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    string number;
    cout << "Enter your number: " << endl;
    cin >> number;
    cout << "Hidden number: " << setfill('X') << setw(13) << number[12] << number[13] << number[14] << number[15];
    return 0;
}
