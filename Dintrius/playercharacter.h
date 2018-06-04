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

    std::string imgPath;
public:
    playerCharacter(std::string kName = "", int kStrength = 0, int kHealth = 0, int kEnergy = 0, int kFaith = 0, int kMana = 0, int kTreatment = 0);
    ~playerCharacter();

    // Atakowanie
    virtual int attack1(opponentCharacter* opponent) = 0;
    virtual int attack2(opponentCharacter* opponent) = 0;
    virtual int attack3(opponentCharacter* opponent) = 0;

    virtual void gainDamage(int dmg) = 0;
    virtual bool isDead() = 0;

    // Pozostale systemy walki
    virtual void treatCharacter() = 0;
    virtual void energyDrink() = 0;
    virtual void manaDrink() = 0;

    virtual void afterFight()= 0;
    virtual void setMaxValues() =0;

    // Wyswietl info o postaci
    virtual void info() = 0;
    virtual int infoAboutClass(int number) = 0;
    virtual std::string returnName() = 0;
    virtual std::string whatAClass() = 0;

    virtual std::string returnImgPath() = 0;

    virtual bool eneughAttack1() = 0;
    virtual bool eneughAttack2() = 0;
    virtual bool eneughAttack3() = 0;

    
    // Operator dodawania
    void operator +(int i);
    
    // Operator wyświetlenia
    friend std::ostream & operator<< (std::ostream &s, const playerCharacter & v);

};



#endif // PLAYERCHARACTER_H
