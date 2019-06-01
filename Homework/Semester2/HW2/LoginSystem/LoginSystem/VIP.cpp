

#include <iostream>
#include "VIP.h"

VIP::VIP(): User() { 
}

void VIP::setTitle(const char* rhs) { 
    if(strcmp(title, rhs)){
        delete[] User::title;
        title = new char[strlen(rhs) + 1];
        strcpy(this->title, rhs);
    }
    
}

VIP::VIP(const char* ip, const char* username, const char* password, const char* title):
    User(ip, username, password, title) {
}

