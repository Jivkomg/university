

#ifndef Guest_h
#define Guest_h

class Guest{
protected:
    char* ipAddress;
public:
    Guest();
    Guest(const char*);
    Guest(const Guest&);
    void setIpAddress(const char*);
    const char* getIpAddress() const;
    Guest& operator=(const Guest&);
    ~Guest();
};

#endif /* Guest_h */
