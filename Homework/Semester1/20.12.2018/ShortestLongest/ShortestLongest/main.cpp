//
//  main.cpp
//  ShortestLongest
//
//  Created by Zhivko Georgiev on 20.12.18.
//  Copyright © 2018 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    size_t max = 0;
    size_t min = 100;
    char word[100];
    do{
        cin >> word;
        if(strlen(word) < min){
            min = strlen(word);
        }
        if(strlen(word) > max){
            max = strlen(word);
        }
    }
    while (strcmp(word, "END") != 0);
    cout << max << endl;
    cout << min << endl;
    return 0;
}
