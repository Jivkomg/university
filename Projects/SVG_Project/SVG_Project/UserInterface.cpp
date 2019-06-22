//
//  UserInterface.cpp
//  SVG_Project
//
//  Created by Zhivko Georgiev on 17.06.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include "UserInterface.h"
//#include "Rectangle.h"
//#include "Circle.h"
//#include "Line.h"
//#include "ShapeCreator.h"
#include <fstream>
#include <iostream>


const std::string header = "<?xml version=\"1.0\" standalone=\"no\"?>\n<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"\n\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n";
const std::string openTag = "<svg>\n";
const std::string closeTag = "</svg>\n";

void UserInterface::close() {
    this->clear();
    std::cout << "Closed current file" << std::endl;
}

void UserInterface::save() {
    if(currentFile == ""){
        std::cout << "There is no opened file!" << std::endl;
        return;
    }
    this->saveAs(currentFile);
}

void UserInterface::saveAs(const std::string& fileName) {
    std::ofstream ofs;
    char* fileNameCharArray = new char[fileName.length() + 1];
    strcpy(fileNameCharArray, fileName.c_str());
    ofs.open(fileNameCharArray, std::ofstream::out | std::ofstream::trunc);
    
    if (!ofs.is_open())
    {
        std::cout << "Invalid input" << std::endl;
        return;
    }
    ofs << header << openTag;
    
    for (int i = 0; i < this->shapes.size(); i++)
    {
        this->shapes[i]->serialize(ofs);
    }
    
    ofs << closeTag;
    ofs.close();
    std::cout << "Successfully saved to " << fileNameCharArray << std::endl;
    delete[] fileNameCharArray;
}

void UserInterface::exit() {
    std::cout << "Exit" << std::endl;
    this->clear();
}

void UserInterface::open(const std::string& fileName) {
    std::ifstream ifs;
    char* fileNameCharArray = new char[fileName.length() + 1];
    strcpy(fileNameCharArray, fileName.c_str());

    ifs.open(fileNameCharArray, std::ifstream::out);
    delete[] fileNameCharArray;
    if (!ifs.is_open())
    {
        std::cout << "Invalid input" << std::endl;
        return;
    }
    this->clear();
    this->currentFile = fileName;
    this->read(ifs);
    std::cout << "Successfully opened " << fileName << "\n";
    ifs.close();
}
void UserInterface::clear() {
    currentFile = "";
    for (int i = 0; i < this->shapes.size(); i++)
    {
        delete shapes[i];
    }
    shapes.clear();
}

void UserInterface::help() const {
    //TODO
    std::cout << "Commands available:\n";
    std::cout << "- print\n";
    std::cout << "- create <rectangle/circle/line> <params>\n";
    std::cout << "- erase <index>\n";
    std::cout << "- translate vertical=<value> horizontal=<value> {<index>}\n";
    std::cout << "- within <rectangle/circle> <params>\n";
    std::cout << "- save\n";
    std::cout << "- saveas <filename>\n";
    std::cout << "- open <filename>\n";
    std::cout << "- close\n";
    std::cout << "- exit\n";
    std::cout << "For more details, read the Readme file!\n";
}

void UserInterface::read(std::istream& is) {
    //    std::ifstream inputFile(fileName, std::ios_base::binary);
    //    if (inputFile.fail()) {
    //        return false; // Failed to open file
    //    }
    //
    //    if (inputFile.is_open()) {
    //        char next;
    //        while (inputFile.get(next)) {
    //            input.push_back(next);
    //        }
    //    }
    //    inputFile.close();
    //    return true; // Successfully read file
    //}
    if(is.good()){
//        ShapeCreator creator;
        
//       get the next tag might do additional method
        char c;
        std::string s = "";
        do
        {
            c = is.get();
            
        } while (c != '<' && c > 0);
        
        c = is.get();
        while (c != ' ' && c != '>')
        {
            s += c;
            c = is.get();
        }
        
        std::string tagName = s;
        while (tagName != "/svg")
        {
            BasicShape* shape;
            if(tagName == "rectangle"){
                shape = new Rectangle();
            }
            else if(tagName == "line"){
                shape = new Line();
            }
            else if(tagName == "circle"){
                shape = new Circle();
            }
            else {
                shape = nullptr;
            }

//            BasicShape* shape = creator.createShape(tagName);
            if (shape != nullptr)
            {
                shape->deserialize(is);
                this->shapes.push_back(shape);
            }
            //       get the next tag

            std::string s = "";
            do
            {
                c = is.get();
                
            } while (c != '<' && c > 0);
            
            c = is.get();
            while (c != ' ' && c != '>')
            {
                s += c;
                c = is.get();
            }
            tagName = s;
        }
    }
    std::cout << "Invalid stream!" << std::endl;
}


bool UserInterface::containedInRectangle(const Rectangle& rect, const BasicShape* shape){
    if((rect.getLeft().x <= shape->getLeft().x) && (rect.getLeft().y <= shape->getLeft().y) &&
       ((rect.getLeft().x <= shape->getBottom().x) && rect.getLeft().y <= shape->getBottom().y) &&
       ((rect.getRight().x >= shape->getRight().x) && rect.getRight().y >= shape->getRight().y) &&
       ((rect.getRight().x >= shape->getTop().x) && rect.getRight().y >= shape->getTop().y)){
        return true;
    }
    else return false;
}

bool UserInterface::containedInCircle(const Circle& circle, const BasicShape* shape){
    if ((circle.getCentre().getDistanceToPoint(shape->getBottom()) > circle.getRadius()) ||
        (circle.getCentre().getDistanceToPoint(shape->getRight()) > circle.getRadius()) ||
        (circle.getCentre().getDistanceToPoint(shape->getLeft()) > circle.getRadius()) ||
        (circle.getCentre().getDistanceToPoint(shape->getTop()) > circle.getRadius())){
        return false;
    }
    else return true;
}



Line* UserInterface::createLine(std::vector<std::string> params) {
    if(params.size() < 6){
        std::cout << "Not enough parameters" << std::endl;
        return nullptr;
    }
    Point p1(std::atoi(params[2].c_str()), std::atoi(params[3].c_str()));
    Point p2(std::atoi(params[4].c_str()), std::atoi(params[5].c_str()));
    Line* newLine = new Line();
    newLine->setPoint1(p1);
    newLine->setPoint1(p2);
    newLine->setStrokeWidth(std::atoi(params[6].c_str()));
    return newLine;
}

Rectangle* UserInterface::createRectangle(const std::vector<std::string>& params) {
    if(params.size() < 6){
        std::cout << "Not enough parameters" << std::endl;
        return nullptr;
    }
    Point leftMostPoint(std::atoi(params[2].c_str()), std::atoi(params[3].c_str()));
    int width = std::atoi(params[4].c_str());
    int height = std::atoi(params[5].c_str());
    Rectangle* newRect = new Rectangle();
    newRect->setLeftMostPoint(leftMostPoint);
    newRect->setWidth(width);
    newRect->setHeight(height);
    if(params.size() == 7){
        newRect->setFill(params[6].c_str());
    }
    return newRect;
}

Circle* UserInterface::createCircle(const std::vector<std::string>& params) {
    if(params.size() < 5){
        std::cout << "Not enough parameters" << std::endl;
        return nullptr;
    }
    Point centre(std::atoi(params[2].c_str()), std::atoi(params[3].c_str()));
    int radius = std::atoi(params[4].c_str());
    Circle* newCircle = new Circle();
    newCircle->setCentre(centre);
    newCircle->setRadius(radius);
    if(params.size() == 6){
        newCircle->setFill(params[5]);
    }
    return newCircle;
}


void UserInterface::print() const{
    for(int i = 0; i < shapes.size(); i++){
        std::cout << i + 1;
        shapes[i]->print();
        std::cout << std::endl;
    }
}


void UserInterface::create(const std::vector<std::string>& params) {
    BasicShape* newShape;
    if(!params[1].compare("rectangle")){
        newShape = createRectangle(params);
    }
    else if(!params[1].compare("circle")){
        newShape = createCircle(params);
    }
    else if(!params[1].compare("line")){
        newShape = createLine(params);
    }
    else{
        std::cout << "Invalid parameters!" << std::endl;
        return;
    }
    shapes.push_back(newShape);
    std::cout << "Successfully created " << newShape->getType() << " " << shapes.size() << "\n";
}

void UserInterface::erase(const int& index) {
    if(index > shapes.size() - 1){
        std::cout << "There is no figure number "<< index << "!" << std::endl;
        return;
    }
    BasicShape* figure = this->shapes[index - 1];
    this->shapes.erase(this->shapes.begin() + index - 1);
    std::cout << "Erased a " << figure->getType() << " (" << index << ")" << std::endl;
    delete figure;
}

void UserInterface::within(const std::vector<std::string>& params) {
    std::vector<int> shapesWithinIndexes;
    if(params.size() == 5 || params.size() == 6){
        if(!params[1].compare("rectangle")){
            Rectangle* rectangle = createRectangle(params);
            for (int i = 0 ; i < shapes.size(); i++) {
                if(containedInRectangle(*rectangle, shapes[i])){
                    shapesWithinIndexes.push_back(i);
                }
            }
            delete rectangle;
        }
        else if(!params[1].compare("circle")){
            Circle* circle = createCircle(params);
            for (int i = 0 ; i < shapes.size(); i++) {
                if(containedInCircle(*circle, shapes[i])){
                    shapesWithinIndexes.push_back(i);
                }
            }
            delete circle;
        }
        else{
            std::cout << "Invalid input!" << std::endl;
            return;
        }
    }
    else{
        std::cout << "Invalid input!" << std::endl;
        return;
    }
    for (int i = 0; i < shapesWithinIndexes.size(); i++) {
        std::cout << i + 1 << ". ";
        shapes[shapesWithinIndexes[i]]->print();
    }
}

void UserInterface::translate(const std::vector<std::string>& params) {
    if(params.size() >= 3){
        int dx = std::atoi(params[2].substr(params[2].find("=") + 1).c_str());
        int dy = std::atoi(params[1].substr(params[1].find("=") + 1).c_str());
        if (params.size() == 3)
        {
            for (int i = 0; i < this->shapes.size(); i++)
            {
                this->shapes[i]->translate(dx, dy);
            }
            std::cout << "Translated all figures" << std::endl;
            return;
        }
        int index = std::atoi(params[3].c_str());
        shapes[index]->translate(dx, dy);
        std::cout << "Translated " << index << std::endl;
    }
}

void UserInterface::executeProgram() { 
    std::cout << "Welcome!" << std::endl;
    std::string input;
    while (true)
    {
        std::cout << "> ";
        std::cin >> input;
        std::vector<std::string> params = split(input, ' ');
        std::string cmd = params[0];
        if (cmd == "print")
        {
            this->print();
        }
        else if (cmd == "create")
        {
            this->create(params);
        }
        else if (cmd == "erase")
        {
            this->erase(atoi(params[1].c_str()));
        }
        else if (cmd == "translate")
        {
            this->translate(params);
        }
        else if (cmd == "save")
        {
            this->save();
        }
        else if (cmd == "saveas")
        {
            this->saveAs(params[1]);
        }
        else if (cmd == "open")
        {
            if (params.size() != 2)
            {
                std::cout << "Invalid input!" <<std::endl;
                continue;
            }
            this->open(params[1]);
        }
        else if (cmd == "within")
        {
            if (params.size() < 5)
            {
                std::cout << "Invalid input" <<std::endl;
                continue;
            }
            this->within(params);
        }
        else if (cmd == "exit")
        {
            this->exit();
            return;
        }
        else if (cmd == "close")
        {
            this->close();
        }
        else
        {
            std::cout << "Invalid input" <<std::endl;
            
        }
    }

}






