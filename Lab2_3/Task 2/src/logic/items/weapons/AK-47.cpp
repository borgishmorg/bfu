#include "AK-47.hpp"

using BattleRoyale::AK47;

AK47::AK47():
    Weapon(NAME_, DURABILITY_, COST_, DAMAGE_, DEATH_CHANCE_, DISTANCE_){}

AK47::~AK47(){}



void AK47::attack(Player & user, Player & target, Screen & screen){
    for(int i = 0; i < 3; i++){
        int damage = 1 + rand() % weaponStats_.damage_;
        target.takeDamage(damage);
        screen.drawMessage(target.getName() + " takes " + std::to_string(damage) + " damage with " + name_);
        system("pause");
    }
}



const std::string AK47::NAME_ = "AK-47";
const int AK47::DURABILITY_ = 5;
const int AK47::COST_ = 2;
const int AK47::DAMAGE_ = 15;
const int AK47::DEATH_CHANCE_ = 33;
const int AK47::DISTANCE_ = 5;