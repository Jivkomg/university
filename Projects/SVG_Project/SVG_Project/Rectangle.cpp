//
//  Rectangle.cpp
//  SVG_Project
//
//  Created by Zhivko Georgiev on 2.06.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include "Rectangle.h"


Rectangle::Rectangle(): p(0,0), width(0), height(0), BasicShape() {
}

Rectangle::Rectangle(Point p, const int& width, const int& height, const std::string& fill, const int& strokeWidth):
    p(p.x, p.y), width(width), height(height), BasicShape(fill, strokeWidth){
}

void Rectangle::translate(const int& dx, const int& dy) {
    p.x += dx;
    p.y += dy;
}

void Rectangle::setWidth(const int& width) {
    this->width = width;
}

void Rectangle::setHeight(const int& height) {
    this->height = height;
}

void Rectangle::setPoint(const Point& p) {
    this->p.x = p.x;
    this->p.y = p.y;
}

const int Rectangle::getWidth() const {
    return width;
}

const int Rectangle::getHeight() const {
    return height;
}

const Point Rectangle::getPoint() const { 
    return p;
}
