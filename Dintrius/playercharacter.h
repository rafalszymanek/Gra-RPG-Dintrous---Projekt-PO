#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include <string>

class playerCharacter
{
protected:
    std::string characterName;
    std::string whatClass = "";
    int health;
    int energy;
    int mana;
    int strength;
    int faith;
    int treatment;
public:
    playerCharacter(std::string kName = "", int kHealth = 0, int kEnergy = 0, int kMana = 0, int kStrength = 0, int kFaith = 0, int kTreatment = 0);
    ~playerCharacter();

    // Atakowanie
    virtual int attack1() = 0;
    virtual int attack2() = 0;
    virtual int attack3() = 0;

    // Pozostale systemy walki
    virtual void treatCharacter() = 0;
    virtual void energyDrink() = 0;
    virtual void manaDrink() = 0;

    // Wyswietl info o postaci
    virtual void info() = 0;


};

#endif // PLAYERCHARACTER_H
