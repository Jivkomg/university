

#include <iostream>
#include "Admin.h"


Admin::Admin(): VIP(), PowerUser() {
}

void Admin::setUsername(const char* rhs) {
    if(strcmp(username, rhs)){
        delete[] username;
        username = new char[strlen(rhs) + 1];
        strcpy(this->username, rhs);
    }
}

void Admin::setOthersUsername(const char* rhs, User& u) {
    if(strcmp(u.username, rhs)){
        delete[] u.username;
        u.username = new char[strlen(rhs) + 1];
        strcpy(u.username, rhs);
    }
}

Admin::Admin(const char* ip, const char* username, const char* password, const char* title, int reputation):
    PowerUser(ip, username, password, title, reputation) {
}

