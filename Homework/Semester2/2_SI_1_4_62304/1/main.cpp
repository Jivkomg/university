
#include <iostream>
#include "MagicBox.hpp"
int main(int argc, const char * argv[]) {
    
    //test1
    MagicBox<int> m1;
    m1.insert(2);
    m1.insert(1);
    m1.insert(5);
    m1.insert(12);
    m1.insert(6);
    m1.list();

    for(int i = 0; i < 6; i++){
        m1.pop();
        m1.list();
    }
    
    
    //test2
    MagicBox<double> m2;
    m2.insert(2.2);
    m2.insert(1.4);
    m2.insert(5.3);
    m2.insert(12.2);
    m2.insert(6.1);
    m2.list();
    
    for(int i = 0; i < 6; i++){
        m2.pop();
        m2.list();
    }
    return 0;
}
