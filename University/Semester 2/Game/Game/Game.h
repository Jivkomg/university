//
//  Game.h
//  Game
//
//  Created by Zhivko Georgiev on 9.04.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef Game_h
#define Game_h
#include "Player.h"
class Game{
private:
//    static Game* instance;
    int hiddenNumber;
    Player player;
    
public:
    Game(); //default
    Game(Player); //one parameter

//    static Game* getInstance();
    void gamePlaying(int);
    friend void Hacker(const Game& g);
};

#endif /* Game_h */
