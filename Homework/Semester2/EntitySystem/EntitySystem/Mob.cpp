//
//  Mob.cpp
//  EntitySystem
//
//  Created by Zhivko Georgiev on 8.06.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include "Mob.h"


Mob::Mob():Entity() {
    Type::Mob;
}

Mob::Mob(int iD, std::string name, Point2D* location, int health):Entity(iD, name, location, Type::Mob) {
    Type::Mob;
}

bool Mob::isAlive() { 
    if (health > 0)
    {
        return true;
    }
    else return false;
}
void Mob::setHealth(const int& h){
    health = h;
}
const int Mob::getHealth() const{
    return health;
}

void Mob::attack(class Player* rhs) {
    if (this->getDistanceTo(*rhs) < 5)
    {
        rhs->health = rhs->health - this->damage;
    }

}

void Mob::print() { 
    std::cout << name << health;
}


