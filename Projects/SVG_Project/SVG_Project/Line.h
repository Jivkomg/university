//
//  Line.h
//  SVG_Project
//
//  Created by Zhivko Georgiev on 29.05.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef Line_h
#define Line_h

#include "BasicShape.h"
class Line: public BasicShape{
private:
    Point p1;
    Point p2;
//    int width;
public:
    Line();
    Line(const Point&, const Point&, const std::string&, const int&);
    void translate(const int&, const int&) override;
  
    void setPoint1(const Point&);
    void setPoint2(const Point&);
//    void setWidth(int);
    
    const Point getPoint1() const;
    const Point getPoint2() const;
//    const int getWidth() const;
};

#endif /* Line_h */
