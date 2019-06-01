#include <iostream>

using namespace std;

int main()
{
	char input;
	cout << "Enter a letter\n";
	cin >> input;
	//ascii
	if ((input >= 65 && input <= 90) || (input >= 97 && input < 122)) {
		cout << "It's a latin letter!\n";
		if (input == 'a' || input == 'o' || input == 'i' || input == 'u' || input == 'y' || input == 'e'
			|| input == 'A' || input == 'O' || input == 'I' || input == 'U' || input == 'Y' || input == 'E')
			cout << "It's also a vowel one!\n";
		else {
			cout << "It's also consonant one!\n";
		}
	}
	else {
		cout << "It's NOT a latin letter!\n";
	}

    return 0;
}

