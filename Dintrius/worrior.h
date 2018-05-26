#ifndef WORRIOR_H
#define WORRIOR_H
#include "playercharacter.h"

class worrior:public playerCharacter
{
public:
    // Nie dziedziczymy po klasie abstrakcyjnej, poniewaz sa inne wartosci startowe!
    worrior(std::string kName = "");
    ~worrior();

    // Atak
    virtual int attack1();
    virtual int attack2();
    virtual int attack3();

    virtual void gainDamage(int dmg);

    // Pozostale systemy walki
    virtual void treatCharacter();
    virtual void energyDrink();
    virtual void manaDrink();

    // Wyswietl info o postaci
    virtual void info();
    virtual bool isDead();

};

#endif // WORRIOR_H
