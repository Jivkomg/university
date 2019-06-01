//
//  Store.cpp
//  OnlineStore
//
//  Created by Zhivko Georgiev on 12.04.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
#include "Store.h"
//TODO SKU
Store::Store(): productsCnt(0), capacity(10) {
    products =  new Product[capacity];
}

Store::Store(const Store& rhs): productsCnt(rhs.productsCnt), capacity(rhs.capacity) {
    products = new Product[rhs.capacity];
    for(int i = 0; i < rhs.productsCnt; i++){
        products[i] = rhs.products[i];
    }
}
void Store::resize() {
    capacity *= 2;
    Product* newProducts = new Product[capacity];
    for(int i = 0; i < productsCnt; i++){
        products[i] = newProducts[i];
    }
    delete[] products;
    products = newProducts;
}


void Store::addProduct(const Product& product) {
    if(productsCnt == capacity){
        resize();
    }
    products[productsCnt] = product;
    productsCnt++;
}

void Store::deleteProduct(int pos) { 
    if(pos < productsCnt){
        for(int i = pos; i < productsCnt - 1; i++){
            products[i] = products[i + 1];
        }
        productsCnt--;
    }
    else{
        std::cout << "Wrong input\n";
    }
}

void Store::changeProduct(int pos, const Product& product) {
    if(pos < productsCnt){
        products[pos] = product;
    }
    else{
        std::cout << "Wrong input\n";
    }
}
void Store::displayProducts() const { 
    std::cout << "There are currently " << productsCnt << " products in stock \n";
    for(int i = 0; i < productsCnt; i++){
        std::cout << "Product " << i << ": \n";
        products[i].printProduct();
        std::cout << std::endl;
    }
}

Store& Store::operator=(const Store& rhs) {
    if(this != &rhs){
        productsCnt = rhs.productsCnt;
        capacity = rhs.capacity;
        delete[] products;
        products = new Product[rhs.capacity];
        for(int i = 0; i < rhs.productsCnt; i++){
            products[i] = rhs.products[i];
        }
    }
    return *this;
}

Store::~Store() { 
    delete[] products;
}


