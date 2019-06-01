//
//  main.cpp
//  Car
//
//  Created by Zhivko Georgiev on 7.03.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include <iostream>

struct Car{
    char manufacture[50];
    char model[50];
    int horsepower;
    int price;
};

void fillCarInfo(Car& car){
    std::cin >> car.manufacture;
    std::cin >> car.model;
    std::cin >> car.horsepower;
    std::cin >> car.price;
}

void printCarInfo(const Car& car){
    std::cout << car.manufacture << " " << car.model << std::endl;
    std::cout << car.horsepower << std::endl;
    std::cout << car.price << std::endl;
}


int main(int argc, const char * argv[]) {
    int n;
    std::cin >> n;
    Car* cars = new Car[n];
    for(int i = 0; i < n; i++){
        fillCarInfo(cars[i]);
    }
    int p, w;
    std::cin >> p >> w;
    for(int i = 0; i < n; i++)
    {
        if(cars[i].price <= p) printCarInfo(cars[i]); //Извеждаме информация за колата, съотвестваща на критерия цена
        if(cars[i].horsepower >= w) printCarInfo(cars[i]); //Извеждаме информация за колата, съотвестваща на критерия мощност
    }
    
    return 0;
}
