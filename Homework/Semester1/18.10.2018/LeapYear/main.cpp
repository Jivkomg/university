#include <iostream>

using namespace std;


int main()
{
	int year;
	cout << "Enter a year\n";
	cin >> year;
	if (year % 4 == 0) {
		if (year % 100 == 0 && year % 400 != 0) {
			cout << "Not a leap year \n";
		}
		else {
			cout << "Leap year!\n";
		}
	}
	else {
		cout << "Not a leap year \n";
	}
    return 0;
}






