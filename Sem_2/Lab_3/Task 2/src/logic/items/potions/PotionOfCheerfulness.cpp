#include "PotionOfCheerfulness.hpp"

using BattleRoyale::PotionOfCheerfulness;

PotionOfCheerfulness::PotionOfCheerfulness():
    Potion("Potion of Cheerfulness"){}

PotionOfCheerfulness::~PotionOfCheerfulness(){}



void PotionOfCheerfulness::drink(Player & drinker, Screen & screen){
    int deltaAP = 1 + rand()%10;
    drinker.takeFatigue(-deltaAP);
    screen.drawMessage(drinker.getName() + " is fealling much cheerful by " + name_);
}