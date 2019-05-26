#include "PotionOfHealth.hpp"

using BattleRoyale::PotionOfHealth;

PotionOfHealth::PotionOfHealth():
    Potion("Potion of Health"){}

PotionOfHealth::~PotionOfHealth(){}



void PotionOfHealth::drink(Player & drinker, Screen & screen){
    if(rand()%100 < 80){
        drinker.takeDamage(-100);
        screen.drawMessage(drinker.getName() + " is healed by " + name_ + "!");
    }else{
        drinker.takeDamage(30);
        screen.drawMessage(drinker.getName() + " is poisoned by " + name_ + "!");
    }
}