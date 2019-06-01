
#include <iostream>
#include "Guardian.h"

Guardian::Guardian() {
    name = new char[8];
    strcpy(name, "Guardian");
    HP = 40;
    MP = 25;
    AP = 1;
    DP = 3;
}
