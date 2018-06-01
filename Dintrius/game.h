#ifndef GAME_H
#define GAME_H

#include "playercharacter.h"
#include "charactercreator.h"
#include "worrior.h"

class game
{
    playerCharacter* player;
    int status;

public:
    game(int liczba = 0);
    ~game();

    void createCharacter();
    void history1();


};

#endif // GAME_H
