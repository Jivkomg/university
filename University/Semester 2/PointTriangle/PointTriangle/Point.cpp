//
//  main.cpp
//  PointTriangle
//
//  Created by Zhivko Georgiev on 7.03.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
#include "Point.h"

void Point::setX(){
    std::cin >> x;
}
void Point::setY(){
    std::cin >> y;
}

void Point::printPoint() const{
    std::cout << "(" << x << ", " << y << ")";
}
double Point::getX() const{
    return x;
}
double Point::getY() const{
    return y;
}
double Point::distanceBetweenTwoPoints(const Point& a) const{
    return sqrt((x - a.x) * (x - a.x) + (x - a.y) * (x - a.y));
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
