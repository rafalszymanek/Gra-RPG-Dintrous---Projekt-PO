#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include <string>

#include "opponent.h"

class playerCharacter
{
protected:
    std::string characterName;
    std::string whatClass;
    int health;
    int energy;
    int mana;
    int strength;
    int faith;
    int treatment;
    
    // Aktualny stan jednostki
    int currentHealth;
    int currentEnergy;
    int currentMana;
    
    int maxHealth;
    int maxEnergy;
    int maxMana;
public:
    playerCharacter(std::string kName = "", std::string whatClass = "", int kStrength = 0, int kHealth = 0, int kEnergy = 0, int kFaith = 0, int kMana = 0, int kTreatment = 0);
    ~playerCharacter();

    // Atakowanie
    virtual int attack1(opponentCharacter* opponent) = 0;
    virtual int attack2(opponentCharacter* opponent) = 0;
    virtual int attack3(opponentCharacter* opponent) = 0;

    virtual void gainDamage(int dmg) = 0;

    // Pozostale systemy walki
    virtual void treatCharacter() = 0;
    virtual void energyDrink() = 0;
    virtual void manaDrink() = 0;

    // Wyswietl info o postaci
    virtual void info() = 0;
    virtual std::string infoAboutClass() = 0;
    virtual std::string returnName() = 0;
    virtual bool isDead() = 0;


};

#endif // PLAYERCHARACTER_H
