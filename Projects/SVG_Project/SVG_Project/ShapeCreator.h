//
//  ShapeCreator.h
//  SVG_Project
//
//  Created by Zhivko Georgiev on 17.06.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef ShapeCreator_h
#define ShapeCreator_h

#include "BasicShape"
class ShapeCreator{
public:
    Shape* createShape(const std::string&) const;
};

#endif /* ShapeCreator_h */
