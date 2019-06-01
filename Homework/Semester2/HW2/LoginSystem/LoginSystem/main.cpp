
#include <iostream>
#include "Guest.h"
#include "User.h"
#include "PowerUser.h"
#include "VIP.h"
#include "Admin.h"

char* decipherPassword(const char* inpString)
{
    char xorKey = 'Z';
    size_t len = strlen(inpString);
    char* retString = new char[len + 1];
    for (int i = 0; i < len; i++)
    {
        retString[i] = inpString[i] ^ xorKey;
    }
    return retString;
}

int main() {
    Guest g("215.293.193.40");
    Guest g1 = g;
    std::cout << g1.getIpAddress() << std::endl;
    
    User u1("211.298.191.40", "noobmaster69", "blabla", "Endgame");
    User u2("244.239.190.40", "thelegend27", "azorahai", "Got");
    
    std::cout << std::endl;
    //change password test
    u1.setPassword("thanos");
    std::cout << "New password: "<< u1.getPassword() << std::endl;
    std::cout << "New password: "<< decipherPassword(u1.getPassword()) << std::endl;

    std::cout << std::endl;
    //reputation exchange test
    PowerUser p1("211.298.191.40", "power1", "foo1", "CoolTitle1", 5);
    PowerUser p2("212.299.192.40", "power2", "foo2", "CoolTitle2", 10);
    std::cout << p1.getUsername() << " has " << p1.getReputation() << " reputation" << std::endl;
    p1.giveReputation(p2); // p2 has given p1 +1 reputation
    std::cout << p1.getUsername() << " now has " << p1.getReputation() << " reputation" << std::endl;
    
    std::cout << std::endl;
    //title test
    VIP v("231.295.181.40", "vip", "1234", "VIPTitle1");
    v.setTitle("VIPVIP");
    std::cout << "New title: " << v.getTitle() << std::endl;
    
    std::cout << std::endl;
    //username change test
    Admin a("210.290.190.40", "admin", "admin", "AdminTitle", 100);
    a.setUsername("bla");
    std::cout << "New username: " << a.getUsername() << std::endl;
    
    a.setOthersUsername("blaa", u1);
    std::cout << "New username: " << u1.getUsername() << std::endl;
    
    return 0;
}
