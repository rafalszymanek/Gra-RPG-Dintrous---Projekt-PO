#include "game.h"
#include "dialogarea.h"
#include "charactercreator.h"
#include "fightarea.h"


using namespace std;

game::game(int liczba)
{
    status = liczba;
}

game::~game(){
    delete player;
}

void game::createCharacter(){
//    characterCreator* CreateNewCharacter = new characterCreator(); // Zmienna do otworznia nowego
//    CreateNewCharacter->setModal(true);
//    CreateNewCharacter->exec();

//    // Po zamknieciu okna wykonuje dalsze instrukcje

//    string characterName;
//    string classOfCharacter;
//    int strength;
//    int health;
//    int energy;
//    int faith;
//    int mana;
//    int treatment;

//    characterName = CreateNewCharacter->getCharacterName();
//    classOfCharacter = CreateNewCharacter->getClassName();
//    strength = CreateNewCharacter->getStrength();
//    health = CreateNewCharacter->getHealth();
//    energy = CreateNewCharacter->getEnergy();
//    faith = CreateNewCharacter->getFaith();
//    mana = CreateNewCharacter->getMana();
//    treatment = CreateNewCharacter->getTreatment();

//    if(classOfCharacter[0] == 'W')
//        player = new worrior(characterName, classOfCharacter, strength, health, energy, faith, mana, treatment);
//    delete CreateNewCharacter;

    /*
     * Usuń to!
     */
    player = new worrior();
}

void game::history1(){
//    QString* dialogHistory = new QString[7];
//    dialogHistory[0] = "Witaj w grze dintrous! Jestem treningowym murlokiem.<br/> Jakie pytanie chcesz mi zadać?";
//    dialogHistory[1] = "Kim Ty jesteś?";
//    dialogHistory[2] = "Co się stanie jak z Tobą wygram?";
//    dialogHistory[3] = "Zatem walczmy!";
//    dialogHistory[4] = "Jak już powiedziałem, jestem treningowym murlokiem<br/> Możesz ze mną przećwiczyć rozmowę lub <br/> spróbować walki ze mną.";
//    dialogHistory[5] = "Wygrasz to idziesz dalej, przegrasz to koniec gry. Bój SIĘ!";
//    dialogHistory[6] = "Oby to było Twoje ostatnie słowo!";

//    dialogArea* dialog = new dialogArea(dialogHistory, player->infoAboutClass(), player->returnName(), "Murlok", 3, ":/murloc.png", player->returnImgPath()); // Zmienna do otworznia nowego
//    dialog->setModal(true);
//    dialog->exec();

    opponentCharacter* opponent = new murlok(1);
    int mana = 0;
    fightArea* fight = new fightArea(player, opponent);
    fight->setModal(true);
    fight->exec();
}
