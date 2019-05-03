#include "Potion.hpp"

using BattleRoyale::Potion;

Potion::Potion(std::string name):
    Item(name, 1, 1){}

Potion::~Potion(){}



void Potion::use(Player & user, Map & map, Screen & screen){
    if (!user.isActive() || user.getStats().AP_ < 1)
        throw user.getName() + " can't use " + name_ + " now!";
    
    drink(user, screen);
    --stats_.durability_;
    user.addAP(-1);
}