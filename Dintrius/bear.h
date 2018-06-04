#ifndef BEAR_H
#define BEAR_H
#include "opponent.h"
#include "playercharacter.h"
#include "worrior.h"



class bear:public opponentCharacter
{
public:
    bear(int lvl = 1, std::string imagePath = ":/bear.png");
    ~bear();

    // Atakowanie
    virtual int attack();
    virtual void gainDamage(int dmg);

    virtual bool isDead();

    // Zwróc informacje o scieżce do obrazka
    virtual std::string returnImgPath();
    virtual int info(int number);


    // Przeciążanie operatora =
    // Przypisuje siłę bohatera do siły beara
    void operator=(playerCharacter *player);

};
#endif // BEAR_H
