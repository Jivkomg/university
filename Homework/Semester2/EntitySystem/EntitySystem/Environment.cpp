//
//  Environment.cpp
//  EntitySystem
//
//  Created by Zhivko Georgiev on 9.06.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include "Environment.h"


Environment::Environment() {
}


void Environment::add(Entity* rhs) {
    entities.push_back(rhs);
}

const Entity& Environment::getAt(int index) {
    return* entities.at(index);
}

void Environment::removeAt(int index) { 
    entities.erase(entities.begin() + index);
}

void Environment::generateEntities() { 
    Point2D* pointMob1 = new Point2D(10, 10);
    Mob* mob1 = new Mob(0,"mob1", pointMob1, 80);
    this->add(mob1);
    
    Point2D* pointPlayer1 = new Point2D(20, 20);
    Player* p2 = new Player(1, "player", pointPlayer1, 100);
    this->add(p2);
    
    Point3D* pointNPC = new Point3D(4, 5, 1);
    NPC* npc = new NPC(2, "npc", pointNPC);
    this->add(npc);;
}

void Environment::destroyEntities() { 
    for (int i = 0; i < entities.size(); i++)
    {
        delete entities[i];
        this->removeAt(i);
    }
}

Entity* Environment::getClosestEntity(Player p, Entity::Type t) {
    Entity* closestEntity = entities[0];
    double distance = p.getDistanceTo(*closestEntity);
    for (int i = 0; i < entities.size(); i++)
    {
        if (distance > p.getDistanceTo(*entities[i]) && p.type == t && closestEntity->isAlive())
        {
            distance = p.getDistanceTo(*entities[i]);
            closestEntity = this->entities[i];
        }
    }
    return closestEntity;;
}
