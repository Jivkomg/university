//
//  main.cpp
//  Lines
//
//  Created by Zhivko Georgiev on 5.02.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
using namespace std;
struct Line{
    double x1;
    double y1;
    double x2;
    double y2;
};
int min(int a, int b){
    return (a <= b) ? a : b;
}
int max(int a, int b){
    return (a >= b) ? a : b;
}
int lineIntersect(Line line1, Line line2){
    if(line1.x1 != line1.x2 && line1.y1 != line1.y2){
        return -1;
    }
    if(line2.x1 != line2.x2 && line2.y1 != line2.y2){
        return -1;
    }
    
    if(line1.y1 == line1.y2 == line2.y1 == line2.y2){
        if(max(line1.x1, line1.x1) >= min(line2.x1, line2.x2)){
            
        }
    }
    return -1;
}
int main() {
   
    return 0;
}
