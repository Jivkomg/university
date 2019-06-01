//
//  main.cpp
//  ConstPointers
//
//  Created by Zhivko Georgiev on 22.11.18.
//  Copyright © 2018 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
using namespace std;
void change(int const *ptr){
    ptr = new int(20);
    cout << ptr << endl;
    cout << *ptr << endl;
    
}
int main() {
    int *number = new int(10);
    cout << number << endl;
    cout << *number << endl;
    change(number);
    cout << number << endl;
    cout << *number << endl;
    return 0;
}
