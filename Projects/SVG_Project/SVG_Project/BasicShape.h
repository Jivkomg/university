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
#include <iostream>
#include <vector>

//    Line has 2 points, Rectangle and Circle 1
struct Point{
    int x;
    int y;
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
	int getX() const{
		return x;
	}
	int getY() const {
		return y;
	}
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

    void setFill(const std::string&);
    void setStrokeWidth(const int);
    
    // all figures are translated and printed differently
    virtual void translate(const int, const int) = 0;
    virtual void print() const = 0;
    
//    Additional methods for calculating within function
    virtual const Point getLeft() const = 0;
    virtual const Point getRight() const = 0;
    virtual const Point getTop() const = 0;
    virtual const Point getBottom() const = 0;
    
    virtual ~BasicShape(){};
};

#endif /* BasicShape_h */
