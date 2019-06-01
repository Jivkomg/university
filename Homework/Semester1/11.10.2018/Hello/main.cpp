#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    cout << "What's your name mate?" << endl;
    getline(cin, input);
    cout << "Hello " << input << endl;
    return 0;
}
