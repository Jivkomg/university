#include <iostream>
using namespace std;

int main()
{
	int number;
	cin >> number;
	int guess;
	int cnt = 0;
	do {
		cin >> guess;
		if (guess > number) {
			cout << "Your guess is bigger than the number\n";
			cnt++;
		}
		else if (guess < number) {
			cout << "Your guess is less than the number\n";
			cnt++;
		}
	} while (guess != number);
	cout << "You guessed it after " << cnt << " tries\n";;

    return 0;
}
