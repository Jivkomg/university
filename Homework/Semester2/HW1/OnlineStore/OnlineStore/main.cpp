//
//  main.cpp
//  OnlineStore
//
//  Created by Zhivko Georgiev on 10.04.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
#include "Store.h"
int main() {
    std::cout << "-------------Guitar World-------------\n";
    std::cout << "A         Add new product\n";
    std::cout << "X         Delete product\n";
    std::cout << "C         Change product\n";
    std::cout << "D         Display roducts\n";
    std::cout << "Q         Quit\n";
    
    Product p1 = Product("1fo241", "Gibson", "Les Paul", "Electric", 5700, 2);
    Product p2 = Product("52fqj3", "Cort", "KX 5", "Electric", 500, 1);
    Product p3 = Product("1yks02", "Yamaha", "Pacifica 112V", "Electric", 4350, 3);
    Product p4 = Product("124skg", "Kala", "KA-15S", "Ukulele", 120, 1);
    Product p5 = Product("523sk2", "Yamaha", "F310", "Acoustic", 3000, 4);

    Product p6 = Product("ghi033", "Ibanez", "RG550", "Electric", 3500, 1);
    
    
    Store myStore = Store();
    myStore.addProduct(p1);
    myStore.addProduct(p2);
    myStore.addProduct(p3);
    myStore.addProduct(p4);
    myStore.addProduct(p5);
    Product pA;
    pA = p1;
    

    char input;
    do{
        std::cin >> input;
        if(input == 'D'){
            myStore.displayProducts();
        }
        else if(input == 'A'){
            std::cout << "Enter a new product" << std::endl;
            Product p;
            std::cin >> p;
            myStore.addProduct(p);
        }
        else if(input == 'X'){
            std::cout << "Enter position" << std::endl;
            int pos;
            std::cin >> pos;
            myStore.deleteProduct(pos);
        }
        else if(input == 'C'){
            std::cout << "Enter a new product" << std::endl;
            Product p;
            std::cin >> p;
            std::cout << "Enter position" << std::endl;
            int pos;
            std::cin >> pos;
            myStore.changeProduct(pos, p);
        }
        else{
            continue;
        }
    }
    while(input != 'Q');
    
    return 0;
}
