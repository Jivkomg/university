//
//  NPC.cpp
//  EntitySystem
//
//  Created by Zhivko Georgiev on 8.06.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include "NPC.h"


NPC::NPC(){
    Type::NPC;
}

NPC::NPC(int iD, std::string name, Point2D* p): Entity(iD, name,p , Type::NPC)  {
}

bool NPC::isAlive() { 
    return true;
}
