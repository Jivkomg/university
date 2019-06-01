//
//  main.cpp
//  Vector
//
//  Created by Zhivko Georgiev on 26.03.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//
#include <iostream>
#include "Vector.hpp"
//
//template <class T>
//void sort(MyVector<T>& rhs){
//    int size = rhs.size;
//    for (int i = 0; i < size - 1; i++) {
//        for(int j = 0; j < size; j++){
//            if(rhs.values[i] > rhs.values[j]){
//                //swap
//                int temp = rhs.values[i];
//                rhs.values[i] = rhs.values[j];
//                rhs.values[j] = temp;
//            }
//        }
//    }
//}
//
int main(){
    MyVector<int> a;
    for(int i = 1; i <= 15; i++)
    {
        a.pushBack(i);
    }
    a.setElement(5,3);
    a.insert(6,-5);
    a.remove(5);
    std::cout << a.getElement(3) << std::endl;
    std::cout << a.popBack() << std::endl;
    std::cout << a.begin() << " " << a.end() << std::endl;
    a.print();
//    a.sort();
//    a.print();

    MyVector<double> b;
    for(int i = 1; i <= 15; i++)
    {
        b.pushBack(i + 0.1);
    }
    b.setElement(5,3);
    b.insert(6,-5);
    b.remove(5);
    std::cout << a.getElement(3) << std::endl;
    std::cout << a.popBack() << std::endl;
    std::cout << a.begin() << " " << a.end() << std::endl;
    b.print();


//    MyVector<char> semiString;
//    char tmp;
//    while (std::cin.get(tmp) && tmp != '\n') {
//        semiString.pushBack(tmp);
//    }
//    semiString.pushBack('\0');
//    semiString.print();
    
//    MyVector a;
//
//    for(int i = 1; i <= 15; i++)
//    {
//        a.pushBack(i);
//    }
//    //1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
//    a.setElement(5,3); //1 2 3 4 5 3 7 8 9 10 11 12 13 14 15
//
//    a.insert(6,-5);     //1 2 3 4 5 3 -5 7 8 9 10 11 12 13 14 15
//    a.remove(5);        //1 2 3 4 5 -5 7 8 9 10 11 12 13 14 15
//
//
//    std::cout << a.getElement(3) << std::endl;
//    std::cout << a.popBack() << std::endl;
//    //1 2 3 4 5 -5 7 8 9 10 11 12 13 14
//
//    std::cout << a.begin() << " " << a.end() << std::endl;
//
//    a.print();
//
//    MyVector b;
//    b.pushBack(2);
//    b.pushBack(5);
//    b.pushBack(1);
//
//    b.print();
//    sort(b);
//    b.print();
//    return 0;

}
