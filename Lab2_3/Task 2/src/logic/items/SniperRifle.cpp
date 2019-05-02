#include "SniperRifle.hpp"

using BattleRoyale::SniperRifle;

SniperRifle::SniperRifle():
    Weapon(NAME_, DURABILITY_, COST_, DAMAGE_, DEATH_CHANCE_, DISTANCE_){}

SniperRifle::~SniperRifle(){}



const std::string SniperRifle::NAME_ = "Sniper rifle";
const int SniperRifle::DURABILITY_ = 3;
const int SniperRifle::COST_ = 3;
const int SniperRifle::DAMAGE_ = 99;
const int SniperRifle::DEATH_CHANCE_ = 99;
const int SniperRifle::DISTANCE_ = 15;