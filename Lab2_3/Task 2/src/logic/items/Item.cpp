#include "Item.hpp"

using BattleRoyale::Item;

Item::Item(std::string name, unsigned int durability):
    name_(name), durability_(durability){}

Item::~Item(){}

bool Item::isBroken() const{
    return durability_ > 0;
}