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
#include <string>
#include <iostream>
struct Point{
    int x;
    int y;
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
    double distance(const Point& p){
        int dx = this->x - p.x;
        int dy = this->y - p.y;
        return sqrt(dx * dx + dy * dy);
    }
};
class BasicShape{
protected:
    std::string fillColour;
    int strokeWidth;
    //point
public:
    BasicShape();
    BasicShape(std::string, int);
    const std::string getFill() const;
    const int getStrokeWidth() const;
    
    void setFill(const std::string&);
    void setStrokeWidth(const int&);
    virtual void translate(const int&, const int&) = 0;
    virtual const std::string getType() const = 0;
    virtual void print() const = 0;
    
    
};

#endif /* BasicShape_h */
