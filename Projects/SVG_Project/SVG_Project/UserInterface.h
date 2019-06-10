//
//  UserInterface.h
//  SVG_Project
//
//  Created by Zhivko Georgiev on 4.06.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef UserInterface_h
#define UserInterface_h
#include <string>
class UserInterface(){
public:
    void close();
    void save();
    void saveAs(const std::string&);
    void exit();
    void open(const std::string&);
    void clear();
    void print() const;
}
#endif /* UserInterface_h */
