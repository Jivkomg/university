//
//  main.cpp
//  Work
//
//  Created by Zhivko Georgiev on 1.04.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//
#include <iostream>
#include "Boss.h"


int main(int argc, const char * argv[]) {
    Worker w = Worker();
    w.setName("Pesho");
    w.setSurname("Peshov");
    w.setSalary(10000);
    
    Boss b = Boss();
    b.setName("Pablo");
    b.setSurname("Escobar");
    b.setMoney(20000);
    
    b.getMoneyFromTheWorker(w);
    std::cout <<"New money(Boss) "<< b.getMoney() << std::endl;
   // std::cout << "New monew(worker)" << w.
    return 0;
}
