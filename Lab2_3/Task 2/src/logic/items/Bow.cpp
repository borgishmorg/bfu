#include "Bow.hpp"

using BattleRoyale::Bow;

Bow::Bow():
    Weapon(NAME_, DURABILITY_, COST_, DAMAGE_, DEATH_CHANCE_, DISTANCE_){}

Bow::~Bow(){}



const std::string Bow::NAME_ = "Bow";
const int Bow::DURABILITY_ = 5;
const int Bow::COST_ = 1;
const int Bow::DAMAGE_ = 10;
const int Bow::DEATH_CHANCE_ = 0;
const int Bow::DISTANCE_ = 5;