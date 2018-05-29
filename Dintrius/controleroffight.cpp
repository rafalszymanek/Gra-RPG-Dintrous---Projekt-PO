#include <iostream>
#include <ctime>

#include "controleroffight.h"

using namespace std;
/*
    Funkcja - Menu wyboru, którego ataku chce użyć gracz. (Niepotrzebne w graficznym)
 */
int whichAttackOfPlayer(){
    int choiceOfPlayer;
    for(;;){
        cout<<"Co chcesz zrobic w tej turze?" << endl << endl;
        cout<<"1. Atak 1" <<  endl;
        cout<<"2. Atak 2" <<  endl;
        cout<<"3. Atak 3" <<  endl;
        cout<<"4. Uleczenie" <<  endl;
        cout<<"5. Energy drink" <<  endl;
        cout<<"6. Mana drink" <<  endl;
        cout<<"Opcja nr: ";
        cin >> choiceOfPlayer;
        
        switch (choiceOfPlayer) {
            case 1:
                return 1;
                break;
            case 2:
                return 2;
                break;
            case 3:
                return 3;
                break;
            case 4:
                return 4;
                break;
            case 5:
                return 5;
                break;
            case 6:
                return 6;
                break;
            default:
                cout << "Zły wybor!" <<endl;
                break;
        }
    }
    return 0;
}

controlerOfFight::controlerOfFight(playerCharacter *kPlayer, opponentCharacter *kOpponent)
{
    player = kPlayer;
    opponent = kOpponent;
}

controlerOfFight::~controlerOfFight(){
    player = NULL;
    opponent = NULL;
}
/*
 Co kiedy zwraca?
 1 - wygral gracz
 0 - wygral przeciwnik
 */
int controlerOfFight::fight(){
    srand(time( NULL ) );
    int dmg = 0;
    int opponentDmg = 0;
    
    
    int whoStartFight = rand() % 3; // 0 lub 2 Rozpoczyna gracz / 1 rozpoczyna przeciwnik
    
    ///////////////
    // ROZPOCZYNA GRACZ
    //////////////
    if (whoStartFight == 0 || whoStartFight == 2) {
        cout << "Rozpoczyna gracz" << endl;
        for (;;) {
            int choiceOfPlayer = whichAttackOfPlayer();
            if (choiceOfPlayer == 1) {
                dmg = player->attack1(opponent);    // Odrazu w funkcji przecwinik otrzymuje obrażenia
            }
            else if (choiceOfPlayer == 2){
                dmg = player->attack2(opponent);    // Odrazu w funkcji przecwinik otrzymuje obrażenia
            }
            else if (choiceOfPlayer == 3){
                dmg = player->attack3(opponent);    // Odrazu w funkcji przecwinik otrzymuje obrażenia
            }
            else if (choiceOfPlayer == 4){
                player->treatCharacter();
            }
            else if (choiceOfPlayer == 5){
                player->energyDrink();
            }
            else if (choiceOfPlayer == 6){
                player->manaDrink();
            }
            
            if (opponent->isDead() == true) {
                return 1;   // WYGRAŁ GRACZ
            }
            
            opponentDmg = opponent->attack();
            player->gainDamage(opponentDmg);    // Gracz nie otrzymuje obrażeń w funkcji. Trzeba użyc osobnej funkcji
            
            cout << "------------------------" << endl;
            player->info();
            cout << "------------------------" << endl;
            opponent -> info();
            cout << "------------------------" << endl;
            if (player->isDead() == true) {
                return 0;   // WYGRAŁ PRZECIWNIK
            }
            
            
        }
        ///////////////
        // ROZPOCZYNA PRZECIWNIK
        //////////////
    }
    else{
        cout << "Rozpoczyna przeciwnik" << endl;
        for(;;){
            opponentDmg = opponent->attack();
            player->gainDamage(opponentDmg);            // Gracz nie otrzymuje obrażeń w funkcji. Trzeba użyc osobnej funkcji
            
            if (player->isDead() == true) {
                return 0;   // WYGRAŁ PRZECIWNIK
            }
                int choiceOfPlayer = whichAttackOfPlayer();
                if (choiceOfPlayer == 1) {
                    dmg = player->attack1(opponent);    // Odrazu w funkcji przecwinik otrzymuje obrażenia
                }
                else if (choiceOfPlayer == 2){
                    dmg = player->attack2(opponent);    // Odrazu w funkcji przecwinik otrzymuje obrażenia
                }
                else if (choiceOfPlayer == 3){
                    dmg = player->attack3(opponent);    // Odrazu w funkcji przecwinik otrzymuje obrażenia
                }
                else if (choiceOfPlayer == 4){
                    player->treatCharacter();
                }
                else if (choiceOfPlayer == 5){
                    player->energyDrink();
                }
                else if (choiceOfPlayer == 6){
                    player->manaDrink();
                }
                cout << "------------------------" << endl;
                player->info();
                cout << "------------------------" << endl;
                opponent -> info();
                cout << "------------------------" << endl;
                
                if (opponent->isDead() == true) {
                    return 1;   // WYGRAŁ GRACZ
                }
                
            
        }
    }
}
