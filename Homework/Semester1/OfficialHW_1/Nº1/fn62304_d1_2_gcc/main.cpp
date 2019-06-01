#include <iostream>
using namespace std;

int main()
{
    int number = 0;
    int digit = 0;
    cin >> number;
    cin >> digit;
    int cnt = 0;
    while(number > 0)
    {
        if(number % 10 == digit)
        {
            cnt++;
        }
        number /= 10;
    }
	cout << cnt << endl;
    return 0;
}s
