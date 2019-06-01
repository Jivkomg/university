//
//  main.cpp
//  HeapPointers
//
//  Created by Zhivko Georgiev on 22.11.18.
//  Copyright © 2018 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int *int_ptr = new int(90);
    
    cout << int_ptr << endl;
    cout << *int_ptr << endl;
    
    delete int_ptr;
    cout << int_ptr << endl;
    cout << *int_ptr << endl;


//    int_ptr = new int(70);
//    cout << int_ptr << endl;
//    cout << *int_ptr << endl;
    
    
    return 0;
}
