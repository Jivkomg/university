
#include <iostream>
#include "User.h"

char* encryptPassword(char* inpString)
{
    char xorKey = 'Z';
    size_t len = strlen(inpString);
    char* retString = new char[len + 1];
    for (int i = 0; i < len; i++)
    {
        retString[i] = inpString[i] ^ xorKey;
    }
    return retString;
}

User::User() : Guest() {
    username = new char[1];
    username[0] = '\0';
    password = new char[1];
    password[0] = '\0';
    title = new char[1];
    title[0] = '\0';
}

User::User(const char* ip, const char* username, const char* password, const char* title):Guest(ip) { 
    size_t len = strlen(username);
    this->username = new char[len + 1];
    strcpy(this->username, username);
    
    len = strlen(password);
    this->password = new char[len + 1];
    strcpy(this->password, password);

    len = strlen(title);
    this->title = new char[len + 1];
    strcpy(this->title, title);
}

User::User(const User& rhs) : Guest(rhs){ 
    size_t len = strlen(rhs.username);
    this->username = new char[len + 1];
    strcpy(this->username, rhs.username);
    
    len = strlen(rhs.password);
    this->password = new char[len + 1];
    strcpy(this->password, rhs.password);
    
    len = strlen(rhs.title);
    this->title = new char[len + 1];
    strcpy(this->title, rhs.title);
}

void User::setPassword(const char* newPass) {
    char* oldPass = new char[strlen(password) + 1];
    std::cout << "Enter old password" << std::endl;
    std::cin >> oldPass;
    if(!strcmp(oldPass, password)){
        delete[] password;
        password = new char[strlen(newPass) + 1];
        strcpy(this->password, newPass);
        std::cout << "Password changed!" << std::endl;
    }
    else{
        std::cout << "Wrong password!" << std::endl;
    }
}

const char* User::getPassword() const {
    return encryptPassword(password);
}

const char* User::getUsername() const {
    return username;
}

const char* User::getTitle() const {
    return title;
}


User& User::operator=(const User& rhs) {
    if(this != &rhs){
        Guest::operator=(rhs);
        delete[] username;
        delete[] password;
        delete[] title;
        size_t len = strlen(username);
        this->username = new char[len + 1];
        strcpy(this->username, username);
        
        len = strlen(password);
        this->password = new char[len + 1];
        strcpy(this->password, password);
        
        len = strlen(title);
        this->title = new char[len + 1];
        strcpy(this->title, title);
        
    }
    return *this;;
}

User::~User() { 
    delete[] username;
    delete[] password;
    delete[] title;
}



