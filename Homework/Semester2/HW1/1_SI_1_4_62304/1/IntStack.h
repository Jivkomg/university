//
//  IntStack.h
//  IntStack
//
//  Created by Zhivko Georgiev on 9.04.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef IntStack_h
#define IntStack_h

const int MAX = 100;

class IntStack{
private:
    int capacity;
    int top;
    int* values;

    void resize();
    bool full() const;
public:
    IntStack(); //default
    IntStack(IntStack const&); //copy

    void push(int);
    void print() const;
    bool empty() const;
    int peek() const;
    int pop();
    
    IntStack& operator=(IntStack const &); //operator =
    friend IntStack& sortStack(IntStack&);
    
    ~IntStack(); //destructor
};
#endif /* IntStack_h */
