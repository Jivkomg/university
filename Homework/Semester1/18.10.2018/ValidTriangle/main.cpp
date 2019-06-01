#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if(a <= 0 || b <= 0 || c <= 0){
        cout << "Not a triangle!\n";
        return 0;
    }
    if((a + b) > c && (a + c) > b && (c + b) > a){
        cout << "Valid triangle!\n";
    }
    else cout << "Not a triangle!\n";
    return 0;
}
