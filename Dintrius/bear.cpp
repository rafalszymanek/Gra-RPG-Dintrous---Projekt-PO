#include "bear.h"

#include <ctime>
#include <iostream>

using namespace std;

bear::bear(int lvl, std::string imagePath)
{
    currentHealth = 50 + (30*lvl);
    strenght = 7 + (1*lvl); // UWAGA, pierwszy lvl ma 8 siły!
    mana = 0;
    imgPath = imagePath;
}
bear::~bear(){

}

int bear::attack(){
    srand(time( NULL ) );
    int critick = rand() % 12 + 1;
    if(critick == 12){

        return strenght * 3.5;
    }
    else{
        return strenght * (rand()%(30-15 + 1) + 15) / 10; // losuj z zakresu (nie mozemy randa  double)
    }
}

void bear::gainDamage(int dmg){
    currentHealth -= dmg;
    this->isDead();
}

string bear::returnImgPath(){
    return imgPath;
}

int bear::info(int number){
    if(number==1)
        return this->currentHealth;
    return -5423;
}

bool bear::isDead(){
    if(currentHealth<=0){
        return true;
    }
    else
        return false;}

void bear::operator=(playerCharacter *player){
    this->strenght = player->infoAboutClass(1);
}
