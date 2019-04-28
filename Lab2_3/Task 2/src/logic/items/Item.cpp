#include "Item.hpp"

using BattleRoyale::Item;

Item::Stats::Stats(unsigned int durability):
    durability_(durability){}

Item::Stats::~Stats(){}



Item::Item(std::string name, unsigned int durability):
    name_(name), stats_(durability), maxStats_(durability){}

Item::~Item(){}

const std::string Item::toShortString() const{
    return name_ + " (" + std::to_string(stats_.durability_) + "/" + std::to_string(maxStats_.durability_) + ") ";
}

const std::string & Item::getName() const{
    return name_;
}

bool Item::isBroken() const{
    return stats_.durability_ > 0;
}