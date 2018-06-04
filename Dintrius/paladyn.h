#ifndef PALADYN_H
#define PALADYN_H


#include "playercharacter.h"
#include "opponent.h"

class paladyn:public playerCharacter
{
public:
    // Nie dziedziczymy po klasie abstrakcyjnej, poniewaz sa inne wartosci startowe!
    paladyn(std::string kName = "", int kStrength = 11, int kHealth = 11, int kEnergy = 9, int kFaith = 5, int kMana = 7, int kTreatment = 7);
    ~paladyn();

    // Atak
    virtual int attack1(opponentCharacter* opponent);
    virtual int attack2(opponentCharacter* opponent);
    virtual int attack3(opponentCharacter* opponent);

    virtual void gainDamage(int dmg);

    // Pozostale systemy walki
    virtual void treatCharacter();
    virtual void energyDrink();
    virtual void manaDrink();

    virtual bool isDead();

    // Leczy postać po walce
    virtual void afterFight();
    // Ustawia maksymalne wartości po podniesieniu poziomu umiejętności
    virtual void setMaxValues();

    // Wyswietl info o postaci
    virtual void info();
    virtual int infoAboutClass(int number); // Zwraca wszystko co chcemy
    virtual std::string returnName();
    virtual std::string whatAClass();

    // Zwroc scieze do obrazka
    virtual std::string returnImgPath();

    // Sprawdź czy wystarczająco do zaatakowania
    virtual bool eneughAttack1();
    virtual bool eneughAttack2();
    virtual bool eneughAttack3();

};


#endif // PALADYN_H
