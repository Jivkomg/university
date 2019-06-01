#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x1, y1, x2, y2;
    cout << "Enter x1 and y1:" << endl;
    cin >> x1 >> y1;
    cout << "Enter x2 and y2:" << endl;
    cin >> x2 >> y2;
    cout << "Distance is: "<< round(sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) * 100) / 100 << endl;

    return 0;
}
