/**
 *
 * Solution to homework task 5
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2018/2019
 *
 * @author Zhivko Georgiev
 * @idnumber 62304
 * @task 5
 * @compiler GCC
 *
 */


#include <iostream>
#include <math.h>
using namespace std;
//validation
double readInput()
{
    double input = -1;
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
//this method is needed because of the double's precision
bool equals(double x, double y){
    double difference = (x - y) > 0 ? x - y: y - x;
    double precision = 0.0001;
    if(difference <= precision){
        return true;
    }
    else {
        return false;
    }
}
        

int main(int argc, const char * argv[]) {
    double x0 = 0.0;
    double y0 = 0.0;
    cout << "Enter the x coordinate of the point: " << endl;
    x0 = readInput();
    cout <<"Enter the y coordinate of the point: " << endl;
    y0 = readInput();
    
    const double WHOLE_CIRCLE_RAD = 6.0;
    const double BIG_CIRCLES_RAD = 3.0;
    const double SMALL_CIRCLES_RAD = 1.0;
    
    //distance from point (0;0)
    double wholeCircleDistance = sqrt(x0 * x0 + y0 * y0);
    //distance from point (0;3)
    double upperCenterDistance = sqrt(x0 * x0 + (y0 - 3) * (y0 - 3));
    //distance from point (0;-3)
    double lowerCenterDistance = sqrt(x0 * x0 + (y0 + 3) * (y0 + 3));
    
    // whole circle
    if(wholeCircleDistance < WHOLE_CIRCLE_RAD){
        //big white circle
        if(upperCenterDistance < BIG_CIRCLES_RAD){
            //small white line
            if(equals(upperCenterDistance, SMALL_CIRCLES_RAD)){
                cout << "Undefined" << endl;
                return 0;
            }
            //small black circle
            else if(upperCenterDistance < SMALL_CIRCLES_RAD){
                cout << "Black" << endl;
                return 0;
            }
            else cout << "White" << endl;
            return 0;
        }
        //big white circle line
        else if(equals(upperCenterDistance, BIG_CIRCLES_RAD)){
            if(x0 < 0){
                cout << "White" << endl;
                return 0;
            }
            else{
                cout << "Undefined" << endl;
                return 0;
            }
        }
        
        //big black circle
        else if(lowerCenterDistance < BIG_CIRCLES_RAD){
            //small white line
            if(equals(lowerCenterDistance, SMALL_CIRCLES_RAD)){
                cout << "Undefined" << endl;
                return 0;
            }
            //small white circle
            else if(lowerCenterDistance < SMALL_CIRCLES_RAD){
                cout << "White" << endl;
                return 0;
            }
            else cout << "Black" << endl;
            return 0;
        }
        //big black circle line
        else if(equals(lowerCenterDistance, BIG_CIRCLES_RAD)){
            if(x0 > 0){
                cout << "Black" << endl;
                return 0;
            }
            else {
                cout << "Undefined" << endl;
                return 0;
            }
        }
        //white leftout
        if(x0 < 0 && upperCenterDistance > SMALL_CIRCLES_RAD && lowerCenterDistance > BIG_CIRCLES_RAD){
            cout << "White" << endl;
            return 0;
        }
        //black leftout
        if(x0 > 0 && lowerCenterDistance > SMALL_CIRCLES_RAD && upperCenterDistance > BIG_CIRCLES_RAD){
            cout << "Black" << endl;
            return 0;
        }
    }
    //whole circle line
    else if (equals(wholeCircleDistance,WHOLE_CIRCLE_RAD)){
        cout << "Undefined" << endl;
        return 0;
    }
    //outside of the whole circle
    else cout << "Outside" << endl;
//    cout << endl;
    return 0;
}

