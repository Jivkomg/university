//
//  Worker.h
//  Work
//
//  Created by Zhivko Georgiev on 1.04.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//
#ifndef Worker_h
#define Worker_h
class Worker{
private:
    char* name;
    char* surname;
    int salary;
public:
    Worker(); // default
    Worker(const Worker&); // copy
    
    void setName(const char*);
    void setSurname(const char*);
    void setSalary(const int);
    Worker& operator=(const Worker&);
    
    friend class Boss;
    ~Worker(); // destructor
};
#endif /* Worker_h */
