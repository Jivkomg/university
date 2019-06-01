//
//  DNSCache.h
//  DNS Cache
//
//  Created by Zhivko Georgiev on 10.04.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef DNSCache_h
#define DNSCache_h

#include "DNSRecord.h"
class DNSCache{
private:
    int size;
    int capacity;
    DNSRecord* records;
public:
    DNSCache(); //default
    DNSCache(const DNSCache&); //copy
    
    void resize();
    void add(const DNSRecord&);
    char* lookup(const char*) const;
    void flush();
    void print() const;
    DNSCache& operator=(const DNSCache&); //operator =
    ~DNSCache(); //destructor

};

#endif /* DNSCache_h */
