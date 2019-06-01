//
//  main.cpp
//  Task1
//
//  Created by Zhivko Georgiev on 7.02.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
struct Point{
    double x;
    double y;
};
double toPower2(double a){
    return a * a;
}
double distance(Point p1, Point p2){
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
void swapIf(double& a, double& b){
    if(a != b){
        double tmp = a;
        a = b;
        b = tmp;
    }
}
bool rightAngle(Point p1, Point p2, Point p3){
    if(p1.x == p2.x && p2.x == p3.x){
        return false;
    }
    if(p1.y == p2.y && p2.y == p3.y){
        return false;
    }
    
    double dist12 = distance(p1, p2);
    double dist13 = distance(p1, p3);
    double dist23 = distance(p2, p3);
    
    double maxDist = dist12;
    double distOne = dist13;
    double distTwo = dist23;
    
    if(maxDist < distOne){
        swapIf(maxDist, distOne);
    }
    if(maxDist < distTwo){
        swapIf(maxDist, distTwo);
    }
    if(toPower2(maxDist) == (toPower2(distTwo) + toPower2(distOne))){
        cout << "yes";
        return true;
    }
    cout << " No ";
     return false;
}
int main() {
    Point p1;
    p1.x = -3;
    p1.y = -1;
    Point p2;
    p2.x = 2;
    p2.y = -1;
    Point p3;
    p3.x = 2;
    p3.y = 3;
    cout << rightAngle(p1, p2, p3);
    return 0;
}
