// Task2.cpp : Defines the entry point for the console application.
//Zhivko's program

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>;
#include <cstdio>;
using namespace std;

int main()
{
	/*
	int number1, number2;
	cin >> number1;
	cin.ignore(500, '\n');
	cin >> number2;
	cout << "Number1 + Number2 is : " << number1 + number2 << endl;
	cout << "\n";
	cout << '\n';
	double f = 3.14159;
	cout << setprecision(5) << f << '\n';
	cout << setprecision(9) << f << '\n';
	cout << fixed << '\n';
	cout << setprecision(5) << f << '\n';
	cout << setprecision(9) << f << '\n';
	
	int a = 1234;
	cout << setfill('x') << setw(16) << a << endl;
	//cout << setfill('x');
	
	string name;
	cout << "What is your name?\n";
	getline(cin, name);
	cout << "Your name is " << name << endl;
	
	string text;
	getline(cin, text, '^');
	cout << text << endl;
	*/
	unsigned short int number = 45;
	cout << dec << number << endl;
	cout << hex<< number << endl;
	cout << oct << number << endl;

	cout << "The square root of "<< number <<" is "<<ceil(sqrt(number))<<"   <3" << endl;
	cout << pow(5,3)<<endl;

	printf("The square root of %u is %f    <3\n", number, sqrt(number));
	
	return 0;


}

