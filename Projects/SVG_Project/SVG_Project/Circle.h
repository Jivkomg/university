//
//  Circle.h
//  SVG_Project
//
//  Created by Zhivko Georgiev on 2.06.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef Circle_h
#define Circle_h
#include "BasicShape.h"
class Circle: public BasicShape{
protected:
    Point centre;
    int radius;
public:
    Circle();
    Circle(const Point&, const int&, const std::string& fill, const int& strokeWidth);
    
    const Point getCentre() const;
    const int getRadius() const;
    void setCentre(const Point&);
    void setRadius(const int&);
    const std::string getType() const override;
    void print() const override;

};

#endif /* Circle_h */
