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
#include "rapidxml_utils.hpp"


//const std::string header = "<?xml version=\"1.0\" standalone=\"no\"?>\n<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"\n\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n";
//const std::string openTag = "<svg>\n";
//const std::string closeTag = "</svg>\n";
std::vector<std::string> split(const std::string& str,char delimiter)
{
    std::vector<std::string> result;
    long count = std::count(str.begin(), str.end(), delimiter);
    long currIndex = 0;
    long indexOfDelimiter = str.find(delimiter);
    for (int i = 0; i < count; i++)
    {
        result.push_back(std::string(str.substr(currIndex, indexOfDelimiter - currIndex)));
        currIndex = indexOfDelimiter + 1;
        indexOfDelimiter = str.find(delimiter, currIndex);
    }
    result.push_back(std::string(str.substr(currIndex)));
    
    //Remove empty entries
    for (long i = result.size() - 1; i >= 0; i--)
    {
        if (result[i] == std::string())
        {
            result.erase(result.begin() + i);
        }
    }
    return result;
}

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
    this->currentFile = fileName.c_str();
    rapidxml::file<> xmlFile("somefile.xml"); // Default template is char
    rapidxml::xml_document<> doc;
    doc.parse<0>(xmlFile.data());
    rapidxml::xml_node<>* node = doc.first_node();
    //remove all nodes
    
//    while(node->next_sibling() != nullptr){
//        delete
//    }
    //    strcpy(currentFile, fileName.c_str());
    for(int i = 0; i < shapes.size(); i++){
//        add
    }
    
//    std::ofstream ofs;
//    char* fileNameCharArray = new char[fileName.length() + 1];
//    strcpy(fileNameCharArray, fileName.c_str());
//    ofs.open(fileNameCharArray, std::ofstream::out | std::ofstream::trunc);
//
//    if (!ofs.is_open())
//    {
//        std::cout << "Invalid input" << std::endl;
//        return;
//    }
//    ofs << header << openTag;
//
//    for (int i = 0; i < this->shapes.size(); i++)
//    {
//        this->shapes[i]->serialize(ofs);
//    }
//
//    ofs << closeTag;
//    ofs.close();
//    std::cout << "Successfully saved to " << fileNameCharArray << std::endl;
//    delete[] fileNameCharArray;
}

void UserInterface::exit() {
    std::cout << "Exited program" << std::endl;
    this->clear();
}

void UserInterface::open(const std::string& fileName) {
//    std::ifstream ifs;
////    char* fileNameCharArray = new char[fileName.length() + 1];
////    strcpy(fileNameCharArray, fileName.c_str());
//
//    ifs.open(fileName.c_str(), std::ifstream::out);
////    delete[] fileNameCharArray;
//    if (!ifs.is_open())
//    {
//        std::cout << "Invalid input" << std::endl;
//        return;
//    }
//    this->clear();
//    this->currentFile = fileName;
//    this->read(ifs);
//    std::cout << "Successfully opened " << fileName << "\n";
//    ifs.close();
    std::ifstream ifs(fileName);
    if (!ifs)
    {
        std::cout << "Invalid file name" << std::endl;
        return;
    }
    std::string xmlText = "";
    while(ifs.peek() != EOF){
        std::string line;
        std::getline(ifs, line);
        xmlText += line;
    }
//    rapidxml::file<> xmlFile(xmlText.c_str()); // Default template is char
    rapidxml::xml_document<> doc;
    char* xmlTextChars = new char[strlen(xmlText.c_str()) + 1];
    strcpy(xmlTextChars, xmlTextChars);
    doc.parse<0>(xmlTextChars);
    rapidxml::xml_node<>* node = doc.first_node();
//    std::cout << node->name() <<"ewnfioqfioewnkqw" << std::endl;
//    rapidxml::xml_attribute<> *attr = node->first_attribute();
    do{
        if(!strcmp(node->name(), "rect")){
            rapidxml::xml_attribute<>* attr = node->first_attribute();
            Rectangle* rect = new Rectangle();
            Point p((int)*attr->value(), (int)*attr->next_attribute()->value());
            rect->setLeftMostPoint(p);
            attr = attr->next_attribute()->next_attribute();
            rect->setWidth((int)*attr->value());
            attr = attr->next_attribute();
            rect->setHeight((int)*attr->value());
            attr = attr->next_attribute();
            rect->setFill(attr->value());
            shapes.push_back(rect);
        }
        else if(!strcmp(node->name(), "circle")){
            rapidxml::xml_attribute<>* attr = node->first_attribute();
            Circle* circle = new Circle();
            Point p((int)*attr->value(), (int)*attr->next_attribute()->value());
            circle->setCentre(p);
            attr = attr->next_attribute()->next_attribute();
            circle->setRadius((int)*attr->value());
            attr = attr->next_attribute();
            circle->setFill(attr->value());
            shapes.push_back(circle);
        }
        else if(!strcmp(node->name(), "line")){
            rapidxml::xml_attribute<>* attr = node->first_attribute();
            Line* line = new Line();
            Point p1((int)*attr->value(), (int)*attr->next_attribute()->value());
            line->setPoint1(p1);
            attr = attr->next_attribute()->next_attribute();
            
            Point p2((int)*attr->value(), (int)*attr->next_attribute()->value());
            line->setPoint1(p2);
            attr = attr->next_attribute()->next_attribute();
            
            line->setStrokeWidth((int)*attr->value());
            shapes.push_back(line);
        }
        node = node->next_sibling();
    }
    while (node->next_sibling() != nullptr);
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
    std::cout << "List of all the commands that are available:\n";
    std::cout << "- print(prints all figures in the file)\n";
    std::cout << "- create <rectangle/circle/line> <params>(creates new figure)\n";
    std::cout << "- erase <index>(erases a figure by index, or all figures)\n";
    std::cout << "- translate vertical=<value> horizontal=<value> {<index>}(translates figure by index or all figures)\n";
    std::cout << "- within <rectangle/circle> <params>(checks if a figure is within rectangle or circle)\n";
    std::cout << "- save\n";
    std::cout << "- saveas <filename>\n";
    std::cout << "- open <filename>\n";
    std::cout << "- close\n";
    std::cout << "- exit\n";
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
//    if(is.good()){
////        ShapeCreator creator;
//
////       get the next tag might do additional method
//        char c;
//        std::string s = "";
//        do
//        {
//            c = is.get();
//
//        } while (c != '<' && c > 0);
//
//        c = is.get();
//        while (c != ' ' && c != '>')
//        {
//            s += c;
//            c = is.get();
//        }
//
//        std::string tagName = s;
//        while (tagName != "/svg")
//        {
//            BasicShape* shape;
//            if(tagName == "rectangle"){
//                shape = new Rectangle();
//            }
//            else if(tagName == "line"){
//                shape = new Line();
//            }
//            else if(tagName == "circle"){
//                shape = new Circle();
//            }
//            else {
//                shape = nullptr;
//            }
//
////            BasicShape* shape = creator.createShape(tagName);
//            if (shape != nullptr)
//            {
//                shape->deserialize(is);
//                this->shapes.push_back(shape);
//            }
//            //       get the next tag
//
//            std::string s = "";
//            do
//            {
//                c = is.get();
//
//            } while (c != '<' && c > 0);
//
//            c = is.get();
//            while (c != ' ' && c != '>')
//            {
//                s += c;
//                c = is.get();
//            }
//            tagName = s;
//        }
//    }
//    std::cout << "Invalid stream!" << std::endl;
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
//    if(params.size() < 6){
//        std::cout << "Not enough parameters" << std::endl;
//        return nullptr;
//    }
    Point p1(std::atoi(params[2].c_str()), std::atoi(params[3].c_str()));
    Point p2(std::atoi(params[4].c_str()), std::atoi(params[5].c_str()));
    Line* newLine = new Line();
    newLine->setPoint1(p1);
    newLine->setPoint1(p2);
    newLine->setStrokeWidth(std::atoi(params[6].c_str()));
    return newLine;
}

Rectangle* UserInterface::createRectangle(const std::vector<std::string>& params) {
//    if(params.size() < 6){
//        std::cout << "Not enough parameters" << std::endl;
//        return nullptr;
//    }
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
//    if(params.size() < 5){
//        std::cout << "Not enough parameters" << std::endl;
//        return nullptr;
//    }
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
        if (params.size() < 6)
        {
            std::cout << "Not enough parameters for rectangle" << std::endl;
            return;
        }
        newShape = createRectangle(params);
    }
    else if(!params[1].compare("circle")){
        if (params.size() < 5)
        {
            std::cout << "Not enough parameters for circle" << std::endl;
            return;
        }

        newShape = createCircle(params);
    }
    else if(!params[1].compare("line")){
        if (params.size() < 7)
        {
            std::cout << "Not enough parameters" << std::endl;
            return;
        }

        newShape = createLine(params);
    }
    else{
        std::cout << "Invalid parameters for creation!" << std::endl;
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
            std::cout << "Invalid input for within function!" << std::endl;
            return;
        }
    }
    else{
        std::cout << "Invalid input for within function!" << std::endl;
        return;
    }
    for (int i = 0; i < shapesWithinIndexes.size(); i++) {
        std::cout << i + 1 << ". ";
        shapes[shapesWithinIndexes[i]]->print();
    }
}

void UserInterface::translate(const std::vector<std::string>& params) {
    if(params.size() >= 3){
        int dy = std::atoi(split(params[1], '=')[1].c_str());
        int dx = std::atoi(split(params[2], '=')[1].c_str());

//        int dx = std::atoi(params[2].substr(params[2].find("=") + 1).c_str());
//        int dy = std::atoi(params[1].substr(params[1].find("=") + 1).c_str());
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
    std::cout << "Welcome to the SVG project!" << std::endl;
    this->help();
    std::string input;
    while (true)
    {
        std::cout << "> ";
//        std::cin >> input;
        std::getline(std::cin, input);
        std::vector<std::string> params = split(input, ' ');
        std::cout << params.size();
        std::string cmd = params[0];
//        std::cout << params[1] << std::endl;
        if (!strcmp(cmd.c_str(), "print"))
        {
            this->print();
        }
        else if (!strcmp(cmd.c_str(), "create"))
        {
            this->create(params);
        }
        else if (!strcmp(cmd.c_str(), "erase"))
        {
            this->erase(atoi(params[1].c_str()));
        }
        else if (!strcmp(cmd.c_str(), "translate"))
        {
            this->translate(params);
        }
        else if (!strcmp(cmd.c_str(), "save"))
        {
            this->save();
        }
        else if (!strcmp(cmd.c_str(), "saveas"))
        {
            this->saveAs(params[1]);
        }
        else if (!strcmp(cmd.c_str(), "open"))
        {
//            std::cout << params[1];
            if (params.size() != 2)
            {
                std::cout << "Invalid input for open!" <<std::endl;
                continue;
            }
            this->open(params[1]);
            std::cout << "Successfully opened " << params[1] << std::endl;
        }
        else if (!strcmp(cmd.c_str(), "within"))
        {
            if (params.size() < 5)
            {
                std::cout << "Invalid input for within" <<std::endl;
                continue;
            }
            this->within(params);
        }
        else if (!strcmp(cmd.c_str(), "exit"))
        {
            this->exit();
            return;
        }
        else if (!strcmp(cmd.c_str(), "close"))
        {
            this->close();
        }
        else
        {
            std::cout << "Invalid input for execution. Read the help menu" << std::endl;

        }
    }

}






