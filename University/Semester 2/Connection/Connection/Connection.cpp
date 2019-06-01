//
//  Connection.cpp
//  Connection
//
//  Created by Zhivko Georgiev on 2.04.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//
#include <iostream>
#include "Connection.h"

Connection::Connection(){
    ipToConnect = nullptr;
    whoami = nullptr;
}

Connection::Connection(const Connection& rhs){
    size_t len = strlen(rhs.ipToConnect);
    this->ipToConnect = new char[len + 1];
    strcpy(this->ipToConnect, rhs.ipToConnect);

    len = strlen(rhs.whoami);
    this->whoami = new char[len + 1];
    strcpy(this->whoami, rhs.whoami);
}

Connection& Connection::operator=(const Connection& rhs){
    if(this!= &rhs){
        delete[] ipToConnect;
        delete[] whoami;
        
        size_t len = strlen(rhs.ipToConnect);
        this->ipToConnect = new char[len + 1];
        strcpy(this->ipToConnect, rhs.ipToConnect);
        
        len = strlen(rhs.whoami);
        this->whoami = new char[len + 1];
        strcpy(this->whoami, rhs.whoami);
    }
    return *this;
}

void connectTo(char* ipToConnectTo, char* itsMe){
//    size_t len = strlen(ipToConnectTo);
//    this->whoami = new char[len + 1];
//    strcpy(this->whoami, rhs.its);

}
Connection::~Connection(){
    delete [] ipToConnect;
    delete [] whoami;
}


