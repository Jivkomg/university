//
//  Login.h
//  Login
//
//  Created by Zhivko Georgiev on 11.03.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef Login_h
#define Login_h

class Login{
private:
    char* username;
    char* password;
    int typeOfSession;
public:
    Login();
    Login(const char* username);
    Login(const char* username,const char* password);
    Login(const char* username,const char* password,const int typeOfSession);
    Login(const Login& l);
        
    void setPassword(const char* username);
    void setUsername(const char* password);
    void setSession(const int typeOfSession);
    
    void print() const;
    int getTypeOfSession() const;
    char* getUsername() const;
    char* getPassword() const;
    
};

#endif /* Login_h */
