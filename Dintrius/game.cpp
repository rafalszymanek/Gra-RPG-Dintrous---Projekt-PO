#include "game.h"
#include "dialogarea.h"
#include "charactercreator.h"


using namespace std;

game::game(int liczba)
{
    status = liczba;
}

game::~game(){
    delete player;
}

void game::createCharacter(){
    characterCreator* CreateNewCharacter = new characterCreator(); // Zmienna do otworznia nowego
    CreateNewCharacter->setModal(true);
    CreateNewCharacter->exec();

    // Po zamknieciu okna wykonuje dalsze instrukcje

    string characterName;
    string classOfCharacter;
    int strength;
    int health;
    int energy;
    int faith;
    int mana;
    int treatment;

    characterName = CreateNewCharacter->getCharacterName();
    classOfCharacter = CreateNewCharacter->getClassName();
    strength = CreateNewCharacter->getStrength();
    health = CreateNewCharacter->getHealth();
    energy = CreateNewCharacter->getEnergy();
    faith = CreateNewCharacter->getFaith();
    mana = CreateNewCharacter->getMana();
    treatment = CreateNewCharacter->getTreatment();

    if(classOfCharacter[0] == 'W')
        player = new worrior(characterName, classOfCharacter, strength, health, energy, faith, mana, treatment);
    delete CreateNewCharacter;
}

void game::history1(){
    QString* dialogHistory = new QString[7];
    dialogHistory[0] = "Rozpoczynająca";
    dialogHistory[1] = "1 - Gracz";
    dialogHistory[2] = "2 - Gracz";
    dialogHistory[3] = "3 - Gracz";
    dialogHistory[4] = "Przeciwnik - 1";
    dialogHistory[5] = "Przeciwnik - 2";
    dialogHistory[6] = "Przeciwnik - 3";

    dialogArea* dialog = new dialogArea(dialogHistory, player->infoAboutClass(), player->returnName()); // Zmienna do otworznia nowego
    dialog->setModal(true);
    dialog->exec();
}
