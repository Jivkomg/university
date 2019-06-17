//
//  Rectangle.cpp
//  SVG_Project
//
//  Created by Zhivko Georgiev on 2.06.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include "Rectangle.h"


Rectangle::Rectangle(): leftMostPoint(0,0), width(0), height(0), BasicShape() {
}

Rectangle::Rectangle(Point p, const int& width, const int& height, const std::string& fill, const int& strokeWidth):
    leftMostPoint(p), width(width), height(height), BasicShape(fill, strokeWidth){
}

void Rectangle::translate(const int& dx, const int& dy) {
    leftMostPoint.x += dx;
    leftMostPoint.y += dy;
}

void Rectangle::setWidth(const int& width) {
    this->width = width;
}

void Rectangle::setHeight(const int& height) {
    this->height = height;
}

void Rectangle::setLeftMostPoint(const Point& p) {
    this->leftMostPoint.x = p.x;
    this->leftMostPoint.y = p.y;
}

const int Rectangle::getWidth() const {
    return width;
}

const int Rectangle::getHeight() const {
    return height;
}

const Point Rectangle::getLeftMostPoint() const { 
    return leftMostPoint;
}

const std::string Rectangle::getType() const { 
    return "rectangle";
}

void Rectangle::print() const { 
    std::cout << this->getType() << " " << leftMostPoint.x << " "
        << leftMostPoint.y << " " << getFill();
}

