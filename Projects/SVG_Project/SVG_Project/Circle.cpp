//
//  Circle.cpp
//  SVG_Project
//
//  Created by Zhivko Georgiev on 4.06.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include "Circle.h"

Circle::Circle():p(0,0), radius(0), BasicShape(){
}

Circle::Circle(const Point& p, const int& radius, const std::string& fill, const int& strokeWidth):
    p(p.x, p.y), radius(radius), BasicShape(fill, strokeWidth) {
}

const Point Circle::getPoint() const { 
    return p;
}

const int Circle::getRadius() const { 
    return radius;
}

void Circle::setPoint(const Point& p) {
    this->p.x = p.x;
    this->p.y = p.y;
}

void Circle::setRadius(const int& radius) {
    this->radius = radius;
}
