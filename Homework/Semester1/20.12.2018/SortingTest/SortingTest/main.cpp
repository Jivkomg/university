//
//  main.cpp
//  SortingTest
//
//  Created by Zhivko Georgiev on 20.12.18.
//  Copyright © 2018 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
bool compare(int a, int b){
    return a > b;
}
int main(int argc, const char * argv[])
{
    int arr[] = {5, 4, 1, 9, 3, 4, 5};
    for(int i = 0; i < 7; i++)
    {
        cout << arr[i] <<' ';
    }
    cout << endl;
    sort(arr,arr + 7);
    
    for(int i = 0; i < 7; i++)
    {
        cout << arr[i] <<' ';
    }
    cout << endl;
//    reverse(arr,arr + 7); just turns the array around
    sort(arr, arr + 7,compare);
    for(int i = 0; i < 7; i++)
    {
        cout << arr[i] <<' ';
    }
    cout << endl;
    return 0;
}
