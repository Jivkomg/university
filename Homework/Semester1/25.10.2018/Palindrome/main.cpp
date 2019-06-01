#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input = "ala";
	cin >> input;Ba
	int j = input.length() - 1;
	for (int i = 0; i < (input.length() / 2); i++, j--) {
		if (input[i] != input[j]) {
			cout << "NOT a palindrome!\n";
			return 0;
		}
	}
	cout << "It's a palindrome!" << endl;
    return 0;
}



