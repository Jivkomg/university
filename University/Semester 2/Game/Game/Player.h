//
//  Player.h
//  Game
//
//  Created by Zhivko Georgiev on 9.04.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef Player_h
#define Player_h
class Player{
private:
    char* playerName;
    int tokens;
public:
    Player(); //default
    Player(const char*); //one
    Player(const Player&); //copy

    int getTokens() const;
    Player& operator=(const Player&);
    ~Player(); //destructor
    friend class Game;
};

#endif /* Player_h */
