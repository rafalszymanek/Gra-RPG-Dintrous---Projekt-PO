#ifndef MAG_H
#define MAG_H
#include "playercharacter.h"
#include "opponent.h"

class mag:public playerCharacter
{
public:
    // Nie dziedziczymy po klasie abstrakcyjnej, poniewaz sa inne wartosci startowe!
    mag(std::string kName = "", int kStrength = 3, int kHealth = 7, int kEnergy = 5, int kFaith = 13, int kMana = 12, int kTreatment = 10);
    ~mag();

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
#endif // MAG_H
