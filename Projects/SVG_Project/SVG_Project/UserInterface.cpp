//
//  UserInterface.cpp
//  SVG_Project
//
//  Created by Zhivko Georgiev on 17.06.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include "UserInterface.h"
#include <fstream>
#include <iostream>
#include "rapidxml_utils.hpp"
#include "rapidxml_print.hpp"
#include "rapidxml.hpp"
using namespace rapidxml;
#include <string>


int parseInt(const char* stringInt)
{
    int number = 0;
    while (*stringInt != '\0')
    {
        number *= 10;
        number += *stringInt - '0';
        stringInt++;
    }
    return number;
}


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
	if (currentFile.compare("") == 0) {
		std::cout << "There is no opened file!" << std::endl;
		return;
	}
    this->clear();
    std::cout << "Closed current file" << std::endl;
}

void UserInterface::save() {
   
    this->saveAs(currentFile);
}

void UserInterface::saveAs(const std::string& fileName) {
	if (currentFile.compare("") == 0) {
		std::cout << "There is no opened file!" << std::endl;
		return;
	}
    std::ofstream ofs(fileName, std::ofstream::out | std::ofstream::trunc);
	currentFile = fileName;

	// xml declaration
	rapidxml::xml_document<> doc;
	rapidxml::xml_node<>* decl = doc.allocate_node(rapidxml::node_declaration);
	decl->append_attribute(doc.allocate_attribute("version", "1.0"));
	decl->append_attribute(doc.allocate_attribute("encoding", "no"));
	doc.append_node(decl);
	
	// doctype declaration
	rapidxml::xml_node<>* doctype = doc.allocate_node(rapidxml::node_doctype);
	doctype->value("svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\"");
	doc.append_node(doctype);

	// root declaration
	rapidxml::xml_node<>* root = doc.allocate_node(rapidxml::node_element, "svg");
	doc.append_node(root);

	for (int i = 0; i < shapes.size(); i++) {
		if (!strcmp(shapes[i]->getType().c_str(), "rectangle")) {
			rapidxml::xml_node<>* child = doc.allocate_node(rapidxml::node_element, "rect");
			Rectangle* rect = dynamic_cast<Rectangle*>(shapes[i]);
			char* idxStr = doc.allocate_string(std::to_string(rect->getLeft().getX()).c_str());
			child->append_attribute(doc.allocate_attribute("x", idxStr));
		
			idxStr = doc.allocate_string(std::to_string(rect->getLeft().getY()).c_str());
			child->append_attribute(doc.allocate_attribute("y", idxStr));

			idxStr = doc.allocate_string(std::to_string(rect->getWidth()).c_str());
			child->append_attribute(doc.allocate_attribute("width", idxStr));

			idxStr = doc.allocate_string(std::to_string(rect->getHeight()).c_str());
			child->append_attribute(doc.allocate_attribute("height", idxStr));

			idxStr = doc.allocate_string(rect->getFill().c_str());
			child->append_attribute(doc.allocate_attribute("fill", idxStr));
			root->append_node(child);
		}
		else if (!strcmp(shapes[i]->getType().c_str(), "circle")) {
			rapidxml::xml_node<>* child = doc.allocate_node(rapidxml::node_element, "circle");
			Circle* circle = dynamic_cast<Circle*>(shapes[i]);
			
			char* idxStr = doc.allocate_string(std::to_string(circle->getCentre().getX()).c_str());
			child->append_attribute(doc.allocate_attribute("cx", idxStr));

			idxStr = doc.allocate_string(std::to_string(circle->getCentre().getY()).c_str());
			child->append_attribute(doc.allocate_attribute("cy", idxStr));

			idxStr = doc.allocate_string(std::to_string(circle->getRadius()).c_str());
			child->append_attribute(doc.allocate_attribute("r", idxStr));

			idxStr = doc.allocate_string(circle->getFill().c_str());
			child->append_attribute(doc.allocate_attribute("fill", idxStr));
			root->append_node(child);
		}
		else if (!strcmp(shapes[i]->getType().c_str(), "line")) {
			rapidxml::xml_node<>* child = doc.allocate_node(rapidxml::node_element, "line");
			Line* line = dynamic_cast<Line*>(shapes[i]);

			char* idxStr = doc.allocate_string(std::to_string(line->getPoint1().getX()).c_str());
			child->append_attribute(doc.allocate_attribute("x1", idxStr));

			idxStr = doc.allocate_string(std::to_string(line->getPoint1().getY()).c_str());
			child->append_attribute(doc.allocate_attribute("y1", idxStr));

			idxStr = doc.allocate_string(std::to_string(line->getPoint2().getX()).c_str());
			child->append_attribute(doc.allocate_attribute("x2", idxStr));

			idxStr = doc.allocate_string(std::to_string(line->getPoint2().getY()).c_str());
			child->append_attribute(doc.allocate_attribute("y2", idxStr));

			idxStr = doc.allocate_string(std::to_string(line->getStrokeWidth()).c_str());
			child->append_attribute(doc.allocate_attribute("stroke-width", idxStr));
			root->append_node(child);
		}
	}
	//std::string xml_as_string;
	//rapidxml::print(std::back_inserter(xml_as_string), doc);
	ofs << doc;
	ofs.close();
	doc.clear();
}

void UserInterface::exit() {
    std::cout << "Exited program" << std::endl;
    this->clear();
}

void UserInterface::open(const std::string& fileName) {
    std::ifstream ifs(fileName);
    if (!ifs)
    {
        std::cout << "Invalid file name" << std::endl;
		ifs.close();
        return;
    }

    std::string xmlText = "";
    while(ifs.peek() != EOF){
        std::string line;
        std::getline(ifs, line);
        xmlText += line;
    }
    rapidxml::xml_document<> doc;
    char* xmlTextChars = new char[strlen(xmlText.c_str()) + 1];
    strcpy(xmlTextChars, xmlText.c_str());
    doc.parse<0>(xmlTextChars);
    rapidxml::xml_node<>* node = doc.first_node();
    node = node->first_node();
    
    do{
        if(!strcmp(node->name(), "rect")){
            rapidxml::xml_attribute<>* attr = node->first_attribute();
            Rectangle* rect = new Rectangle();
            Point p(parseInt(attr->value()), parseInt(attr->next_attribute()->value()));
            rect->setLeftMostPoint(p);
            attr = attr->next_attribute()->next_attribute();
            rect->setWidth(parseInt(attr->value()));
            attr = attr->next_attribute();
            rect->setHeight(parseInt(attr->value()));
            attr = attr->next_attribute();
            rect->setFill(attr->value());
            shapes.push_back(rect);
        }
        else if(!strcmp(node->name(), "circle")){
            rapidxml::xml_attribute<>* attr = node->first_attribute();
            Circle* circle = new Circle();
            Point p(parseInt(attr->value()), parseInt(attr->next_attribute()->value()));
            circle->setCentre(p);
            attr = attr->next_attribute()->next_attribute();
            circle->setRadius(parseInt(attr->value()));
            attr = attr->next_attribute();
            circle->setFill(attr->value());
            shapes.push_back(circle);
        }
        else if(!strcmp(node->name(), "line")){
            rapidxml::xml_attribute<>* attr = node->first_attribute();
            Line* line = new Line();
            Point p1(parseInt(attr->value()), parseInt(attr->next_attribute()->value()));
            line->setPoint1(p1);
            attr = attr->next_attribute()->next_attribute();
            
            Point p2(parseInt(attr->value()), parseInt(attr->next_attribute()->value()));
            line->setPoint1(p2);
            attr = attr->next_attribute()->next_attribute();
            
            line->setStrokeWidth(parseInt(attr->value()));
            shapes.push_back(line);
        }
        node = node->next_sibling();
    }
    while (node != nullptr);
	currentFile = fileName;
	ifs.close();
}
void UserInterface::clear() {
	if (currentFile.compare("") == 0) {
		std::cout << "There is no opened file!" << std::endl;
		return;
	}
    currentFile = "";
    for (int i = 0; i < this->shapes.size(); i++)
    {
        delete shapes[i];
    }
    shapes.clear();
}

void UserInterface::help() const {
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
    Point p1(std::atoi(params[2].c_str()), std::atoi(params[3].c_str()));
    Point p2(std::atoi(params[4].c_str()), std::atoi(params[5].c_str()));
    Line* newLine = new Line();
    newLine->setPoint1(p1);
    newLine->setPoint2(p2);
    newLine->setStrokeWidth(std::atoi(params[6].c_str()));
    return newLine;
}

Rectangle* UserInterface::createRectangle(const std::vector<std::string>& params) {
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
	if (currentFile.compare("") == 0) {
		std::cout << "There is no opened file!" << std::endl;
		return;
	}
    for(int i = 0; i < shapes.size(); i++){
        std::cout << i + 1 << ". ";
        shapes[i]->print();
        std::cout << std::endl;
    }
}


void UserInterface::create(const std::vector<std::string>& params) {
	if (currentFile.compare("") == 0) {
		std::cout << "There is no opened file!" << std::endl;
		return;
	}
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
	if (currentFile.compare("") == 0) {
		std::cout << "There is no opened file!" << std::endl;
		return;
	}
    if(index > shapes.size()){
        std::cout << "There is no figure number "<< index << "!" << std::endl;
        return;
    }
    BasicShape* figure = this->shapes[index - 1];
    this->shapes.erase(this->shapes.begin() + index - 1);
    std::cout << "Erased a " << figure->getType() << " (" << index << ")" << std::endl;
    delete figure;
}

void UserInterface::within(const std::vector<std::string>& params) {
	if (currentFile.compare("") == 0) {
		std::cout << "There is no opened file!" << std::endl;
		return;
	}
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
	if (currentFile.compare("") == 0) {
		std::cout << "There is no opened file!" << std::endl;
		return;
	}
    if(params.size() >= 3){
        int dy = std::atoi(split(params[1], '=')[1].c_str());
        int dx = std::atoi(split(params[2], '=')[1].c_str());
        
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
        std::getline(std::cin, input);
        std::vector<std::string> params = split(input, ' ');
        std::string cmd = params[0];
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






