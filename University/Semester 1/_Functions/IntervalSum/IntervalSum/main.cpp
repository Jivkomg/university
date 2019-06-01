//
//  main.cpp
//  IntervalSum
//
//  Created by Zhivko Georgiev on 15.11.18.
//  Copyright © 2018 Zhivko Georgiev. All rights reserved.
//
#include <iostream>
using namespace std;

//int sum_interval(int first, int last){
//    int sum = 0;
//    for(int i = first; i <= last; i++){
//        sum += i;
//    }
//    return sum;
//}
//recursion
int sum_interval(int first, int last){
    if (first < last){
        return first + (sum_interval(first + 1, last));
    }
    else{
        return first;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    cout << sum_interval(2,5) << endl;
    return 0;
}
