//
//  main.cpp
//  ReverseString
//
//  Created by Zhivko Georgiev on 20.12.18.
//  Copyright © 2018 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
using namespace std;
void swap(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}
void reverseString(char* str){
    for(size_t i = 0, j = strlen(str) - 1; i < strlen(str); i++, j--){
        swap(str[i], str[j]);
    }
}
int main(int argc, const char * argv[]) {
    char str[100];
    for(size_t i = 0; i < 100; i++){
        //TODO
        if(str[i] == 'Z')
            
    }
    return 0;
}
