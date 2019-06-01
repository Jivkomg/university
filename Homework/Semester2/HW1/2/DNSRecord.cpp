//
//  DNSRecord.cpp
//  DNS Cache
//
//  Created by Zhivko Georgiev on 10.04.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include "DNSRecord.h"
#include <iostream>
DNSRecord::DNSRecord(){
    domainName = new char[1];
    domainName[0] = '\0';
    ipAddress =  new char[1];
    ipAddress[0] = '\0';
}

DNSRecord::DNSRecord(const char* name, const char* address){
    size_t len = strlen(name);
    domainName = new char[len + 1];
    strcpy(this->domainName, name);

    len = strlen(address);
    ipAddress = new char[len + 1];
    strcpy(this->ipAddress, address);
}

DNSRecord::DNSRecord(const DNSRecord& rhs) {
    size_t len = strlen(rhs.domainName);
    domainName = new char[len + 1];
    strcpy(this->domainName, rhs.domainName);
    
    len = strlen(rhs.ipAddress);
    ipAddress = new char[len + 1];
    strcpy(this->ipAddress, rhs.ipAddress);
}

char* DNSRecord::getIpAddress() const {
    return ipAddress;
}

char* DNSRecord::getDomainName() const {
    return domainName;
}

DNSRecord& DNSRecord::operator=(const DNSRecord& rhs) {
    if(this != &rhs){
        size_t len = strlen(rhs.domainName);
        delete[] domainName;
        domainName = new char[len + 1];
        strcpy(this->domainName, rhs.domainName);
        
        len = strlen(rhs.ipAddress);
        delete[] ipAddress;
        ipAddress = new char[len + 1];
        strcpy(this->ipAddress, rhs.ipAddress);
        
    }
    return *this;
}

DNSRecord::~DNSRecord(){
    delete[] domainName;
    delete[] ipAddress;
}






