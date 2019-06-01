
#ifndef MagicBox_h
#define MagicBox_h

#include <iostream>
#include <random>


template <class T>
class MagicBox {
private:
    T* values; //box
    int size;
    int capacity;
    
    void resize();
    
    
public:
    MagicBox();
    MagicBox(const MagicBox&);
    MagicBox<T>& operator=(const MagicBox&);
    
    void insert(T);
    void pop();
    void list() const;
    ~MagicBox();
};

template <class T>
MagicBox<T>::MagicBox(): size(0), capacity(10){
    values = new T[capacity];
}

template <class T>
MagicBox<T>::MagicBox(const MagicBox& rhs): size(rhs.size), capacity(rhs.capacity){
    values = new T[capacity];
    
    for(int i = 0; i < size; i++){
        values[i] = rhs.values[i];
    }
}

template <class T>
MagicBox<T>& MagicBox<T>::operator=(const MagicBox& rhs){
    if(this != &rhs)
    {
        delete[] values;
        
        capacity = rhs.capacity;
        size = rhs.size;
        
        values = new T[capacity];
        
        for(int i = 0; i < size; i++){
            values[i] = rhs.values[i];
        }
    }
    return *this;
}

template <class T>
void MagicBox<T>::resize()
{
    capacity *= 2;
    T* newValues = new T[capacity];
    
    for(int i = 0; i < size; i++){
        newValues[i] = values[i];
    }
    
    delete[] values;
    values = newValues;
}


template <class T>
void MagicBox<T>::insert(T value) {
    if(size == capacity){
        resize();
    }
    values[size] = value;
    size++;
}

template <class T>
void MagicBox<T>::pop(){
    if(size == 0){
        std::cout << "No items" << std::endl;
        return;
    }
    
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, size); // define the range

    int randomNum = distr(eng);
    
    for(int i = randomNum; i < size - 1; i++){
        values[i] = values[i + 1];
    }
    size--;
}

template <class T>
void MagicBox<T>::list() const
{
    for(int i = 0; i < size; i++){
        std::cout << values[i] << " ";
    }
    std::cout << std::endl;
}

template <class T>
MagicBox<T>::~MagicBox(){
    delete[] values;
}

#endif /* MagicBox_h */
