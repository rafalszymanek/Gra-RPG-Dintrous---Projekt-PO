#include "playercharacter.h"

playerCharacter::playerCharacter(std::string kName, int kHealth, int kEnergy, int kMana, int kStrength, int kFaith, int kTreatment)
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
