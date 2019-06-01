//
//  DNSRecord.h
//  DNS Cache
//
//  Created by Zhivko Georgiev on 10.04.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef DNSRecord_h
#define DNSRecord_h
class DNSRecord{
private:
    char* domainName;
    char* ipAddress;
public:
    DNSRecord(); //default
    DNSRecord(const char*, const char*); //two parameters
    DNSRecord(const DNSRecord&); //copy
    
    char* getIpAddress() const;
    char* getDomainName() const;
    DNSRecord& operator=(const DNSRecord&); //operator =
    ~DNSRecord(); //destructor
};

#endif /* DNSRecord_h */
