// Task3.cpp : Defines the entry point for the console application.
//
&
#include <iostream>
using namespace std;

int main()
{
	int number;
	cout << "Enter a number larger than 20 \n";
	cin >> number;
	if (number <= 20) {
		cout << "Learn to read idod!\n";
		return 1;
	}
	
	cout << number * number << endl;
    return 0;
}

