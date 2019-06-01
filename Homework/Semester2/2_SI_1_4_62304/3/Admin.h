

#ifndef Admin_h
#define Admin_h
#include "VIP.h"
#include "PowerUser.h"
class Admin: public VIP, public PowerUser{
public:
    Admin();
    Admin(const char*, const char*, const char*, const char*, int);
    void setUsername(const char*);
    void setOthersUsername(const char*, User&);
};

#endif /* Admin_h */
