#include "InfinityStone.hpp"

using BattleRoyale::InfinityStone;



InfinityStone::InfinityStone(Type type):
    Item(typeToString(type), 1, 2000000000), type_(type){}

InfinityStone::~InfinityStone(){};



void InfinityStone::use(Player & user, Map & map, Screen & screen){
    screen.drawMessage(user.getName() + " is feeling the power of " + name_ + "!");
}



const std::string InfinityStone::toString() const{
    return name_;   
}



InfinityStone::Type InfinityStone::stringToType(std::string str){
    if(str == "Reality Stone") return REALITY;
    else if(str == "Soul Stone") return SOUL;
    else if(str == "Mind Stone") return MIND;
    else if(str == "Space Stone") return SPACE;
    else if(str == "Time Stone") return TIME;
    else if(str == "Power Stone") return POWER;
    else return NO_TYPE;
}

std::string InfinityStone::typeToString(Type type){
    if(type == REALITY) return "Reality Stone";
    else if(type == SOUL) return "Soul Stone";
    else if(type == MIND) return "Mind Stone";
    else if(type == SPACE) return "Space Stone";
    else if(type == TIME) return "Time Stone";
    else if(type == POWER) return "Power Stone";
    else return "NO_TYPE";
}