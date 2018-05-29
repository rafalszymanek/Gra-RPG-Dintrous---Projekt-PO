#ifndef OPPONENT_H
#define OPPONENT_H

#include <string>




class opponentCharacter
{
protected:
    std::string name;
    int currentHealth;
    int strenght;
    int mana;
public:
    opponentCharacter();
    ~opponentCharacter();
    virtual int attack()=0;
    virtual void gainDamage(int dmg) = 0;
    virtual void info() = 0;
    virtual bool isDead() = 0;
};

#endif // OPPONENT_H
