//
//  Entity.h
//  EntitySystem
//
//  Created by Zhivko Georgiev on 4.06.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef Entity_h
#define Entity_h
#include <iostream>
#include <string>
#include "Point3D.h"
class Entity{
protected:
    int iD;
    std::string name;
    Point2D* location;
// big 4
public:
    enum Type{Player, NPC, Mob} type;
    Entity();
    Entity(int, std::string, Point2D*, Type);
    Entity(const Entity&);
    Point2D* getLocation() const;
    void setLocation(Point2D*);
    virtual bool isAlive();
    virtual double getDistanceTo2D(const Entity&);
    virtual double getDistanceTo(const Entity&);
    virtual void moveTo(Point2D*);
    virtual void moveTo(Point3D*);
    virtual void moveTo(const Entity&);
    virtual void print() = 0;
    Entity& operator=(const Entity&);
    virtual ~Entity();
};

#endif /* Entity_h */
