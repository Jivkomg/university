//
//  Boss.cpp
//  Work
//
//  Created by Zhivko Georgiev on 1.04.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//
#include <iostream>
#include "Boss.h"
Boss::Boss(): currentMoney(0){
    name = new char[1];
    name[0] = '\0';
    surname = new char[1];
    name[0] = '\0';
}
Boss::Boss(const Boss& rhs): currentMoney(rhs.currentMoney){
    size_t len = strlen(rhs.name);
    name = new char[len];
    strcpy(this->name, rhs.name);
    
    len = strlen(rhs.surname);
    surname = new char[len];
    strcpy(this->surname, rhs.surname);
}

void Boss::setName(const char* name) {
    size_t len = strlen(name);
    this->name = new char[len + 1];
    strcpy(this->name, name);
}

void Boss::setSurname(const char * surname) {
    size_t len = strlen(surname);
    this->surname = new char[len + 1];
    strcpy(this->surname, surname);
}


char* Boss::getName() const {
    return this->name;
}

char* Boss::getSurname() const {
    return this->surname;
}

int Boss::getMoney() const {
    return this->currentMoney;
}

void Boss::setMoney(const int money) {
    this->currentMoney = money;
}

Boss& Boss::operator=(const Boss& rhs){
    if(this != &rhs){
        currentMoney = rhs.currentMoney;
        delete[] name;
        delete[] surname;
        
        name = new char[strlen(rhs.name)];
        surname = new char[strlen(rhs.surname)];
    }
    return *this;
}

void Boss::getMoneyFromTheWorker(Worker& worker){
    //takes half the money
    int difference = worker.salary/2;
    worker.salary -= difference;
    this->currentMoney += difference;
    std::cout << "Peshos money" << worker.salary << std::endl;
}
Boss::~Boss(){
    delete[] name;
    delete[] surname;
}


