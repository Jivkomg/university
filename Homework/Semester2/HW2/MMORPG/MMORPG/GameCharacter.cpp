
#include <iostream>
#include "GameCharacter.h"

GameCharacter::GameCharacter(): HP(0), MP(0), AP(0), DP(0) {
    name = new char[1];
    name[0] = '\0';
}

GameCharacter::GameCharacter(const char* name, int hp, int mp, int ap, int dp):HP(hp), MP(mp), AP(ap), DP(dp){
    size_t len = strlen(name);
    this->name = new char[len + 1];
    strcpy(this->name, name);
}

GameCharacter::GameCharacter(const GameCharacter& rhs): HP(rhs.HP), MP(rhs.MP),
    AP(rhs.AP), DP(rhs.DP){
    size_t len = strlen(rhs.name);
    this->name = new char[len + 1];
    strcpy(this->name, rhs.name);
}

bool GameCharacter::isDead() const {
    if(HP <= 0){
        return true;
    }
    else return false;
}

void GameCharacter::get_attacked(int points) {
    int difference = points - DP;
    if(difference >= 0){
        HP -= difference;
    }
    if(this->isDead()){
        std::cout << "Noo, " << name << " is dead!" << std::endl;
    }
}

void GameCharacter::show_power() const {
    if(this->isDead()){
        std::cout << name << " is dead!" << std::endl;

    }
    else{
        std::cout << "Name: " << name << std::endl;
        std::cout << "HP: " << HP << std::endl;
        std::cout << "MP: " << MP << std::endl;
        std::cout << "AP: " << AP << std::endl;
        std::cout << "DP: " << DP << std::endl;
    }
}

GameCharacter& GameCharacter::operator=(const GameCharacter& rhs) {
    if (this != &rhs) {
        delete[] name;
        HP = rhs.HP;
        MP = rhs.MP;
        AP = rhs.AP;
        DP = rhs.DP;
        size_t len = strlen(rhs.name);
        this->name = new char[len + 1];
        strcpy(this->name, rhs.name);
    }
    return *this;
}

GameCharacter::~GameCharacter() { 
    delete[] name;
}




