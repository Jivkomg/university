//
//  main.cpp
//  NoNulls
//
//  Created by Zhivko Georgiev on 6.12.18.
//  Copyright © 2018 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int array[10]{1, 2, 0, 4, 5, 0, 7, 8, 0, 10};
    for (int i = 9; i >= 0; i--){
        if(array[i] != 0){
            cout << array[i] << " ";
        }
    }
    cout << endl;
    return 0;
}
