//
//  Point3D.h
//  EntitySystem
//
//  Created by Zhivko Georgiev on 4.06.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef Point3D_h
#define Point3D_h
#include "Point2D.h"
class Point3D: public Point2D{
protected:
    double z;
public:
    Point3D();
    Point3D(double, double, double);
    double getDistanceTo(const Point3D&);
};

#endif /* Point3D_h */
