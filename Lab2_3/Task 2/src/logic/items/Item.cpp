#include "Item.hpp"

using BattleRoyale::Item;

Item::Stats::Stats(unsigned int durability, unsigned int cost, bool droppable):
    durability_(durability), cost_(cost), droppable_(droppable){}

Item::Stats::~Stats(){}



Item::Item(std::string name, unsigned int durability, unsigned int cost):
    name_(name), stats_(durability, cost, true){}

Item::~Item(){}

const std::string Item::toString() const{
    return toShortString();
}

const std::string Item::toShortString() const{
    return name_ + " (" + std::to_string(stats_.durability_) + ") ";
}



const std::string & Item::getName() const{
    return name_;
}

bool Item::isBroken() const{
    return stats_.durability_ <= 0;
}

bool Item::isDroppable() const{
    return stats_.droppable_;
}