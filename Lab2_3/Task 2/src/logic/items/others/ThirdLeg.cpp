#include "ThirdLeg.hpp"

using BattleRoyale::ThirdLeg;

ThirdLeg::ThirdLeg(): Item("Third leg", 1, 0){}

ThirdLeg::~ThirdLeg(){}



void ThirdLeg::use(Player & user, Map & map, Screen & screen){
    if(user.getStats().HP_ <= 0)
        throw user.getName() + " can't use " + name_ + " now!";

    user.addUpgradePoints(1);
    user.upgrade(Player::AP, 1);
    screen.drawMessage(user.getName() + " has eaten an " + name_);
    --stats_.durability_;
}