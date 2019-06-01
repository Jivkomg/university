//
//  main.cpp
//  Palindrome
//
//  Created by Zhivko Georgiev on 20.12.18.
//  Copyright © 2018 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
using namespace std;
bool IsPalindrome(const char* str){
    for(size_t i = 0,j = strlen(str) - 1; i < strlen(str); i++, j--){
        if(str[i] != str[j]){
            return false;
        }
    }
    return true;
}
int main(int argc, const char * argv[]) {
    const char* str = "1";
    cout << IsPalindrome(str) << endl;
    return 0;
}
