//
//  main.cpp
//  IntStack
//
//  Created by Zhivko Georgiev on 9.04.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
#include "IntStack.h"
//additional function
void swap(int& a, int& b){
    if(a!=b){
        int temp = a;
        a = b;
        b = temp;
    }
}
IntStack& sortStack(IntStack& intStack){
    for(int i = 0; i < intStack.top; i++){
        for(int j = 0; j < intStack.top - i; j++){
            if(intStack.values[j] > intStack.values[j + 1]){
                swap(intStack.values[j], intStack.values[j + 1]);
            }
        }
    }
    return intStack;
}

int main() {
    IntStack myStack = IntStack();
    std::cout << "Enter size: ";
    int size = 0;
    std::cin >> size;
    if (size <= 0) {
        std::cout << "Wrong input" << std::endl;
    }
    int value;
    
    for(int i = 0; i < size; i++){
        std::cin >> value;
        myStack.push(value);
    }
    
    //actual task
    myStack.print();
    myStack = sortStack(myStack);
    myStack.print();
    
    //additional testing
    value = myStack.pop();
    std::cout << value << std::endl;
    
    myStack.print();
   
    std::cout << myStack.empty() <<std::endl;
   
    value = myStack.peek();
    std::cout << value << std::endl;
    
    myStack.print();
    IntStack s2 = myStack;
    
    return 0;
}
