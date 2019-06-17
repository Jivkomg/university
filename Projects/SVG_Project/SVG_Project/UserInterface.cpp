//
//  UserInterface.cpp
//  SVG_Project
//
//  Created by Zhivko Georgiev on 17.06.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include "UserInterface.h"

void UserInterface::print() const{
    for(int i = 0; i < shapes.size(); i++){
        std::cout << i + 1;
        shapes[i]->print();
        std::cout << std::endl;
    }
}
