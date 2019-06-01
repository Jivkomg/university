//
//  Vector.h
//  Vector
//
//  Created by Zhivko Georgiev on 12.03.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef Vector_h
#define Vector_h
class MyVector{
private:
    int size;
    int maxSize;
    int* values;
    
    void resize();
    
public:
    MyVector(); //default
    MyVector(const MyVector&); //copy
    
    void setElement(int pos, int val);
    void pushBack(int val);
    void insert(int pos, int val);
    void remove(int pos);
    void print() const;
    
    int getElement(int pos) const;
    int popBack(); //size --, so not a const
    int begin() const;
    int end() const;
    int getSize() const;
    
    MyVector& operator=(const MyVector& rhs);
    int operator[](int pos);
    
    friend void sort (MyVector& myVector);
    ~MyVector(); //destructor
};
#endif /* Vector_h */
