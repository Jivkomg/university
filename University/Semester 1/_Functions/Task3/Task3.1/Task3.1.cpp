// Task3.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	//validation
	//int number;
	//cout << "Enter a number larger than 20 \n";
	//cin >> number;
	//if (number <= 20) {
	//	cout << "Learn to read idod!\n";
	//	return 1;
	//}
	//cout << number * number << endl;
	//--------------------------------------------------------------------------------------------------------------------------------
	//odd or even
	//int number;
	//cout << "Enter a number: \n";
	//cin >> number;
	//if (number % 2 == 0) {
	//	cout << "Even" << endl;
	//}
	//else {
	//	cout << "Odd" << endl;
	//}
	//--------------------------------------------------------------------------------------------------------------------------------
	//number of digits
	//int number;
	//cout << "Enter a number: ";
	//cin >> number;
	//if (number > 0 && number < 10) {
	//	cout << "Number has one digit \n";
	//}
	//else if (number >= 10 && number < 100) {
	//	cout << "Number has two digit \n";
	//}
	//else if (number >= 100 && number < 1000) {
	//	cout << "Number has three digit \n";
	//}
	//else {
	//	cout << "Learn to read idiot!\n";
	//}
	//--------------------------------------------------------------------------------------------------------------------------------
	
	//int number1;
	//int number2;
	//
	//cout << "Enter a number 1: \n";
	//cin >> number1;
	//
	//cout << "Enter a number 2: \n";
	//cin >> number2;
	//
	//if (number2 = 0 & number1 / number2 < 3) {
	//	cout << "Result is less than 3!" << endl;
	//}

	//int number;
	//cin >> number;
	//
	//bool dMoreThanZero = (number > 0 && number < 100);
	//
	//if (dMoreThanZero) {
	//	cout << "<3" << endl;
	//}
	//--------------------------------------------------------------------------------------------------------------------------------
	//1 2 3
	//int number;
	//cin >> number;
	//
	//switch (number) {
	//case 1: 
	//	cout << "One\n";
	//	break;
	//
	//case 2:
	//	cout << "Two\n";
	//	break;
	//
	//case 3:
	//	cout << "Three\n";
	//	break;
	//case 4:
	//
	//	cout << "Four\n";
	//	break;
	//
	//default:
	//	cout << "Not 1, 2, 3!\n";
	//	break;
	//}

	int number;
	cin >> number;
	char sign = (number < 0) ? '-' : '+';
	cout << sign << endl;

	return 0;

}



