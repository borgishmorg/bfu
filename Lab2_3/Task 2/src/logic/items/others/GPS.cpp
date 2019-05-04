#include "GPS.hpp"

using BattleRoyale::GPS;

GPS::GPS(): Item("GPS", 1, 0){}

GPS::~GPS(){}



void GPS::use(Player & user, Map & map, Screen & screen){
    if(user.getStats().HP_ <= 0)
        throw user.getName() + " can't use " + name_ + " now!";

    unsigned int hPos = user.getPos()->getHPos();
    unsigned int wPos = user.getPos()->getWPos();
    screen.drawMessage(user.getName() + " position is (" + std::to_string(hPos) + ";" + std::to_string(wPos) + ")");
}



const std::string GPS::toString() const{
    return name_ + " " + std::to_string(stats_.cost_) + "p";
}