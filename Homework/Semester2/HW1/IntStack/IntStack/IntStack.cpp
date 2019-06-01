//
//  IntStack.cpp
//  IntStack
//
//  Created by Zhivko Georgiev on 9.04.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//
#include "IntStack.h"
#include <iostream>

IntStack::IntStack(): top(-1), capacity(MAX) {
    values = new int [capacity];
}

IntStack::IntStack(const IntStack& rhs): top(rhs.top),capacity(rhs.capacity) {
    values = new int[capacity];
    for(int i = 0; i < top; i++){
        values[i] = rhs.values[i];
    }
}

bool IntStack::empty() const { 
    return top == -1;
}

int IntStack::peek() const { 
    if(!empty()){
        return values[top];
    }
    else{
        std::cout << "No elements" << std::endl;
        return 0;
    }
}

void IntStack::resize() {
    int* newValues = new int[capacity * 2];
    for(int i = 0; i < top; i++){
        newValues[i] = values[i];
    }
    delete[] values;
    values = newValues;
    capacity *= 2;
}

bool IntStack::full() const {
    return top == capacity - 1;
}

void IntStack::push(int value) {
    if(full()){
        resize();
    }
    values[++top] = value;
}

int IntStack::pop() { 
    if(!empty()){
        return values[top--];
    }
    else{
        std::cout << "No elements" << std::endl;
        return 0;
    }
}

void IntStack::print() const { 
    for(int i = top; i >= 0; i--){
        std::cout << values[i] << " ";
    }
    std::cout << std::endl;
}

IntStack& IntStack::operator=(const IntStack& rhs) {
    if(this != &rhs){
        top = rhs.top;
        capacity = rhs.capacity;
        delete[] values;
        values = new int[capacity];
        for(int i = 0; i < capacity; i++){
            values[i] = rhs.values[i];
        }
    }
    return *this;
}

IntStack::~IntStack() {
    delete[] values;
}








