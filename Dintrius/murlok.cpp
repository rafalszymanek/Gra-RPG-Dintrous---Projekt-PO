#include "murlok.h"

#include <ctime>
#include <iostream>

using namespace std;

murlok::murlok(int lvl, std::string name)
{
    currentHealth = 50 + (30*lvl);
    strenght = 7 + (1*lvl); // UWAGA, pierwszy lvl ma 8 siły!
    mana = 0;
    imgPath = ":/murloc.png";
}
murlok::~murlok(){
    
}

int murlok::attack(){
    srand(time( NULL ) );
    int critick = rand() % 12 + 1;
    if(critick == 12){
        
        return strenght * 3.5;
    }
    else{
        return strenght * (rand()%(30-15 + 1) + 15) / 10; // losuj z zakresu (nie mozemy randa  double)
    }
}

void murlok::gainDamage(int dmg){
    currentHealth -= dmg;
    this->isDead();
}

string murlok::returnImgPath(){
    return imgPath;
}

int murlok::info(int number){
    if(number==1)
        return this->currentHealth;
    return -5423;
}

bool murlok::isDead(){
    if(currentHealth<=0){
        return true;
    }
    else
        return false;}
