#include "Sword.hpp"

using BattleRoyale::Sword;

Sword::Sword():
    Weapon(NAME_, DURABILITY_, COST_, DAMAGE_, DEATH_CHANCE_, DISTANCE_){}

Sword::~Sword(){}



const std::string Sword::NAME_ = "Highlander's sword";
const int Sword::DURABILITY_ = 100500;
const int Sword::COST_ = 1;
const int Sword::DAMAGE_ = 10;
const int Sword::DEATH_CHANCE_ = 100;
const int Sword::DISTANCE_ = 1;