#include <iostream>
#include <ctime>

#include "controleroffight.h"

using namespace std;

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

controlerOfFight::controlerOfFight(playerCharacter *kPlayer)
{
    player = kPlayer;
}

controlerOfFight::~controlerOfFight(){
    player = NULL;
    opponent = NULL;
}


void controlerOfFight::fight(){
    srand(time( NULL ) );
    int dmg = 0;
    int health = 0;
    int energy = 0;
    int mana = 0;
    
    
    int whoStartFight = rand() % 3; // 0 lub 2 Rozpoczyna gracz / 1 rozpoczyna przeciwnik
    if (whoStartFight == 0 || whoStartFight == 2) {
        cout << "Rozpoczyna gracz" << endl;
        for (;;) {
            int choiceOfPlayer = whichAttackOfPlayer();
            if (choiceOfPlayer == 1) {
                dmg = player->attack1(opponent);
            }
            else if (choiceOfPlayer == 2){
                dmg = player->attack2();
            }
            else if (choiceOfPlayer == 3){
                dmg = player->attack3();
            }
            else if (choiceOfPlayer == 4){
                health = player->attack2();
            }
            
        }
    }
    else{
        cout << "Rozpoczyna przeciwnik" << endl;
    }
}
