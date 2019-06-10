//
//  Player.cpp
//  EntitySystem
//
//  Created by Zhivko Georgiev on 8.06.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include "Player.h"

Player::Player(): Entity(), health(100), damage(0) {
    Type::Player;
}

Player::Player(int iD, std::string name, Point2D* location, int health):
Entity(iD, name, location,Type::Player), health(health){
}

void Player::print() {
    std::cout << name << " health: " << health;
}

void Player::attack(Player* rhs) {
    if (this->getDistanceTo(*rhs) < 5){
        rhs->health = rhs->health - this->damage;
    }
}
void Player::attack(class Mob* rhs) {
    if (this->getDistanceTo(*rhs) < 5){
        rhs->setHealth( rhs->getHealth() - this->damage);
    }
}

bool Player::isAlive() { 
    if (health > 0){
        return true;
    }
    else return false;
}


