//
//  Player.h
//  EntitySystem
//
//  Created by Zhivko Georgiev on 8.06.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef Player_h
#define Player_h
#include "Entity.h"
#include "Mob.h"
class Player: public Entity{
protected:
    int health;
    int damage;
public:
    Player();
    Player(int, std::string, Point2D*, int);
    bool isAlive() override;
    void attack(Player*);
    void attack(class Mob*);
    void print() override;
    friend class Mob;
};

#endif /* Player_h */
