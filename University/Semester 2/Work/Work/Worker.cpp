//
//  Worker.cpp
//  Work
//
//  Created by Zhivko Georgiev on 1.04.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//
#include <iostream>
#include "Worker.h"

Worker::Worker(): salary(0){
    name = new char[1];
    name[0] = '\0';
    surname = new char[1];
    name[0] = '\0';
}

Worker::Worker(const Worker& rhs): salary(rhs.salary){
    size_t len = strlen(rhs.name);
    name = new char[len + 1];
    strcpy(this->name, rhs.name);

    len = strlen(rhs.surname);
    surname = new char[len + 1];
    strcpy(this->surname, rhs.surname);
}

void Worker::setName(const char* name) {
    size_t len = strlen(name);
    this->name = new char[len + 1];
    strcpy(this->name, name);
}

void Worker::setSurname(const char * surname) {
    size_t len = strlen(surname);
    this->surname = new char[len + 1];
    strcpy(this->surname, surname);

}

void Worker::setSalary(const int salary) {
    this->salary = salary;
}

Worker& Worker::operator=(const Worker& rhs){
    if(this != &rhs){
        salary = rhs.salary;
        delete[] name;
        delete[] surname;
        
        name = new char[strlen(rhs.name) + 1];
        strcpy(this->name, rhs.name);
        surname = new char[strlen(rhs.surname) + 1];
        strcpy(this->surname, rhs.surname);
    }
    return *this;
}

Worker::~Worker(){
    delete[] name;
    delete[] surname;
}

