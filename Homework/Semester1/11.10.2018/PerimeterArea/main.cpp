#include <iostream>

using namespace std;

int main()
{
    double a, b;
    cout << "Please enter the first side of the triangle: " << endl;
    cin >> a;
    cout << "Please enter the second side of the triangle: " << endl;
    cin >> b;

    cout << "The perimeter is: "<< 2 * (a + b) << endl;
    cout << "The area is: "<< a * b << endl;

    return 0;
}
