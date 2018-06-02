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
    std::string imgPath;
public:
    opponentCharacter();
    ~opponentCharacter();
    virtual int attack()=0;
    virtual void gainDamage(int dmg) = 0;
    virtual std::string returnImgPath() = 0;
    virtual int info(int number) = 0;
    virtual bool isDead() = 0;
};

#endif // OPPONENT_H
