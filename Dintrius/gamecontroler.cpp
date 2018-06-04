/*
 * Ta funkcja jest odpowiedzialna za:
 * Sterowanie całym backend gry
 * To w niej tworzone są nowe postacie i to za jej pomocą otwieramy nowe okna
 *
 */
#include <iostream>

#include "charactercreator.h"
#include "dialogarea.h"
#include "game.h"
#include "gamecontroler.h"
#include "worrior.h"
#include "textpluscontiuedialog.h"
#include "theend.h"

using namespace std;


void gameControler(){
    // Uruchomienie okna kreatora postaci

    game* newGame = new game(0);
    newGame->createCharacter();
    textPlusContiueDialog* alert = new textPlusContiueDialog("Rodział pierwszy - Wprowadzenie");
    alert->setModal(true);
    alert->exec();
    delete alert;
    if(newGame->history1()){
        textPlusContiueDialog* alert = new textPlusContiueDialog("Rodział drugi - O co chodzi?");
        alert->setModal(true);
        alert->exec();
        delete alert;
        newGame->history2();
    }


    delete newGame;
    theEnd endOfGame;
    endOfGame.setModal(true);
    endOfGame.exec();
}







