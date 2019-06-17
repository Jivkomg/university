//
//  UserInterface.h
//  SVG_Project
//
//  Created by Zhivko Georgiev on 4.06.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef UserInterface_h
#define UserInterface_h
#include <vector>
#include "BasicShape.h"
class UserInterface{
private:
    std::vector<BasicShape*> shapes;
    void close();
    void save();
    void saveAs(const std::string&);
    void exit();
    void open(const std::string&);
//    void clear();
    
    void create(const std::vector<std::string>&);
    void erase(const int&);
    void print() const;
    void within(const std::vector<std::string>&);
    void translate(const std::vector<std::string>&);
};
#endif /* UserInterface_h */
