//
//  Phone.cpp
//  SmartDevices
//
//  Created by Zhivko Georgiev on 18.05.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
#include "Phone.h"


Phone::Phone(): screenSize(0), number(0) {
    name = new char[1];
    name[0] = '\0';
    
}

Phone::Phone(const char* name, int size, int num):screenSize(size), number(num) {
    size_t len = strlen(name);
    this->name = new char[len + 1];
    strcpy(this->name, name);
}

Phone::Phone(const Phone& rhs):screenSize(rhs.screenSize), number(rhs.number)  {
    size_t len = strlen(rhs.name);
    this->name = new char[len + 1];
    strcpy(this->name, rhs.name);
}

void Phone::setName(const char* name) {
    size_t len = strlen(name);
    this->name = new char[len + 1];
    strcpy(this->name, name);
}

void Phone::setScreenSize(int size) {
    screenSize = size;
}

void Phone::setNumber(int num) {
    number = num;
}

const char* Phone::getName() const {
    return name;
}

const int Phone::getScreenSize() const {
    return screenSize;
}

const int Phone::getNumber() const {
    return number;
}

void Phone::call(const Phone &) const { 
    //bla;
}

void Phone::print() const { 
    std::cout << name << " " << screenSize << " " << number;
}

Phone& Phone::operator=(const Phone& rhs) {
    if(this != &rhs){
        delete[] name;
        screenSize = rhs.screenSize;
        number = rhs.number;
        size_t len = strlen(rhs.name);
        this->name = new char[len + 1];
        strcpy(this->name, rhs.name);
    }
    return *this;
}

Phone::~Phone() { 
    delete[] name;
}


