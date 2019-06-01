/**
 *
 * Solution to homework task 4
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2018/2019
 *
 * @author Zhivko Georgiev
 * @idnumber 62304
 * @task 4
 * @compiler GCC
 *
 */

#include <iostream>
using namespace std;
//validation
int readInput()
{
    int input = -1;
    bool valid = false;
    do
    {
        cin >> input;
        if (cin.good())
        {
            valid = true;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid input, please enter again." << endl;
        }
    } while (!valid);
    
    return (input);
}

int main(int argc, const char * argv[]) {
    cout << "Enter the length of the square: ";
    int length = 0;
    length = readInput();
    
    cout << "Enter a symbol: ";
    char symbol;
    cin >> symbol;
    
    if(length > 13 || length < 0){
        cout << "A square with that length cannot be printed on the standart console"<< endl;
        return 1;
    }
    
    int spaces = 38;
    //row spaces
    for(int i = 0; i < (25 - 2 * length - 1 ) / 2; i++){
        cout << endl;
    }
    //upper half
    for(int i = 1; i <= length; i++){
        for(int s = 0; s < spaces; s++){
            cout << " ";
        }
        for(int j = 1; j <= i*2 -1; j++){
            cout << symbol;
        }
        spaces--;
        cout << endl;
    }
    
    //lower half
    for(int i = length - 1; i > 0; i--){
        for(int s = spaces + 1; s >=0 ; s--){
            cout << " ";
        }
        for(int j = i * 2 - 1; j >= 1; j--){
            cout << symbol;
        }
        spaces++;
        cout << endl;
    }
    //row spaces
    for(int i = 0; i < (25 - 2 * length - 1) / 2; i++){
        cout << endl;
    }
    return 0;
}
