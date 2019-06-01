#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n, m;
    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;

    for(int i = 1; i <= n*m; i++){
        cout << setw(4) << i;
        if(i % n == 0){
            cout << '\n';
        }
    }
    return 0;
}
