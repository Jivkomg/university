//
//  Boss.h
//  Work
//
//  Created by Zhivko Georgiev on 1.04.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//
#ifndef Boss_h
#define Boss_h
#include "Worker.h"
class Boss{
private:
    char* name;
    char* surname;
    int currentMoney;
public:
    Boss(); // default
    Boss(const Boss&); // copy
    
    void setName(const char*);
    void setSurname(const char*);
    void setMoney(const int);
    
    char* getName() const;
    char* getSurname() const;
    int getMoney() const;
    
    Boss& operator=(const Boss&);
    void getMoneyFromTheWorker(Worker&);
    ~Boss();


};

#endif /* Boss_h */
