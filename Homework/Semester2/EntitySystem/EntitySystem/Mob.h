//
//  Mob.h
//  EntitySystem
//
//  Created by Zhivko Georgiev on 8.06.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef Mob_h
#define Mob_h
#include "Entity.h"
#include "Player.h"
class Mob: public Entity{
private:
    int health;
    int damage;
public:
    Mob();
    Mob(int, std::string, Point2D*, int);
    void setHealth(const int&);
    const int getHealth() const;
    void attack(class Player*);
    void print();
    bool isAlive();
};
#endif /* Mob_h */
