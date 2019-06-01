//
//  main.cpp
//  DNS Cache
//
//  Created by Zhivko Georgiev on 10.04.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
#include "DNSCache.h"
int main() {
    DNSRecord record1 = DNSRecord("d1", "123");
    DNSRecord record2 = DNSRecord("d2", "234");
    DNSRecord record3 = DNSRecord("d3", "345");
    DNSRecord record4 = DNSRecord("d4", "456");
    DNSRecord record5 = DNSRecord("d5", "567");
    
    DNSCache cache = DNSCache();
    cache.add(record1);
    cache.add(record2);
    cache.add(record3);
    cache.add(record4);
    cache.add(record5);

    cache.print();
    if(cache.lookup("d1") != NULL){
        std::cout << cache.lookup("d1") << std::endl;
    }
    else {
        std::cout << "No record of it" << std::endl;
    } 
    cache.flush();
    cache.print();
//    std::cout << cache.lookup("d1") << std::endl;
//    std::cout << cache.lookup("bla") << std::endl;
//
    return 0;
}
