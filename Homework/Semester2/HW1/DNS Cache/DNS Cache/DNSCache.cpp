//
//  DNSCache.cpp
//  DNS Cache
//
//  Created by Zhivko Georgiev on 10.04.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include "DNSCache.h"
#include <iostream>
DNSCache::DNSCache(): size(0), capacity(10) { 
    records = new DNSRecord[capacity];
}

DNSCache::DNSCache(const DNSCache& rhs): size(rhs.size), capacity(rhs.capacity) {
    records = new DNSRecord[rhs.capacity];
    for(int i = 0; i < size; i++){
        records[i] = rhs.records[i];
    }
}

void DNSCache::resize(){
    capacity *= 2;
    DNSRecord* newRecords = new DNSRecord[capacity];
    for(int i = 0; i < size; i++){
        newRecords[i] = records[i];
    }
    delete[] records;
    records = newRecords;
}

void DNSCache::add(const DNSRecord& record) {
    if(size == capacity){
        resize();
    }
    records[size] = record;
    size++;
}

char* DNSCache::lookup(const char* name) const {
    for(int i = 0; i < size; i++){
        if(strlen(name) == strlen(records[i].getDomainName())){
            if(!strcmp(name, records[i].getDomainName())){
                return records[i].getIpAddress();
            }
        }
    }
    return NULL;
}

void DNSCache::flush() { 
    delete[] records;
    size = 0;
    capacity = 10;
    records = new DNSRecord[capacity];
}

void DNSCache::print() const { 
    for(int i = 0; i < size; i++){
        std::cout << "DomainName: "<< records[i].getDomainName() <<
        " IpAddres: " << records[i].getIpAddress() << std::endl;
    }
}

DNSCache& DNSCache::operator=(const DNSCache& rhs) {
    if(this != &rhs){
        size = rhs.size;
        capacity = rhs.capacity;
        delete[] records;
        records = new DNSRecord[rhs.capacity];
        for(int i = 0; i < size; i++){
            records[i] = rhs.records[i];
        }
    }
    return *this;
}

DNSCache::~DNSCache() { 
    delete[] records;
}
