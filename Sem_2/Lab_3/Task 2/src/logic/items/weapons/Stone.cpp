#include "Stone.hpp"

using BattleRoyale::Stone;

Stone::Stone():
    Weapon(NAME_, DURABILITY_, COST_, DAMAGE_, DEATH_CHANCE_, DISTANCE_){}

Stone::~Stone(){}



const std::string Stone::NAME_ = "Stone";
const int Stone::DURABILITY_ = 1;
const int Stone::COST_ = 1;
const int Stone::DAMAGE_ = 5;
const int Stone::DEATH_CHANCE_ = 0;
const int Stone::DISTANCE_ = 3;