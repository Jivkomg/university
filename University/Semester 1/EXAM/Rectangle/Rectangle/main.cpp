//
//  main.cpp
//  Rectangle
//
//  Created by Zhivko Georgiev on 6.02.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
using namespace std;
void pushX(int n){
    for(int i = 0; i < n; i++){
        cout << ' ';
    }
}
void pushY(int n){
    for(int i = 0; i < n; i++){
        cout << endl;
    }
}
void printLine(int n,char c){
    for(int i = 0; i < n; i++){
        cout << c;
    }
}
void printRectangle(int N, int M, char c){
    pushY((25 - M)/2);
    for(int i = 0; i < M; i++){
        pushX((80 - N)/2);
        printLine(N, c);
        cout << endl;
    }
    pushY((25 - M)/2);
}
int main() {
    printRectangle(5, 3, '*');
    return 0;
}
