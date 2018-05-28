#ifndef CONTROLEROFFIGHT_H
#define CONTROLEROFFIGHT_H

#include "playercharacter.h"
#include "opponent.h"

class controlerOfFight
{
    playerCharacter* player;
    opponentCharacter* opponent;
public:
    controlerOfFight(playerCharacter *player);
    ~controlerOfFight();
    
    void fight();
};

#endif // CONTROLEROFFIGHT_H
