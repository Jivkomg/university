

#include <iostream>
#include "PowerUser.h"

PowerUser::PowerUser(): reputation(0), User() {
}

PowerUser::PowerUser(const char* ip, const char* username, const char* password, const char* title, int reputation):
    User(ip, username, password, title), reputation(reputation) {
}

const int PowerUser::getReputation() const { 
    return reputation;
}

void PowerUser::giveReputation(const PowerUser& rhs) {
    if(strcmp(rhs.getUsername(), this->getUsername()) ){
        this->reputation++;
    }
}


