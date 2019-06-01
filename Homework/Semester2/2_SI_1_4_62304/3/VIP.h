

#ifndef VIP_h
#define VIP_h

#include "User.h"
class VIP: virtual public User{
public:
    VIP();
    VIP(const char*, const char*, const char*, const char*);
    void setTitle(const char*);
};
#endif /* VIP_h */
