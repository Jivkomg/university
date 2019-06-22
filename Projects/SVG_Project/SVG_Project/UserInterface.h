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
//#include "ShapeCreator.h"
#include "Line.h"
#include "Rectangle.h"
#include "Circle.h"
class UserInterface{
    //singleton TODO
private:
    std::string currentFile;
    std::vector<BasicShape*> shapes;
    
    
    void close();
    void save();
    void saveAs(const std::string&);
    void exit();
    void open(const std::string&);
    void clear();
    void help() const;
    void read(std::istream&);

    bool containedInRectangle(const Rectangle&, const BasicShape*);
    bool containedInCircle(const Circle&, const BasicShape*);
    
    Line* createLine(std::vector<std::string>);
    Rectangle* createRectangle(const std::vector<std::string>&);
    Circle* createCircle(const std::vector<std::string>&);
    
    void create(const std::vector<std::string>&);
    void erase(const int&);
    void print() const;
    void within(const std::vector<std::string>&);
    void translate(const std::vector<std::string>&);
public:
    void executeProgram();
    
};
#endif /* UserInterface_h */
