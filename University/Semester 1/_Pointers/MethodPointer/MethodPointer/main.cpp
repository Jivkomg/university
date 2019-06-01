//
//  main.cpp
//  MethodPointer
//
//  Created by Zhivko Georgiev on 22.11.18.
//  Copyright © 2018 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
using namespace std;
int *init(){
    int *a = new int(90);
    return a;
}
int main(int argc, const char * argv[]) {
    int *int_ptr = init();
    cout << int_ptr << endl;
    cout << *int_ptr << endl;
    delete int_ptr;
    return 0;
}
