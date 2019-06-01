#include <iostream>

using namespace std;

int main()
{
    int number, position;

    cout << "Number: ";
    cin >> number;
    cout << "Position: ";
    cin >> position;

    int mask = 1 << position;
    int bit = (mask & number) >> position;

    cout << bit << endl;

    return 0;
}
