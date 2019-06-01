//
//  main.cpp
//  SortArrays
//
//  Created by Zhivko Georgiev on 5.02.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
using namespace std;
int min(int a, int b){
    return (a < b) ? a : b;
}
void sort(int array[], size_t size){
    for(int i = 0; i < size - 1; i++){
        for(int j = size - 1; j > i; j--){
            if(array[j - 1] > array[j]){
                swap(array[j], array[j - 1]);
            }
        }
    }
}
void swap(size_t &a, size_t &b){
    int c = a;
    a = b;
    b = c;
}
int* sortArrays(int* firstArray, size_t firstSize, int* secondArray, size_t secondSize){
//    validation
    if(firstArray == nullptr) return secondArray;
    if(secondArray == nullptr) return firstArray;
    if(firstArray == nullptr && secondArray == nullptr) return nullptr;
    
    size_t size = firstSize + secondSize;
    int* array = new int[size];
//    int leftOver = firstArray[0];
    for(int i = 0; i < firstSize; i++){
        array[i] = firstArray[i];
    }
    for(size_t i = firstSize, j = 0; i < size; i++, j++){
        array[i] = secondArray[j];
    }
    sort(array, size);
    return array;
}
int main() {
    int arr1[] = {1, 4, 5, 10};
    int arr2[] = {1, 2, 3, 6, 11, 15};
    int *result = sortArrays(arr1, 4, arr2, 6);
    for (int i = 0; i < 10; i++) {
        cout << result[i] << ' ';
    }
    delete result;
    return 0;
}
