//
//  main.cpp
//  PointDistance
//
//  Created by Zhivko Georgiev on 29.11.18.
//  Copyright © 2018 Zhivko Georgiev. All rights reserved.
//
#include <math.h>
#include <iostream>
using namespace std;
double distance(double x1, double y1, double x2, double y2){
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    double point;
    double arrayPoints[n * 2];
    for(int i = 0; i < n * 2; i++){
        cin >> point;
        arrayPoints[i] = point;
    }
    for(int i = 0; i < n * 2 - 3; i++){
        cout << "Distance: " << distance(arrayPoints[i], arrayPoints[i + 1],
                                         arrayPoints[i + 2], arrayPoints[i + 3]);
    }
    return 0;
}
