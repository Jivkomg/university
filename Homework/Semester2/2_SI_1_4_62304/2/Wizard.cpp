
#include <iostream>
#include "Wizard.h"

Wizard::Wizard() {
    name = new char[6];
    strcpy(name, "Wizard");
    HP = 30;
    MP = 30;
    AP = 2;
    DP = 2;;
}
