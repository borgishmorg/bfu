#include "Item.hpp"

using BattleRoyale::Item;

Item::Stats::Stats(unsigned int durability, unsigned int cost):
    durability_(durability), cost_(cost){}

Item::Stats::~Stats(){}



Item::Item(std::string name, unsigned int durability, unsigned int cost):
    name_(name), stats_(durability, cost), maxStats_(durability, cost){}

Item::~Item(){}

const std::string Item::toShortString() const{
    return name_ + " (" + std::to_string(stats_.durability_) + "/" + std::to_string(maxStats_.durability_) + ") ";
}

const std::string & Item::getName() const{
    return name_;
}

bool Item::isBroken() const{
    return stats_.durability_ <= 0;
}