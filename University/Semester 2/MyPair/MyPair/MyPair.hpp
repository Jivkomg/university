//
//  MyPair.h
//  MyPair
//
//  Created by Zhivko Georgiev on 16.04.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef MyPair_h
#define MyPair_h
#include <iostream>
template <class T, class S>
class MyPair{
private:
    T first;
    S second;
public:
    MyPair();
    MyPair(const T&, const S&);
    void setFirst(const T&);
    void setSecond(const S&);
    
    const T getFirst() const;
    const S getSecond() const;
    
    const bool operator==(const MyPair<T,S>&) const;
};

template <class T, class S>
MyPair<T,S>::MyPair(){
    first = T();
    second = S();
}

template <class T, class S>
MyPair<T,S>::MyPair(const T& t, const S& s):first(t), second(s){
//    first = T(t);
//    second = S(s);
}

template <class T, class S>
void MyPair<T,S>::setFirst(const T& t){
    first = t;
}

template <class T, class S>
void MyPair<T,S>::setSecond(const S& s){
    second = s;
}

template <class T, class S>
const T MyPair<T,S>::getFirst() const{
    return first;
}

template <class T, class S>
const S MyPair<T,S>::getSecond() const{
    return second;
}

template <class T, class S>
const bool MyPair<T,S>::operator==(const MyPair<T,S>& rhs) const{
    if(first == rhs.first && second == rhs.second){
        return true;
    }
    else return false;
}

template <class T, class S>
std::ostream& operator<<(std::ostream& out, const MyPair<T,S>& myPair){
    out << myPair.getFirst() << " " << myPair.getSecond() << std::endl;
    return out;
}

#endif /* MyPair_h */
