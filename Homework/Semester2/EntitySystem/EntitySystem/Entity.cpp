//
//  Entity.cpp
//  EntitySystem
//
//  Created by Zhivko Georgiev on 4.06.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include "Entity.h"
#include <iostream>

Entity::Entity():iD(0), name("New name"), location(NULL),type(Player) {
    
}
Entity::Entity(int iD, std::string name, Point2D* p, Type type):
        iD(iD), name(name), location(p), type(type){

}


Entity::Entity(const Entity& rhs):iD(rhs.iD), type(rhs.type){
    name = std::string(rhs.name);
    location = rhs.location;
}

Point2D* Entity::getLocation() const {
    return location;
}

void Entity::setLocation(Point2D* location) {
    delete[] this->location;
    this->location = location;
}

bool Entity::isAlive() { 
    return true;
}

double Entity::getDistanceTo2D(const Entity& rhs) {
    return this->location->getDistanceTo(*rhs.location);
}

double Entity::getDistanceTo(const Entity& rhs) {
    if(dynamic_cast<Point3D*>(location) != nullptr
        && dynamic_cast<Point3D*>(rhs.location) != nullptr){
        Point3D* p1 = dynamic_cast<Point3D*>(location);
        Point3D* p2 = dynamic_cast<Point3D*>(rhs.location);
        return p1->getDistanceTo(*p2);
    }
    else return this->getDistanceTo(rhs);
    return 0;
}
void Entity::moveTo(Point3D* p) {
    this->setLocation(p);
}

void Entity::moveTo(Point2D* p) {
    this->setLocation(p);
}

void Entity::moveTo(const Entity& rhs) { 
    moveTo(rhs.getLocation());
}

Entity& Entity::operator=(const Entity& rhs) {
    if(this != &rhs){
        delete[] location;
        iD = rhs.iD;
        type = rhs.type;
        name = std::string(rhs.name);
        location = rhs.location;
        
    }
    return *this;
}

Entity::~Entity() { 
    delete[] location;
}





