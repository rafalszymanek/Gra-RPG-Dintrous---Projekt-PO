#ifndef MURLOK_H
#define MURLOK_H
#include "opponent.h"


class murlok:public opponentCharacter
{
public:
    murlok(int lvl = 1, std::string name = "Murlok");
    ~murlok();
    virtual int attack();
    virtual void gainDamage(int dmg);
    virtual void info();
    virtual bool isDead();
    
};

#endif // MURLOK_H
