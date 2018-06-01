/*
 * Ta funkcja jest odpowiedzialna za:
 * Sterowanie całym backend gry
 * To w niej tworzone są nowe postacie i to za jej pomocą otwieramy nowe okna
 *
 */
#include <iostream>

#include "charactercreator.h"
#include "gamecontroler.h"
#include "worrior.h"

using namespace std;


void gameControler(){
    // Uruchomienie okna kreatora postaci
    characterCreator alertNewGame; // Zmienna do otworznia nowego
    alertNewGame.setModal(true);
    alertNewGame.exec();

    // Po zamknieciu okna wykonuje dalsze instrukcje

    string characterName;
    string classOfCharacter;
    int strength;
    int health;
    int energy;
    int faith;
    int mana;
    int treatment;
    worrior *player;

    characterName = alertNewGame.getCharacterName();
    classOfCharacter = alertNewGame.getClassName();
    strength = alertNewGame.getStrength();
    health = alertNewGame.getHealth();
    energy = alertNewGame.getEnergy();
    faith = alertNewGame.getFaith();
    mana = alertNewGame.getMana();
    treatment = alertNewGame.getTreatment();

    if(classOfCharacter[0] == 'W')
        player = new worrior(characterName, classOfCharacter, strength, health, energy, faith, mana, treatment);


}







