//
//  Phone.h
//  SmartDevices
//
//  Created by Zhivko Georgiev on 18.05.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef Phone_h
#define Phone_h

class Phone{
protected:
    char* name;
    int screenSize;
    int number;
public:
    Phone();
    Phone(const char*, int, int);
    Phone(const Phone&);
    void setName(const char*);
    void setScreenSize(int);
    void setNumber(int);
    
    const char* getName() const;
    const int getScreenSize() const;
    const int getNumber() const;
    void call(const Phone&) const;
    void print() const;
    Phone& operator=(const Phone&);
    ~Phone();
};
#endif /* Phone_h */
