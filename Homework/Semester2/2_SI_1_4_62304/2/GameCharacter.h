
#ifndef GameCharacter_h
#define GameCharacter_h

class GameCharacter{
protected:
    char* name;
    int HP;
    int MP;
    int AP;
    int DP;
    //private constructor so no instances can be made
    GameCharacter();
    GameCharacter(const char*, int, int, int, int);
public:
    GameCharacter(const GameCharacter&);
    void get_attacked(int);
    void show_power() const;
    bool isDead() const;
    GameCharacter& operator=(const GameCharacter&);
    ~GameCharacter();
};
#endif /* GameCharacter_h */
