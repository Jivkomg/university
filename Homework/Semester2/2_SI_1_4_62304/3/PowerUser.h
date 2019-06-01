

#ifndef PowerUser_h
#define PowerUser_h

#include "User.h"
class PowerUser: virtual public User{
protected:
    int reputation;
public:
    PowerUser();
    PowerUser(const char*, const char*, const char*, const char*, int);
    const int getReputation() const;
    void giveReputation(const PowerUser&);
};
#endif /* PowerUser_h */
