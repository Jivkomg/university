//
//  main.cpp
//  EntitySystem
//
//  Created by Zhivko Georgiev on 4.06.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
#include "Environment.h"

int main() {
    Point2D* p = new Point2D(12, 12);
    Player p1(123, "PLAYER", p, 100);
    Environment* e = nullptr;
    e->generateEntities();
    Mob* mob = dynamic_cast<Mob*>(e->getClosestEntity(p1, Entity::Mob));
    while (nullptr != mob)
    {
        p1.attack(mob);
        mob = dynamic_cast<Mob*>(e->getClosestEntity(p1, Entity::Mob));
    }
    
    return 0;
}
