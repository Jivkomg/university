//
//  main.cpp
//  Login
//
//  Created by Zhivko Georgiev on 11.03.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
#include "Login.h"
//QUESTION order - constructors, getters, setters?

//constructors
//default
Login::Login():typeOfSession(0){
    username = new char[1];
    username[0] = '0';
    
    password = new char[1];
    password[0] = '0';
}

//1 parameter
Login::Login(const char* username):typeOfSession(1){
    size_t size = strlen(username);
    username = new char[size + 1];
    strcpy(this->username, username);
    
//    version 1
    size_t passSize;
    std::cout << "Enter password: " <<std::endl;
    std::cin >> passSize;
    password = new char[passSize + 1];
    std::cin >> password;
//    version 2
//    password = new char[50];
//    std::cin.get(password, 50);
}
//2 parameters
Login::Login(const char* username,const char* password):typeOfSession(1){
    size_t sizeUsername = strlen(username);
    username = new char[sizeUsername + 1];
    strcpy(this->username, username);
    
    size_t sizePassword = strlen(password);
    password = new char[sizePassword + 1];
    strcpy(this->password, password);
}
//3 parameters
Login::Login(const char* username, const char* password, const int typeOfSession){
    size_t sizeUsername = strlen(username);
    username = new char[sizeUsername + 1];
    strcpy(this->username, username);
    
    size_t sizePassword = strlen(password);
    password = new char[sizePassword + 1];
    strcpy(this->password, password);
    
    this-> typeOfSession = typeOfSession;
}
//copy constructor
Login::Login(const Login& l){
    size_t sizeUsername = strlen(username);
    username = new char[sizeUsername + 1];
    strcpy(this->username, l.username);
    
    size_t sizePassword = strlen(password);
    password = new char[sizePassword + 1];
    strcpy(this->password, l.password);
    
    typeOfSession = l.typeOfSession;
}

//setters
void Login::setSession(const int typeOfSession){
    this->typeOfSession = typeOfSession;
}
void Login::setUsername(const char* username){
    size_t size = strlen(username);
    this->username = new char[size];
    strcpy(this->username, username);
}
void Login::setPassword(const char* password){
    size_t size = strlen(password);
    this->password = new char[size];
    strcpy(this->password, password);
}

void Login::print() const{
    std::cout << "USername: " << username << " Password: " << password <<
        " SessionType: " << typeOfSession << std::endl;
}

//getters
char* Login::getUsername() const{
    return username;
}

char* Login::getPassword() const{
    return password;
}
int Login::getTypeOfSession() const{
    return typeOfSession;
}
