//
//  main.cpp
//  Intersecting
//
//  Created by Zhivko Georgiev on 15.11.18.
//  Copyright © 2018 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
bool are_intersecting(int a1, int a2, int b1, int b2){
    if(a2 >= b1 && b2 >= a1){
        return true;
    }
    return false;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << are_intersecting(1, 3, 2, 5) << std::endl;
    return 0;
}
