//
//  Rectangle.h
//  SVG_Project
//
//  Created by Zhivko Georgiev on 2.06.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef Rectangle_h
#define Rectangle_h
#include "BasicShape.h"
class Rectangle: public BasicShape{
private:
    Point leftMostPoint;
    int width;
    int height;
public:
    Rectangle();
    Rectangle(Point, const int&, const int&, const std::string&, const int&);
    void translate(const int& dx, const int& dy) override;
    
    void setWidth(const int&);
    void setHeight(const int&);
    void setLeftMostPoint(const Point&);
    const int getWidth() const;
    const int getHeight() const;
    const Point getLeftMostPoint() const;
    
    const std::string getType() const override;
    void print() const override;

};
#endif /* Rectangle_h */
