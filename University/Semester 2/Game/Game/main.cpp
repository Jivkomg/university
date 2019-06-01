//
//  main.cpp
//  Game
//
//  Created by Zhivko Georgiev on 9.04.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
#include "Game.h"
void Hacker(const Game& g){
    std::cout << "The hidden number is: " << g.hiddenNumber << std::endl;
}
int main() {
    Player playerOne("Pesho");
//    Player playerTwo("Tosho");
    
//    Game *gameOne = gameOne::getInstance();

    Game gameOne(playerOne);
    char startSymbol;
    std::cout << "Enter a symbol\n";
    
    while (playerOne.getTokens() > -1) {
        std::cin >> startSymbol;
        if(startSymbol == 'y'){
            int n = 0;
            std::cin >> n;
            gameOne.gamePlaying(n);
        }
        if(startSymbol == 'h'){
            Hacker(gameOne);
            int n = 0;
            std::cin >> n;
            gameOne.gamePlaying(n);
        }
    }
//    while (playerOne.getTokens() > -1 && playerTwo.getTokens() > -1) {
//        std::cin >> startSymbol;
//        if(startSymbol == 'y'){
//            std::cout << "Player one num: \n";
//            int peshoNum = 0;
//            std::cin >> peshoNum;
//            gameOne.gamePlaying(peshoNum);
//
//            std::cout << "Player two num: \n";
//            int toshoNum = 0;
//            std::cin >> toshoNum;
//            gameOne.gamePlaying(toshoNum);
//            if(peshoNum){
//
//            }
//
//        }
//        if(startSymbol == 'h'){
//            Hacker(gameOne);
//            std::cout << "Player one num: \n";
//            int peshoNum = 0;
//            std::cin >> peshoNum;
//            gameOne.gamePlaying(peshoNum);
//
//            std::cout << "Player two num: \n";
//            int toshoNum = 0;
//            std::cin >> toshoNum;
//            gameOne.gamePlaying(toshoNum);
//        }
//
//    }
//
//    std::cout << ;
    return 0;
}
