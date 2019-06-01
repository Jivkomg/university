//
//  Vector.hpp
//  Vector
//
//  Created by Zhivko Georgiev on 2.04.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef Vector_h
#define Vector_h
template <class T>
class MyVector{
private:
    int size;
    int maxSize;
    T* values;
    
    void resize();
    
public:
    MyVector(); //default
    MyVector(const MyVector&); //copy
    
    void setElement(int pos, T val);
    void pushBack(T val);
    void insert(int pos, T val);
    void remove(int pos);
    void print() const;
    
    T getElement(int pos) const;
    T popBack();
    T begin() const;
    T end() const;
    T getSize() const;
    
    MyVector<T>& operator=(const MyVector<T>& rhs);
    int operator[](int pos);
    
    friend void sort (MyVector<T>& myVector);

    ~MyVector(); //destructor
};

template <class T>
MyVector<T>::MyVector():size(0), maxSize(10){
    values = new T[maxSize];
}

template <class T>
MyVector<T>::MyVector(const MyVector<T>& rhs):size(rhs.size), maxSize(rhs.maxSize){
    values = new T[maxSize];
    for(int i = 0; i < size; i++){
        values[i] = rhs.values[i];
    }
}

template <class T>
void MyVector<T>::resize()
{
    maxSize *= 2;
    T* newValues = new T[maxSize];
    
    for(int i = 0; i < size; i++)
    {
        newValues[i] = values[i];
    }
    
    delete[] values;
    values = newValues;
}


template <class T>
void MyVector<T>::setElement(int pos, T val) {
    if(pos <= size){
        values[pos] = val;
    }
    else std::cout << "Invalid position \n";
}

template <class T>
void MyVector<T>::pushBack(T val) {
    if(size == maxSize){
        resize();
    }
    values[size] = val;
    size ++;
}

template <class T>
void MyVector<T>::insert(int pos, T val) {
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

template <class T>
void MyVector<T>::remove(int pos) {
    if(pos < size){
        for(int i = pos; i < size - 1; i++){
            values[i] = values[i + 1];
        }
    }
    size--;
}

template <class T>
void MyVector<T>::print() const{
    for(int i = 0; i < size; i++){
        std::cout << values[i] << ' ';
    }
    std::cout << std::endl;
}

template <class T>
T MyVector<T>::getElement(int pos) const {
    if(pos < size){
        return values[pos];
    }
    else{
        std::cout << "Invalid position" << std::endl;
        return -1;
    }
}

template <class T>
T MyVector<T>::popBack() {
    if(size != 0){
        size--;
        return values[size - 1];
    }
    else {
        std::cout << "NO elementrs \n";
        return -1;
    }
}

template <class T>
T MyVector<T>::begin() const {
    if(size != 0){
        return values[0];
    }
    else {
        std::cout << "NO elements \n";
        return -1;
    }
}

template <class T>
T MyVector<T>::end() const {
    
    if(size != 0){
        return values[size - 1];
    }
    else {
        std::cout << "NO elements \n";
        return -1;
    }
}

template <class T>
T MyVector<T>::getSize() const {
    return size;
}

template <class T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& rhs){
    if(this != &rhs){
        size = rhs.size;
        maxSize = rhs.maxSize;
        
        delete[] values;
        
        values = new T[maxSize];
        for(int i = 0; i < size; i ++){
            values[i] = rhs.values[i];
        }
    }
    return *this;
}

template <class T>
int MyVector<T>::operator[](int a){
    return values[a];
}
template <class T>
MyVector<T>::~MyVector(){
    delete[] values;
}




#endif /* Vector_h */
