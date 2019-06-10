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
    Point p;
    int width;
    int height;
public:
    Rectangle();
    Rectangle(Point, const int&, const int&, const std::string&, const int&);
    void translate(const int& dx, const int& dy) override;
    
    void setWidth(const int&);
    void setHeight(const int&);
    void setPoint(const Point&);
    const int getWidth() const;
    const int getHeight() const;
    const Point getPoint() const;
};

#endif /* Rectangle_h */
