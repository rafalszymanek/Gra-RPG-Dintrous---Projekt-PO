#ifndef WORRIOR_H
#define WORRIOR_H
#include "playercharacter.h"
#include "opponent.h"

class worrior:public playerCharacter
{
public:
    // Nie dziedziczymy po klasie abstrakcyjnej, poniewaz sa inne wartosci startowe!
    worrior(std::string kName = "", std::string whatClass = "Wojownik", int kStrength = 16, int kHealth = 14, int kEnergy = 12, int kFaith = 2, int kMana = 2, int kTreatment = 2);
    ~worrior();

    // Atak
    virtual int attack1(opponentCharacter* opponent);
    virtual int attack2(opponentCharacter* opponent);
    virtual int attack3(opponentCharacter* opponent);

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
