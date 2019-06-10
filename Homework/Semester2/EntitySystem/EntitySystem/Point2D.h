//
//  Point2D.h
//  EntitySystem
//
//  Created by Zhivko Georgiev on 4.06.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef Point2D_h
#define Point2D_h

class Point2D{
protected:
    double x;
    double y;
public:
    Point2D();
    Point2D(double, double);
    virtual double getDistanceTo(const Point2D&);
};
#endif /* Point2D_h */
