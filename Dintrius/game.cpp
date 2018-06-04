#include "game.h"
#include "dialogarea.h"
#include "charactercreator.h"
#include "fightarea.h"
#include "theend.h"

#include <iostream>


using namespace std;

game::game(int liczba)
{
    status = liczba;
}

game::~game(){
    delete player;
}

void game::createCharacter(){

    // Wyswietl ekran wyboru postaci
    characterCreator* CreateNewCharacter = new characterCreator(); // Zmienna do otworznia nowego
    CreateNewCharacter->setModal(true);
    CreateNewCharacter->exec();

    // Po zamknieciu okna pobierz dane

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
        player = new worrior(characterName, strength, health, energy, faith, mana, treatment);
    if(classOfCharacter[0] == 'M')
        player = new mag(characterName, strength, health, energy, faith, mana, treatment);
    if(classOfCharacter[0] == 'P')
        player = new paladyn(characterName, strength, health, energy, faith, mana, treatment);
    delete CreateNewCharacter;

}

/*





////////////////////////
    Historia numer jeden
    ////////////////////////





   */

bool game::history1(){
    // Stwórz dialog
    QString* dialogHistory = new QString[7];
    dialogHistory[0] = "Witaj w grze dintrous! Jestem treningowym murlokiem.<br/> Jakie pytanie chcesz mi zadać?";
    dialogHistory[1] = "Kim Ty jesteś?";
    dialogHistory[2] = "Co się stanie jak z Tobą wygram?";
    dialogHistory[3] = "Zatem walczmy!";
    dialogHistory[4] = "Jak już powiedziałem, jestem treningowym murlokiem<br/> Możesz ze mną przećwiczyć rozmowę lub <br/> spróbować walki ze mną.";
    dialogHistory[5] = "Wygrasz to idziesz dalej, przegrasz to koniec gry. Bój SIĘ!";
    dialogHistory[6] = "Oby to było Twoje ostatnie słowo!";

    // Otwórz nowe okno dialogu
    dialogArea* dialog = new dialogArea(dialogHistory, player->returnName(), "Murlok", 3, ":/murloc.png", player->returnImgPath()); // Zmienna do otworznia nowego
    dialog->setModal(true);
    dialog->exec();
    delete [] dialogHistory;
    delete dialog;

    // Stwórz przeciwnika
    opponentCharacter* opponent = new murlok(3);

    // Otworz nowe okno walki
    fightArea* fight = new fightArea(player, opponent);
    fight->setModal(true);
    fight->exec();

    delete opponent;
    delete fight;
    // Jeżeli wygrałeś idź dalej, jeżeli nie to koniec gry
    if (fight->didWon() == true){

        // Podnieś poziom postaci o 1.
        *player+1;
        cout << *player;

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

            delete [] dialogHistory;
            delete dialog;
            return true;
    }
    return false;
}
/*





////////////////////////
    Historia numer dwa
    ////////////////////////





   */

bool game::history2(){
    // Stwórz dialog
    QString* dialogHistory = new QString[7];
    dialogHistory[0] = "Cóż Cię tutaj sprowadza podróżniku?";
    dialogHistory[1] = "Nie wiem gdzie się udać i skąd się tu wziąłem";
    dialogHistory[2] = "Jakiej klątwy";
    dialogHistory[3] = "W takim razie zobaczę co w mojej mocy";
    dialogHistory[4] = "Ahh, więc jesteś tu bez celu?<br/>Miałam nadzieje, że to Ty jesteś tym wybrańcem, który <br/> Uwolni nas od klątwy";
    dialogHistory[5] = "Nasza kraina umiera, zły Pan zawładną SMOCZĄ GÓRĄ";
    dialogHistory[6] = "Dobrze, najlepiej jak porozmawiasz ze strażnikiem miasta";

    // Otwórz nowe okno dialogu
    dialogArea* dialog = new dialogArea(dialogHistory, player->returnName(), "Nieznajoma panna", 3, ":/nieznajoma1.png", player->returnImgPath()); // Zmienna do otworznia nowego
    dialog->setModal(true);
    dialog->exec();
    delete [] dialogHistory;
    delete dialog;

    // Stwórz dialog
    dialogHistory = new QString[7];
    dialogHistory[0] = "Czy ktoś zakłóca porządek?";
    dialogHistory[1] = "Nie, przychodzę w innej sprawie";
    dialogHistory[2] = "Mówisz, masz";
    dialogHistory[3] = "W takim razie zobaczę co w mojej mocy";
    dialogHistory[4] = "Dobrze, zatem w czym mogę pomóc?";
    dialogHistory[5] = "Haha! Ty taki parobek chcesz pokonać władce?!<br/>Najprawdopodobniej nie poradzisz sobie nawet <br/>z grasującym niedźwiedziem przed bramą!";
    dialogHistory[6] = "Wolne żarty!";

    // Otwórz nowe okno dialogu
    dialog = new dialogArea(dialogHistory, player->returnName(), "Strażnik", 3, ":/guard.png", player->returnImgPath()); // Zmienna do otworznia nowego
    dialog->setModal(true);
    dialog->exec();

    delete [] dialogHistory;
    delete dialog;

    // Stwórz przeciwnika
    opponentCharacter* opponent = new bear(7);

    // Otworz nowe okno walki
    fightArea* fight = new fightArea(player, opponent);
    fight->setModal(true);
    fight->exec();

    delete opponent;
    delete fight;
    // Jeżeli wygrałeś idź dalej, jeżeli nie to koniec gry
    if (fight->didWon() == true){
        textPlusContiueDialog* alert = new textPlusContiueDialog("Nadchodzi drugi niedźwiedź!");
        alert->setModal(true);
        alert->exec();

        delete alert;

        opponentCharacter* opponent = new bear(10, ":/bear3.png");

        // Otworz nowe okno walki
        fightArea* fight = new fightArea(player, opponent);
        fight->setModal(true);
        fight->exec();

        delete opponent;
        delete fight;
        if (fight->didWon() == true){
            player->afterFight();
             *player+1;
             cout << *player;

             // Stwórz dialog
             dialogHistory = new QString[7];
             dialogHistory[0] = "O, albo uciekłeś albo Ci się udało";
             dialogHistory[1] = "Tam były dwa niedźwiedzie!";
             dialogHistory[2] = "Nie, oba są martwe.";
             dialogHistory[3] = "Gdzie mogę udać się do smoczej góry?";
             dialogHistory[4] = "Czyli w takim razie na pewno uciekłeś";
             dialogHistory[5] = "Nieprawdopodobne!<br/>Giermek, sprawdź przed bramę czy to prawda!<br/>A jednak, nie jesteś zwykłym parobkiem!";
             dialogHistory[6] = "Najlepiej przejdź przez miastro Gratindam<br/>Tam spotkasz mojego dobrego znajomego Tursona<br/> Podając mu hasło 'Trututumtum' będzie dla Ciebie łaskawy<br/>Miasto znajduje się na południe jakieś 15 min drogi";

             // Otwórz nowe okno dialogu
             dialog = new dialogArea(dialogHistory, player->returnName(), "Strażnik", 3, ":/guard.png", player->returnImgPath()); // Zmienna do otworznia nowego
             dialog->setModal(true);
             dialog->exec();

             delete [] dialogHistory;
             delete dialog;
             return true;

        }

        return false;
        }


    return false;
}
