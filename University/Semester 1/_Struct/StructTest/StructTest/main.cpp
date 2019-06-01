//
//  main.cpp
//  StructTest
//
//  Created by Zhivko Georgiev on 3.01.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
struct Point{
    double x;
    double y;

    Point(){
        x = 0;
        y = 0;
    }

    Point(double x, double y){
        this->x = x;
        this->y = y;

    }
    double distTo (Point otherPoint){
        return sqrt((x -  otherPoint.x) * (x - otherPoint.x) + (y - otherPoint.y) * (y - otherPoint.y));
    }

};


double dist (Point p1, Point p2){
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
int main(int argc, const char * argv[]) {
    Point point1;
    Point point2;
    cin >> point1.x >> point1.y;
    cin >> point2.x >> point2.y;

    cout << dist(point1, point2) << endl;
    cout << point1.distTo(point2) << endl;
    
    Point* ptr_point = &point2;
    cout << ptr_point->distTo(point2) << endl;
   
    Point point(5, 3);
    return 0;
    
    
}
