#include <string>
#include <iostream>
#include "Hero.hpp"

using Arena::AttackType;
using Arena::Hero;

AttackType Arena::stringToAttackType(std::string type){
    if(type == "up" || type == "u")
        return UP;
    if(type == "middle" || type == "m")
        return MIDDLE;
    if(type == "down" || type == "d")
        return DOWN;
    return NO_TYPE;
}

Hero::Hero(int hp):
    hp_(hp), initiative_(0), evasionType_(NO_TYPE){}

Hero::~Hero(){}

bool Hero::takeDamage(int hpDmage, int initiativeDamage, AttackType type){
    if(evasionType_ == NO_TYPE || type != evasionType_){
        hp_ -= hpDmage;
        initiative_ -= initiativeDamage;
        return true;
    }
    return false;
}

void Hero::rest(){
    initiative_ = std::min(initiative_ + 1, 1);
}

void Hero::setEvasionType(AttackType type){
    evasionType_ = type;
}

const int Hero::getHp() const{
    return hp_;
}

const int Hero::getInitiative() const{
    return initiative_;
}

const bool Hero::isAlive() const{
    return (hp_ > 0);
}