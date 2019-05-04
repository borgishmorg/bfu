#include "GrenadeLauncher.hpp"

using BattleRoyale::GrenadeLauncher;

GrenadeLauncher::GrenadeLauncher():
    Weapon(NAME_, DURABILITY_, COST_, DAMAGE_, DEATH_CHANCE_, DISTANCE_), backfireChance_(BACKFIRE_CHANCE_){}

GrenadeLauncher::~GrenadeLauncher(){}



void GrenadeLauncher::attack(Player & user, Player & target, Screen & screen){
    if(rand()%100 < backfireChance_){
        user.takeDamage(weaponStats_.damage_);
        screen.drawMessage("Backfire!\n" + user.getName() + " takes " + std::to_string(weaponStats_.damage_) + " damage with " + name_);
        system("pause");
    }else{
        target.takeDamage(weaponStats_.damage_);
        screen.drawMessage(target.getName() + " takes " + std::to_string(weaponStats_.damage_) + " damage with " + name_);
        system("pause");
    }
}



const std::string GrenadeLauncher::NAME_ = "Grenade launcher";
const int GrenadeLauncher::DURABILITY_ = 10;
const int GrenadeLauncher::COST_ = 3;
const int GrenadeLauncher::DAMAGE_ = 80;
const int GrenadeLauncher::DEATH_CHANCE_ = 20;
const int GrenadeLauncher::DISTANCE_ = 3;
const int GrenadeLauncher::BACKFIRE_CHANCE_ = 10;