//
//  BasicShape.cpp
//  SVG_Project
//
//  Created by Zhivko Georgiev on 29.05.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include "BasicShape.h"

BasicShape::BasicShape():fill("white"), strokeWidth(0)  {
}

BasicShape::BasicShape(std::string fill, int strokeWidth): fill(fill), strokeWidth(strokeWidth) {
}

const std::string BasicShape::getFill() const { 
    return fill;
}

const int BasicShape::getStrokeWidth() const { 
    return strokeWidth;
}

void BasicShape::setFill(const std::string& fill) {
    this->fill = fill;
}

void BasicShape::setStrokeWidth(const int& strokeWidth) {
    this->strokeWidth = strokeWidth;
}
