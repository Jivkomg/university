//
//  Product.cpp
//  OnlineStore
//
//  Created by Zhivko Georgiev on 10.04.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
#include "Product.h"

Product::Product(): price(0), count(0) {
    SKU = new char[1];
    SKU[0] = '\0';
    brand = new char[1];
    brand[0] = '\0';
    model = new char[1];
    model[0] = '\0';
    category = new char[1];
    category[0] = '\0';}

Product::Product(const Product& rhs): price(rhs.price), count(rhs.count) {
    size_t len = strlen(rhs.SKU);
    SKU = new char[len + 1];
    strcpy(this->SKU, rhs.SKU);

    len = strlen(rhs.brand);
    brand = new char[len + 1];
    strcpy(this->brand, rhs.brand);

    len = strlen(rhs.model);
    model = new char[len + 1];
    strcpy(this->model, rhs.model);

    len = strlen(rhs.category);
    category = new char[len + 1];
    strcpy(this->category, rhs.category);
}

Product::Product(const char* sku, const char* brand, const char* model,
                 const char* category, int price, int count): price(price), count(count){
    size_t len = strlen(sku);
    SKU = new char[len + 1];
    strcpy(this->SKU, sku);
    
    len = strlen(brand);
    this->brand = new char[len + 1];
    strcpy(this->brand, brand);
    
    len = strlen(model);
    this->model = new char[len + 1];
    strcpy(this->model, model);
    
    len = strlen(category);
    this->category = new char[len + 1];
    strcpy(this->category, category);
}


char* Product::getSKU() const {
    return SKU;
}

void Product::setSKU(const char* sku) {
    size_t len = strlen(sku);
    SKU = new char[len + 1];
    strcpy(this->SKU, sku);
}

char* Product::getBrand() const {
    return brand;
}

void Product::setBrand(const char* brand) {
    size_t len = strlen(brand);
    this->brand = new char[len + 1];
    strcpy(this->brand, brand);
;
}

char* Product::getModel() const {
    return model;
}

void Product::setModel(const char* model) {
    size_t len = strlen(model);
    this->model = new char[len + 1];
    strcpy(this->model, model);
;
}

char* Product::getCategory() const {
    return category;
}

void Product::setCategory(const char* category) {
    size_t len = strlen(category);
    this->category = new char[len + 1];
    strcpy(this->category, category);
;
}

int Product::getPrice() const {
    return price;
}

void Product::setPrice(int price) {
    this->price = price;
}

int Product::getCount() const {
    return count;
}

void Product::setCount(int count) {
    this->count = count;
}

void Product::printProduct() const{
    std::cout << "SKU: " << SKU << std::endl;
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Category: " << category << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << "Count: " << count << std::endl;
}

Product& Product::operator=(const Product& rhs) {
    if(this != &rhs){
        delete[] SKU;
        size_t len = strlen(rhs.SKU);
        SKU = new char[len + 1];
        strcpy(this->SKU, rhs.SKU);
        
        delete[] brand;
        len = strlen(rhs.brand);
        brand = new char[len + 1];
        strcpy(this->brand, rhs.brand);
        
        delete[] model;
        len = strlen(rhs.model);
        model = new char[len + 1];
        strcpy(this->model, rhs.model);
        
        delete[] category;
        len = strlen(rhs.category);
        category = new char[len + 1];
        strcpy(this->category, rhs.category);

        price = rhs.price;
        count = rhs.count;
    }
    return *this;
}
std::istream& operator>>(std::istream& in, Product& product){
    std::cout << "Enter price: ";
    in >> product.price;
    std::cout << "Enter count: ";
    in >> product.count;
    std::cout << "Enter SKU: ";
    char* tmp = new char[100];
    in >> tmp;
    product.setSKU(tmp);
    std::cout << "Enter brand: ";
    in >> tmp;
    product.setBrand(tmp);
    std::cout << "Enter model: ";
    in >> tmp;
    product.setModel(tmp);
    std::cout << "Enter category: ";
    in >> tmp;
    product.setCategory(tmp);
    return in;
}
Product::~Product() { 
    delete[] SKU;
    delete[] brand;
    delete[] model;
    delete[] category;
}

