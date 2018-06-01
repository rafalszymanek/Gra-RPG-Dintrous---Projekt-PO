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
    
    
    
}

worrior::~worrior(){

}

// System walki znajduje sie w arkuszu
// Ataki

int worrior::attack1(opponentCharacter* opponent){
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
            dmg = strength * (rand()%(42-30 + 1) + 30) / 10; // losuj z zakresu (nie mozemy randa  double)
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

string worrior::infoAboutClass(){
    return this->whatClass;
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
