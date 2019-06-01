//
//  Triangle.cpp
//  PointTriangle
//
//  Created by Zhivko Georgiev on 7.03.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Triangle.h"

void Triangle::setPoint(const Point& a, const Point& b, const Point& c){
    this->A = a;
    this->B = b;
    this->C = c;
    
    this->sideA = b.distanceBetweenTwoPoints(c);
    this->sideB = a.distanceBetweenTwoPoints(c);
    this->sideC = a.distanceBetweenTwoPoints(b);
}

void Triangle::typeOfTriangle() const{
    if(sideB == sideA && sideA == sideC){
        std::cout << "Equal sides" << std::endl;
        return;
    }
    if(sideC == sideB || sideC == sideA || sideA == sideB){
        std::cout << "Two equal sides" << std::endl;
    }
    else {
        std::cout << "No equal sides" << std::endl;
    }
}

bool Triangle::isValidTriangle() const{
    return (sideB + sideA > sideC || sideC + sideB > sideA || sideC + sideA > sideB);
}
