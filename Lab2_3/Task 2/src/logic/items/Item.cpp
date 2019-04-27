#include "Item.hpp"

using BattleRoyale::Item;

Item::Item(std::string name, unsigned int durability):
    name_(name), durability_(durability){}

Item::~Item(){}



const std::string & Item::getName() const{
    return name_;
}

bool Item::isBroken() const{
    return durability_ > 0;
}