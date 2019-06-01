//
//  Game.cpp
//  Game
//
//  Created by Zhivko Georgiev on 9.04.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
#include "Game.h"

//Game* Game::getInstance(){
//    if (instance == 0){
//        instance = new Game();
//    }
//    return instance;
//}
//Game *Game::instance = 0;

Game::Game(): hiddenNumber(rand() % 100 + 1) {
    player = Player();
}

Game::Game(Player player): hiddenNumber(rand() % 100 + 1) { 
    this->player = player;
}

void Game::gamePlaying(int num) {
    if(player.tokens > 0){
        player.tokens--;
        if(hiddenNumber == num){
            std::cout << "You guessed" << std::endl;
            hiddenNumber = rand() % 100 + 1;
            player.tokens +=2;
        }
        else {
            std::cout << "You are wrong" << std::endl;
        }
    }
    else std::cout << "No money" << std::endl;
}
