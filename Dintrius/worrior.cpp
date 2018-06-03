#include <ctime>
#include <iostream>

#include "worrior.h"
#include "opponent.h"

using namespace std;

worrior::worrior(string kName, string kClass, int kStrength, int kHealth, int kEnergy, int kFaith, int kMana, int kTreatment)
    :playerCharacter(kName, kClass, kStrength, kHealth, kEnergy, kFaith, kMana, kTreatment)
{
    // przypisujemy wartosci startowe + imie
    
    maxHealth = health *20;
    maxEnergy = energy * 10;
    maxMana = mana * 20;
    
    currentHealth = maxHealth;
    currentEnergy = maxEnergy;
    currentMana = maxMana;

    whatClass = "worrior";
    imgPath = ":/worrior1.png";
    
    
}

worrior::~worrior(){
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

int worrior::attack1(opponentCharacter* opponent){
    // Atak mieczem
    int dmg = 0;
    
    if (currentEnergy >= 25) {
        srand(time( NULL ) );
        currentEnergy -= 25;
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

int worrior::attack2(opponentCharacter* opponent){
    // Potezny cios
    int dmg = 0;
    if (currentEnergy >= 35) {
        srand(time( NULL ) );
        currentEnergy -= 35;
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

int worrior::attack3(opponentCharacter* opponent){
    // Spirala smierci
    int dmg = 0;
    if (currentEnergy >= 60) {
        srand(time( NULL ) );
        currentEnergy -= 60;
        int critick = rand() % 20 + 1;
        if(critick == 10){
            cout << "Critick!" <<endl;
            return strength * 4.4;
        }
        else{
            dmg = strength * (rand()%(42-40 + 1) + 40) / 10; // losuj z zakresu (nie mozemy randa  double)
            opponent->gainDamage(dmg);
            return dmg;
        }
    }
    else{
        cout << "Zbyt malo energii!";
    }
    return 0;
}

void worrior::gainDamage(int dmg){
    currentHealth -= dmg;
    this->isDead();
}
//
// Pozostale systemy walki

void worrior::treatCharacter(){
    currentHealth += treatment * 30;
    if (currentHealth > maxHealth) {
        currentHealth = maxHealth;
    }
}

void worrior::energyDrink(){
    currentEnergy += 60;
    if (currentEnergy > maxEnergy) {
        currentEnergy = maxEnergy;
    }
}

void worrior::manaDrink(){
    currentMana += 60;
    if (currentMana > maxMana) {
        currentMana = maxMana;
    }
}

// Wyswietl info o postaci
void worrior::info(){
    cout << "Informacje o postaci"<< endl;
    cout << characterName << endl;
    cout << currentHealth<< endl;
    cout << currentEnergy<< endl;
    cout << currentMana<< endl;
    // Wyswiet do klasy Label informacje o postaci!
}

int worrior::infoAboutClass(int number){
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

string worrior::returnImgPath(){
    return this->imgPath;
}

string worrior::returnName(){
    return this->characterName;
}

bool worrior::isDead(){
    if(currentHealth<=0){
        return true;
    }
    else
        return false;
}

bool worrior::eneughAttack1(){
    if(currentEnergy>=25)
        return true;
    else
        return false;
}
bool worrior::eneughAttack2(){
    if(currentEnergy>=35)
        return true;
    else
        return false;
}
bool worrior::eneughAttack3(){
    if(currentEnergy>=60)
        return true;
    else
        return false;
}

string worrior::whatAClass(){
    return whatClass;
}

void worrior::afterFight(){
    currentHealth = maxHealth;
    currentEnergy = maxEnergy;
    currentMana = maxMana;

}
