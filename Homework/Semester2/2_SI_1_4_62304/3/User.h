//
//  User.h
//  LoginSystem
//
//  Created by Zhivko Georgiev on 14.05.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include "Guest.h"
class User: public Guest{
protected:
    char* username;
    char* password;
    char* title;
public:
    User();
    User(const char*, const char*, const char*, const char*);
    User(const User&);
    void setPassword(const char*);
    const char* getPassword() const;
    const char* getUsername() const;
    const char* getTitle() const;

    friend class Admin;
    User& operator=(const User&);
    ~User();
};

#endif /* Header_h */
