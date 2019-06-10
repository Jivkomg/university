//
//  File.cpp
//  FileSystem
//
//  Created by Zhivko Georgiev on 28.05.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
#include "File.h"

File::File() { 
    name = "New file";
    extension = "";
    dateCreated = "18-30-10::04-06-2019";
    size = 0;
    insideNumber = 0;
    information.push_back('\0');
}

File::File(std::string n, std::string e, int s, std::vector<char> i, int in, std::string d) {
    name = n;
    extension = e;
    dateCreated = d;
    size = s;
    insideNumber = in;
    information = i;
}

void File::setName(const std::string& newName) {
    name = newName;
}

void File::setExtension(const std::string& newExtension) {
    extension = newExtension;
}

void File::setDateCreated(const std::string& newDate) {
    dateCreated = newDate;
}

void File::setSize(const int newSize) {
    size = newSize;
}

void File::setInformation(const std::vector<char>& newInformation) {
    information = newInformation;
}

void File::setInsideNumber(const int newNumber) {
    insideNumber = newNumber;
}

const std::string File::getName() const { 
    return name;
}

const std::string File::getExtension() const { 
    return extension;
}

const std::string File::getDateCreated() const { 
    return dateCreated;
}

const std::vector<char> File::getInformation() const { 
    return information;
}

const int File::getSize(int) const { 
    return size;
}

const int File::getInsideNumber(int) const { 
    return insideNumber;
}
