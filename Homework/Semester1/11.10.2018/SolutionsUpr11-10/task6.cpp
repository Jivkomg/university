#include<iostream>
using namespace std;
int main()
{
	 int number;
	 int position;

	 cout << "Number: ";
	 cin >> number;

	 cout << "Position: ";
	 cin >> position;

	 int mask = 1 << position;
	 int bit = (number & mask) >> position;

	 cout << "The value of the bit at position " << position << " in " << number << " is " << bit << endl;

	 return 0;
}
