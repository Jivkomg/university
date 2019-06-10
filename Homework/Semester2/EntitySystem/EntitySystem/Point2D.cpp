//
//  Point2D.cpp
//  EntitySystem
//
//  Created by Zhivko Georgiev on 4.06.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include "Point2D.h"
#include "math.h"

Point2D::Point2D(): x(0.0), y(0.0) {
}

Point2D::Point2D(double x, double y):x(x), y(y) {
}

double Point2D::getDistanceTo(const Point2D& point) {
    return sqrt((x - point.x) * (x - point.x) + (y - point.y) * (y - point.y));
}
