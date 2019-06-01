#include <iostream>
using namespace std;
int main() {
    int year;
    cin >> year;
    if(year % 4 == 0){
        if(year % 100){
            if(year % 400){
                cout << "It's a leap year" << endl;   
            }
            else{
                cout << "It's NOT a leap year" << endl;
            }
        }
        else cout << "It's a leap year" << endl;
     }
     else cout <<"It's NOT a leap year" << endl;
}