//
//  NPC.h
//  EntitySystem
//
//  Created by Zhivko Georgiev on 8.06.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef NPC_h
#define NPC_h

#include "Entity.h"
class NPC: public Entity{
public:
    NPC();
    NPC(int, std::string, Point2D*);
    bool isAlive() override;
    void print() override;
    
};
#endif /* NPC_h */
