
#include <iostream>
#include "Warrior.h"

Warrior::Warrior() {
    name = new char[7];
    strcpy(name, "Warrior");
    HP = 20;
    MP = 5;
    AP = 4;
    DP = 1;
}
