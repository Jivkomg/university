////
////  XMLParser.cpp
////  SVG_Project
////
////  Created by Zhivko Georgiev on 21.06.19.
////  Copyright © 2019 Zhivko Georgiev. All rights reserved.
////
//
//#include "XMLParser.h"
//#include <iostream>
//#include <fstream>
//
//
////bool XMLParser::readString(const std::string& fileName, std::string& input) {
////    std::ifstream inputFile(fileName, std::ios_base::binary);
////    if (inputFile.fail()) {
////        return false; // Failed to open file
////    }
////
////    if (inputFile.is_open()) {
////        char next;
////        while (inputFile.get(next)) {
////            input.push_back(next);
////        }
////    }
////    inputFile.close();
////    return true; // Successfully read file
////}
////
////bool XMLParser::writeString(const std::string& fileName, std::string& output) {
////    std::ofstream outputFile(fileName, std::ios_base::binary);
////    if (outputFile.fail()) {
////        return false; // Failed to open file
////    }
////    outputFile << output;
////    outputFile.close();
////    return true; // Successfully wrote to file
////}
////
////void XMLParser::convertSVGtoCircle(const std::string& circleSVG, std::vector<std::string>& params) {
////    Circle* newCircle;
////    if(circleSVG.find("cx")){
////
////    }
////}
////
//
//
//
//void XMLParser::startSerialize(std::ostream& os) const {
//    os << "<" << this->getType() << " ";
//}
//
//void XMLParser::endSerialize(std::ostream& os) const {
//    os << "/>\n";
//}
//
//void XMLParser::serializeWithParameters(std::ostream& os, const std::string& name, const std::string& value) const {
//    os << name << "=\"" << value << "\" ";
//}
