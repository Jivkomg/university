//
//  Triangle.h
//  PointTriangle
//
//  Created by Zhivko Georgiev on 7.03.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef Triangle_h
#define Triangle_h
#include "Point.h"

class Triangle {
private:
    double sideA;
    double sideB;
    double sideC;
    
    Point A;
    Point B;
    Point C;
public:
    void setPoint(const Point& a, const Point& b, const Point& c);
    void typeOfTriangle() const;
    bool isValidTriangle() const;
};

#endif /* Triangle_h */
