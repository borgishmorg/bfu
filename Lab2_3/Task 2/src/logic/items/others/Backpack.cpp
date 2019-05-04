#include "Backpack.hpp"

using BattleRoyale::Backpack;

Backpack::Backpack(): Item("Backpack", 1, 0){}

Backpack::~Backpack(){}



void Backpack::use(Player & user, Map & map, Screen & screen){
    if(user.getStats().HP_ <= 0)
        throw user.getName() + " can't use " + name_ + " now!";

    user.addUpgradePoints(1);
    user.upgrade(Player::CP, 1);
    screen.drawMessage(user.getName() + " has eaten an " + name_);
    --stats_.durability_;
}