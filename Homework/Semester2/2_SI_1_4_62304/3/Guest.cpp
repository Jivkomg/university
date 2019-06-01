

#include <iostream>
#include "Guest.h"

Guest::Guest() { 
    ipAddress = new char[1];
    ipAddress[0] = '\0';
}

Guest::Guest(const char* ip) {
    size_t len = strlen(ip);
    ipAddress = new char[len + 1];
    strcpy(ipAddress, ip);
}

Guest::Guest(const Guest& rhs) {
    size_t len = strlen(rhs.ipAddress);
    ipAddress = new char[len + 1];
    strcpy(ipAddress, rhs.ipAddress);
}

void Guest::setIpAddress(const char* ip) {
    size_t len = strlen(ip);
    ipAddress = new char[len + 1];
    strcpy(ipAddress, ip);
}

const char* Guest::getIpAddress() const {
    return ipAddress;
}

Guest& Guest::operator=(const Guest& rhs) {
    if(this != &rhs){
        delete[] ipAddress;
        size_t len = strlen(rhs.ipAddress);
        ipAddress = new char[len + 1];
        strcpy(ipAddress, rhs.ipAddress);
    }
    return *this;
}

Guest::~Guest() { 
    delete[] ipAddress;
}


