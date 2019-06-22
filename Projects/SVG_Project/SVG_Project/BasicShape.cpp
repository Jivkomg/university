//
//  BasicShape.cpp
//  SVG_Project
//
//  Created by Zhivko Georgiev on 29.05.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include "BasicShape.h"
//#include <string>
//#include <iostream>
//#include <vector>
#include <sstream>

void eraseAllSubStr(std::string& mainStr, const std::string& toErase)
{
    size_t pos = std::string::npos;
//    search for the substring in string in a loop untill nothing is found
    while ((pos  = mainStr.find(toErase))!= std::string::npos)
    {
//        if found then erase it from string
        mainStr.erase(pos, toErase.length());
    }
}

BasicShape::BasicShape():fillColour("white"), strokeWidth(0)  {
}

BasicShape::BasicShape(std::string fill, int strokeWidth): fillColour(fill), strokeWidth(strokeWidth) {
}

void BasicShape::deserialize(std::istream& is) {
    char c;
    is.get(c);
    std::string str;
    while (c != '>')
    {
        str += c;
        is.get(c);
    }
    eraseAllSubStr(str, "\"");
    eraseAllSubStr(str, "\"");
    
//    str.erase(std::remove(str.begin(), str.end(), "\""), str.end());
//    str.erase(std::remove(str.begin(), str.end(), "\\"), str.end());
    str.erase(std::remove(str.begin(), str.end(), '/'), str.end());
//    str.erase(std::remove(str.begin(), str.end(), "\n"), str.end());
    eraseAllSubStr(str, "\n");

    std::vector<std::string> parameters = split(str, ' ');
    for (int i = 0; i < parameters.size(); i++)
    {
        std::vector<std::string> temp = split(parameters[i], '=');
        this->deserializeWithParameters(temp[0], temp[1]);
    }
}

const std::string BasicShape::getFill() const { 
    return fillColour;
}

const int BasicShape::getStrokeWidth() const { 
    return strokeWidth;
}

void BasicShape::setFill(const std::string& fill) {
    this->fillColour = fill;
}

void BasicShape::setStrokeWidth(const int& strokeWidth) {
    this->strokeWidth = strokeWidth;
}




