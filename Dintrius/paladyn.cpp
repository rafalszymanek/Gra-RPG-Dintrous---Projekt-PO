#include <ctime>
#include <iostream>

#include "paladyn.h"
#include "opponent.h"

using namespace std;

paladyn::paladyn(string kName, int kStrength, int kHealth, int kEnergy, int kFaith, int kMana, int kTreatment)
    :playerCharacter(kName, kStrength, kHealth, kEnergy, kFaith, kMana, kTreatment)
{
    // przypisujemy wartosci startowe + imie

    setMaxValues();

    whatClass = "paladyn";
    imgPath = ":/paladyn.png";


}

paladyn::~paladyn(){
    characterName = "";
    health = 0;
    energy = 0;
    mana = 0;
    strength = 0;
    faith = 0;
    treatment = 0;

    maxHealth = 0;
    maxEnergy = 0;;
    maxMana = 0;

    currentHealth = 0;
    currentEnergy = 0;
    currentMana = 0;

    whatClass = "";
    imgPath = "";
}

// System walki znajduje sie w arkuszu
// Ataki

int paladyn::attack1(opponentCharacter* opponent){
    // Atak mieczem
    int dmg = 0;

    if (currentEnergy >= 15) {
        srand(time( NULL ) );
        currentEnergy -= 15;
        int critick = rand() % 12 + 1;
        if(critick == 12){
            dmg = strength * 3.5;
            opponent -> gainDamage(dmg);
            return dmg;
        }
        else{
            dmg = strength * (rand()%(30-15 + 1) + 15) / 10; // losuj z zakresu (nie mozemy randa  double)
            opponent->gainDamage(dmg);
            return dmg;
        }
    }
    else{
        cout << "Zbyt malo energii!";
    }
    return 0;
}

int paladyn::attack2(opponentCharacter* opponent){
    // Potezny cios
    int dmg = 0;
    if (currentEnergy >= 40) {
        srand(time( NULL ) );
        currentEnergy -= 40;
        int critick = rand() % 12 + 1;
        if(critick == 6){ // polowa (jeden z 12)
            cout << "Critick!" <<endl;
            return strength * 3.7;
        }
        else{
            dmg = strength * (rand()%(35-20 + 1) + 20) / 10; // losuj z zakresu (nie mozemy randa  double)
            opponent->gainDamage(dmg);
            return dmg;

        }
    }
    else{
        cout << "Zbyt malo energii!";
    }
    return 0;
}

int paladyn::attack3(opponentCharacter* opponent){
    // Spirala smierci
    int dmg = 0;
    if (currentMana >= 50) {
        srand(time( NULL ) );
        currentMana -= 50;
        int critick = rand() % 20 + 1;
        if(critick == 10){
            cout << "Critick!" <<endl;
            return strength * 5.2;
        }
        else{
            dmg = strength * (rand()%(50-46 + 1) + 46) / 10; // losuj z zakresu (nie mozemy randa  double)
            opponent->gainDamage(dmg);
            return dmg;
        }
    }
    else{
        cout << "Zbyt malo energii!";
    }
    return 0;
}

void paladyn::gainDamage(int dmg){
    currentHealth -= dmg;
    this->isDead();
}
//
// Pozostale systemy walki

void paladyn::treatCharacter(){
    currentHealth += treatment * 30;
    if (currentHealth > maxHealth) {
        currentHealth = maxHealth;
    }
}

void paladyn::energyDrink(){
    currentEnergy += 60;
    if (currentEnergy > maxEnergy) {
        currentEnergy = maxEnergy;
    }
}

void paladyn::manaDrink(){
    currentMana += 60;
    if (currentMana > maxMana) {
        currentMana = maxMana;
    }
}

// Wyswietl info o postaci
void paladyn::info(){
    cout << "Informacje o postaci"<< endl;
    cout << characterName << endl;
    cout << currentHealth<< endl;
    cout << currentEnergy<< endl;
    cout << currentMana<< endl;
    // Wyswiet do klasy Label informacje o postaci!
}

int paladyn::infoAboutClass(int number){
    if(number == 0){
        return this->strength;
    }
    else if(number == 1){
        return this->health;
    }
    else if(number == 2){
        return this->strength;
    }
    else if(number == 3){
        return this->energy;
    }
    else if(number == 4){
        return this->faith;
    }
    else if(number == 5){
        return this->mana;
    }
    else if(number == 6){
        return this->treatment;
    }
    else if(number == 7){
        return this->currentHealth;
    }
    else if(number == 8){
        return this->currentEnergy;
    }
    else if(number == 9){
        return this->currentMana;
    }
    return 0;
}

string paladyn::returnImgPath(){
    return this->imgPath;
}

string paladyn::returnName(){
    return this->characterName;
}

bool paladyn::isDead(){
    if(currentHealth<=0){
        return true;
    }
    else
        return false;
}

bool paladyn::eneughAttack1(){
    if(currentEnergy>=15)
        return true;
    else
        return false;
}
bool paladyn::eneughAttack2(){
    if(currentEnergy>=40)
        return true;
    else
        return false;
}
bool paladyn::eneughAttack3(){
    if(currentMana>=50)
        return true;
    else
        return false;
}

string paladyn::whatAClass(){
    return whatClass;
}

void paladyn::afterFight(){
    currentHealth = maxHealth;
    currentEnergy = maxEnergy;
    currentMana = maxMana;

}

void paladyn::setMaxValues(){
    maxHealth = health *20;
    maxEnergy = energy * 10;
    maxMana = mana * 20;

    afterFight();
}






