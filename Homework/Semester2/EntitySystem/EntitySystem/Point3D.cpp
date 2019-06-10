//
//  Point3D.cpp
//  EntitySystem
//
//  Created by Zhivko Georgiev on 4.06.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include "Point3D.h"
#include "math.h"

Point3D::Point3D(): Point2D(), z(0.0) {
}

Point3D::Point3D(double x, double y, double z): Point2D(x,y), z(z) {
}

double Point3D::getDistanceTo(const Point3D& point) {
    return sqrt((x - point.x) * (x - point.x) + (y - point.y) * (y - point.y)
                + (z - point.z) * (z - point.z));
}
