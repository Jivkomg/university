//
//  Line.cpp
//  SVG_Project
//
//  Created by Zhivko Georgiev on 2.06.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include "Line.h"


Line::Line(): p1(0,0), p2(0,0), BasicShape() {
}

Line::Line(const Point& p1, const Point& p2, const std::string& fill, const int& strokeWidth):
        p1(p1.x,p1.y), p2(p2.x,p2.y), BasicShape(fill, strokeWidth){
}

void Line::translate(const int& dx, const int& dy) {
    p1.x += dx;
    p2.x += dx;
    p1.y += dy;
    p2.y += dy;
}

void Line::setPoint1(const Point& p1) {
    this->p1.x = p1.x;
    this->p1.y = p1.y;
}

void Line::setPoint2(const Point& p2) {
    this->p2.x = p2.x;
    this->p2.y = p2.y;
}

const Point Line::getPoint1() const {
    return this->p1;
}

const Point Line::getPoint2() const { 
    return this->p2;
}

const std::string Line::getType() const {
    return "line";
}

void Line::print() const { 
    std::cout << this->getType() << " "<< p1.x << " " << p1.y << " "
        << p2.x << " " << p2.y << this->getFill();
}
