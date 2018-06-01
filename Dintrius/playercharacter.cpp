#include "playercharacter.h"

playerCharacter::playerCharacter(std::string kName, std::string kClass, int kStrength, int kHealth, int kEnergy, int kFaith, int kMana, int kTreatment)
{
    characterName = kName;
    whatClass = kClass;
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
