//
//  Circle.cpp
//  SVG_Project
//
//  Created by Zhivko Georgiev on 4.06.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include "Circle.h"
#include <string>
Circle::Circle():centre(0,0), radius(0), BasicShape(){
}

Circle::Circle(const Point& p, const int& radius, const std::string& fill, const int& strokeWidth):
    centre(p.x, p.y), radius(radius), BasicShape(fill, strokeWidth) {
}

const Point Circle::getCentre() const {
    return centre;
}

const int Circle::getRadius() const { 
    return radius;
}

void Circle::setCentre(const Point& p) {
    this->centre.x = p.x;
    this->centre.y = p.y;
}

void Circle::setRadius(const int radius) {
    this->radius = radius;
}

void Circle::translate(const int dx, const int dy) {
    this->centre.x += dx;
    this->centre.y += dy;
}

const std::string Circle::getType() const { 
    return "circle";
}

void Circle::print() const { 
    std::cout << this->getType() << " " << centre.x << " "
    << centre.y << " " << radius << " " << this->getFill() << std::endl;
}

const Point Circle::getLeft() const { 
    return Point(centre.x - radius, centre.y);
}

const Point Circle::getRight() const { 
    return Point(centre.x + radius, centre.y);
}

const Point Circle::getTop() const { 
    return Point(centre.x, centre.y  + radius);
}

const Point Circle::getBottom() const { 
    return Point(centre.x, centre.y - radius);
}




