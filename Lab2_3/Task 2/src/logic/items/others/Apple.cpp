#include "Apple.hpp"

using BattleRoyale::Apple;

Apple::Apple(): Item("Apple", 1, 0){}

Apple::~Apple(){}



void Apple::use(Player & user, Map & map, Screen & screen){
    if(user.getStats().HP_ <= 0)
        throw user.getName() + " can't use " + name_ + " now!";

    user.addHP(1);
    screen.drawMessage(user.getName() + " has eaten an " + name_);
    --stats_.durability_;
}