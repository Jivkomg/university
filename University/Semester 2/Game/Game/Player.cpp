//
//  Player.cpp
//  Game
//
//  Created by Zhivko Georgiev on 9.04.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include "Player.h"
#include <iostream>

Player::Player(): tokens(1){
    this->playerName = nullptr;
}

Player::Player(const char* name): tokens(1) {
    size_t len = strlen(name);
    playerName = new char[len + 1];
    strcpy(this->playerName, name);

}

Player::Player(const Player& rhs): tokens(rhs.tokens){
    size_t len = strlen(rhs.playerName);
    playerName = new char[len + 1];
    strcpy(this->playerName, rhs.playerName);
}

Player &Player::operator=(const Player& rhs) {
    if(this != &rhs){
        delete[] playerName;
        size_t len = strlen(rhs.playerName);
        playerName = new char[len + 1];
        strcpy(this->playerName, rhs.playerName);
    }
    return *this;
}

int Player::getTokens() const {
    return tokens;
}

Player::~Player() { 
    delete[] playerName;
}




