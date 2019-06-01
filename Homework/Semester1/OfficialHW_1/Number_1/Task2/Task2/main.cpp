/**
 *
 * Solution to homework task 2
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2018/2019
 *
 * @author Zhivko Georgiev
 * @idnumber 62304
 * @task 2
 * @compiler GCC
 *
 */
#include <iostream>
using namespace std;
//validation
long long readInput(long long lowBound, long long uppBound)
{
    long long input = -1;
    bool valid = false;
    do
    {
        cin >> input;
        if (cin.good() && (input <= uppBound) && (input >= lowBound))
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

int main()
{
    cout << "Enter a number: " << endl;
    //2^32 - 1 = 4294967295
    long long const MAX_LONG = 4294967295;
    long long const MIN_LONG = -4294967296;
    
    long long number = readInput(MIN_LONG,MAX_LONG);
   
    cout << "Enter a digit: " << endl;
    //validation that this is infact a digit
    int digit = (int)readInput(0,9);
    //counter - how many times the digit is in the number
    int cnt = 0;
    
    //the algorithm works for positive numbers
    number = (number > 0) ? number : -number;
    do{
        if(number % 10 == digit)
        {
            cnt++;
        }
        number /= 10;
    }
    while(number != 0);
    
    cout << "The digit is in the number "<< cnt <<" times."<< endl;
    return 0;
}
