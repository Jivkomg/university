//
//  Connection.h
//  Connection
//
//  Created by Zhivko Georgiev on 1.04.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef Connection_h
#define Connection_h
class Connection{
private:
    char* ipToConnect;
    char* whoami;
public:
    Connection(); //default
    Connection(const Connection&); // copy
    Connection& operator=(const Connection&);
    friend void connectTo(char* ipToConnectTo, char* itsMe);
    ~Connection(); //destructor
};

#endif /* Connection_h */
