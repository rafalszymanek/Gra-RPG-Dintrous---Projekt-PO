#include "worrior.h"
#include <ctime>


worrior::worrior(std::string kName)
{
    // przypisujemy wartosci startowe + imie
    characterName = kName;
    health = 14;
    energy = 12;
    mana = 2;
    strength = 16;
    faith = 2;
    treatment = 4;
}

worrior::~worrior(){

}

// System walki znajduje sie w arkuszu
// Ataki

int worrior::attack1(){
    // Atak mieczem
    srand( time( NULL ) );
    energy -= 15;
    int critick = rand() % 12;
    if(critick == 12){
        return strength * 3.5;
    }
    else{
        return rand();
    }



    return 0;
}

int worrior::attack2(){
    return 0;
}

int worrior::attack3(){
    return 0;
}

//
// Pozostale systemy walki

void worrior::treatCharacter(){

}

void worrior::energyDrink(){

}

void worrior::manaDrink(){

}

// Wyswietl info o postaci
void worrior::info(){
    // Wyswiet do klasy Label informacje o postaci!
}


