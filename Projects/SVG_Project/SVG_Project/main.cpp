//
//  main.cpp
//  SVG_Project
//
//  Created by Zhivko Georgiev on 29.05.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
//#include <sstream>
//#include <vector>
//#include <string>
#include <fstream>
#include "UserInterface.h"

int main() {
//    UserInterface ui;
//    ui.executeProgram();
    std::ofstream ofs("test.txt");
    
    ofs << "bla";
    ofs.close();
    
    return 0;
}
