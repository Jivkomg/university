//
//  Point.h
//  PointTriangle
//
//  Created by Zhivko Georgiev on 7.03.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef Point_h
#define Point_h
#include <math.h>
class Point{
private:
    double x;
    double y;
public:
    void setX();
    void setY();
    void printPoint() const;
    double getX() const;
    double getY() const;
    
    double distanceBetweenTwoPoints(const Point& a) const;
};

#endif /* Point_h */
