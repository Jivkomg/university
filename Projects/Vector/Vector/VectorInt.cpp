//
//  main.cpp
//  Vector
//
//  Created by Zhivko Georgiev on 12.03.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
#include "VectorInt.h"

MyVector::MyVector():size(0), maxSize(10){
    values = new int[maxSize];
}

MyVector::MyVector(const MyVector& rhs):size(rhs.size), maxSize(rhs.maxSize){
    values = new int[maxSize];
    for(int i = 0; i < size; i++){
        values[i] = rhs.values[i];
    }
}
void MyVector::resize()
{
    maxSize*=2;
    int* newValues = new int[maxSize];
    
    for(int i = 0; i < size; i++)
    {
        newValues[i] = values[i];
    }
    
    delete[] values;
    
    values = newValues;
}

void MyVector::setElement(int pos, int val) { 
    if(pos <= size){
        values[pos] = val;
    }
    else std::cout << "Invalid position \n";
}

void MyVector::pushBack(int val) { 
    if(size == maxSize){
        resize();
    }
    values[size] = val;
    size ++;
}

void MyVector::insert(int pos, int val) {
    if(pos <= size){
        if(size == maxSize){
            resize();
        }
        for(int i = size; i > pos; i--){
            values[i] = values[i - 1];
        }
        values[pos] = val;
        size ++;
        
    }
    else std::cout << "Invalid position \n";
}

void MyVector::remove(int pos) {
    if(pos < size){
        for(int i = pos; i < size - 1; i++){
            values[i] = values[i + 1];
        }
    }
    size--;
}

void MyVector::print() const{
    for(int i = 0; i < size; i++){
        std::cout << values[i] << ' ';
    }
    std::cout << std::endl;
}

int MyVector::getElement(int pos) const { 
    if(pos < size){
        return values[pos];
    }
    else{
        std::cout << "Invalid position" << std::endl;
        return -1;
    }
}

int MyVector::popBack() {
    if(size != 0){
        size--;
        return values[size - 1];
    }
    else {
        std::cout << "NO elementrs \n";
        return -1;
    }
}

int MyVector::begin() const { 
    if(size != 0){
        return values[0];
    }
    else {
        std::cout << "NO elements \n";
        return -1;
    }
}

int MyVector::end() const { 
    
    if(size != 0){
        return values[size - 1];
    }
    else {
        std::cout << "NO elements \n";
        return -1;
    }
}

int MyVector::getSize() const {
    return size;
}

MyVector& MyVector::operator=(const MyVector& rhs){
    if(this != &rhs){
        size = rhs.size;
        maxSize = rhs.maxSize;
        
        delete[] values;
        
        values = new int[maxSize];
        for(int i = 0; i < size; i ++){
            values[i] = rhs.values[i];
        }
    }
    return *this;
}

int MyVector::operator[](int a){
    return values[a];
}

MyVector::~MyVector(){
    delete[] values;
}

