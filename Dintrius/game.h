#ifndef GAME_H
#define GAME_H

#include "playercharacter.h"
#include "charactercreator.h"
#include "worrior.h"
#include "mag.h"
#include "paladyn.h"
#include "opponent.h"
#include "murlok.h"
#include "bear.h"

class game
{
    playerCharacter* player;
    int status;

public:
    game(int liczba = 0);
    ~game();

    void createCharacter();
    bool history1();
    bool history2();


};

#endif // GAME_H
