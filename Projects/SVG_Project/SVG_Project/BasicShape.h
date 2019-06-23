//
//  BasicShape.h
//  SVG_Project
//
//  Created by Zhivko Georgiev on 29.05.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef BasicShape_h
#define BasicShape_h
#include "math.h"
//#include <string>
#include <iostream>
//#include "XMLParser.h"
#include <vector>

//    Line has 2 points, Rectangle and Circle 1
struct Point{
    int x;
    int y;
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
//    double distance(const Point& p){
//        int dx = this->x - p.x;
//        int dy = this->y - p.y;
//        return sqrt(dx * dx + dy * dy);
//    }
    double getDistanceToPoint(const Point& p) const{
        int dx = this->x - p.x;
        int dy = this->y - p.y;
        return sqrt(dx * dx +  dy * dy);
    }
};
//    Base class and all other shapes derive from it
class BasicShape{
protected:
//    All figures have colour and stroke width
    std::string fillColour;
    int strokeWidth;
//    virtual void deserializeWithParameters(const std::string&, const std::string&) = 0;
public:
    BasicShape();
    BasicShape(std::string, int);
    const std::string getFill() const;
    const int getStrokeWidth() const;
    virtual const std::string getType() const = 0;

//    virtual void deserialize(std::istream&) override;
//    virtual void serialize(std::ostream&) const = 0;

    void setFill(const std::string&);
    void setStrokeWidth(const int&);
    
    // all figures are translated and printed differently
    virtual void translate(const int&, const int&) = 0;
    virtual void print() const = 0;
    
//    Additional methods for calculating within function
    virtual const Point getLeft() const = 0;
    virtual const Point getRight() const = 0;
    virtual const Point getTop() const = 0;
    virtual const Point getBottom() const = 0;
    
    virtual ~BasicShape(){};
};
//std::vector<std::string> split(const std::string& str,char delimiter)
//{
//    std::vector<std::string> result;
//    long count = std::count(str.begin(), str.end(), delimiter);
//    long currIndex = 0;
//    long indexOfDelimiter = str.find(delimiter);
//    for (int i = 0; i < count; i++)
//    {
//        result.push_back(std::string(str.substr(currIndex, indexOfDelimiter - currIndex)));
//        currIndex = indexOfDelimiter + 1;
//        indexOfDelimiter = str.find(delimiter, currIndex);
//    }
//    result.push_back(std::string(str.substr(currIndex)));
//    
//    //Remove empty entries
//    for (long i = result.size() - 1; i >= 0; i--)
//    {
//        if (result[i] == std::string())
//        {
//            result.erase(result.begin() + i);
//        }
//    }
//    return result;
//}


#endif /* BasicShape_h */
