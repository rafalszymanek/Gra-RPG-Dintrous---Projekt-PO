#include <iostream>
#include "playercharacter.h"

using namespace std;
playerCharacter::playerCharacter(std::string kName, int kStrength, int kHealth, int kEnergy, int kFaith, int kMana, int kTreatment)
{
    characterName = kName;
    health = kHealth;
    energy = kEnergy;
    mana = kMana;
    strength = kStrength;
    faith = kFaith;
    treatment = kTreatment;
}

playerCharacter::~playerCharacter(){
    characterName = "";
    health = 0;
    energy = 0;
    mana = 0;
    strength = 0;
    faith = 0;
    treatment = 0;
}

void playerCharacter::operator+(int i){
    this->strength += i;
    this->health += i;
    this->energy += i;
    this->faith += i;
    this->mana += i;
    this->treatment += i;
    
    this->setMaxValues();

}

std::ostream & operator <<( std::ostream & s, const playerCharacter & v )
{
    return s << "Statystyki postaci "
    << "Sila: " << std::to_string(v.strength) << endl
    << "Życie: " << std::to_string(v.health) << endl
    << "Energia: " << std::to_string(v.energy)<< endl
    << "Wiara: " << std::to_string(v.faith)<< endl
    << "Mana: " << std::to_string(v.mana)<< endl
    << "Lecznictwo: " << std::to_string(v.treatment);
}
