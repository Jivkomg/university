#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int number;
	cin >> number;
	int powNumber = number * number;
	int answer = 0;
	for (int i = log10((double)abs(powNumber)); i >= 0; i--) {
		answer += (powNumber % 10) * pow(10, i);
		powNumber /= 10;
	}
	cout << answer << endl;
    return 0;
}
