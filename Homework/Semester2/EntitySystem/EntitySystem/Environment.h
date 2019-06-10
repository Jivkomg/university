//
//  Environment.h
//  EntitySystem
//
//  Created by Zhivko Georgiev on 8.06.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef Environment_h
#define Environment_h
#include "Player.h"
#include "Mob.h"
#include "NPC.h"
#include <vector>

class Environment{
private:
    std::vector<Entity*> entities;
public:
    Environment();
    void add(Entity*);
    const Entity& getAt(int index);
    void removeAt(int index);
    void generateEntities();
    void destroyEntities();
    Entity* getClosestEntity(Player, Entity::Type);
    
};

#endif /* Environment_h */
