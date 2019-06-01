
#include <iostream>
#include "Wizard.h"
#include "Guardian.h"
#include "Warrior.h"
int main() {
    Warrior jon; //snow
    Wizard harry; //you are a wizard harry
    Guardian gandalf; //you shall not pass

    jon.show_power();
    harry.show_power();
    gandalf.show_power();
    
    jon.get_attacked(10);
    harry.get_attacked(20);
    gandalf.get_attacked(10);
    
    jon.show_power();
    harry.show_power();
    gandalf.show_power();
    
    jon.get_attacked(100);
    jon.show_power();
    return 0;
}
