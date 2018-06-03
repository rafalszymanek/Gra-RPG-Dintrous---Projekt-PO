#include "game.h"
#include "dialogarea.h"
#include "charactercreator.h"
#include "fightarea.h"
#include "theend.h"


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

bool game::history1(){
    QString* dialogHistory = new QString[7];
    dialogHistory[0] = "Witaj w grze dintrous! Jestem treningowym murlokiem.<br/> Jakie pytanie chcesz mi zadać?";
    dialogHistory[1] = "Kim Ty jesteś?";
    dialogHistory[2] = "Co się stanie jak z Tobą wygram?";
    dialogHistory[3] = "Zatem walczmy!";
    dialogHistory[4] = "Jak już powiedziałem, jestem treningowym murlokiem<br/> Możesz ze mną przećwiczyć rozmowę lub <br/> spróbować walki ze mną.";
    dialogHistory[5] = "Wygrasz to idziesz dalej, przegrasz to koniec gry. Bój SIĘ!";
    dialogHistory[6] = "Oby to było Twoje ostatnie słowo!";

    dialogArea* dialog = new dialogArea(dialogHistory, player->returnName(), "Murlok", 3, ":/murloc.png", player->returnImgPath()); // Zmienna do otworznia nowego
    dialog->setModal(true);
    dialog->exec();
    delete dialog;

    opponentCharacter* opponent = new murlok(7);
    int mana = 0;
    fightArea* fight = new fightArea(player, opponent);
    fight->setModal(true);
    fight->exec();

    if (fight->didWon() == true){
            QString* dialogHistory = new QString[7];
            dialogHistory[0] = "Pokonałeś mnie. <br/>Ale pamiętaj to dopiero trening, <br/>czeka Cię jeszcze mnóstwo przygód";
            dialogHistory[1] = "Co mogę teraz zrobić?";
            dialogHistory[2] = "Dobrze, zatem zmierzam";
            dialogHistory[3] = "";
            dialogHistory[4] = "Iść dalej wlacząc z przeciwnikami i poznając nowe osobniki";
            dialogHistory[5] = "Powodzenia!";
            dialogHistory[6] = "";

            dialogArea* dialog = new dialogArea(dialogHistory, player->returnName(), "Murlok", 2, ":/murloc.png", player->returnImgPath()); // Zmienna do otworznia nowego
            dialog->setModal(true);
            dialog->exec();
            player->afterFight();
            return true;
    }
    return false;
}
