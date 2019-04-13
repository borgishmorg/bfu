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
    hp_(hp), initiative_(0), initiativeDelta_(0), durationOfPoisoning_(0), evasionType_(NO_TYPE){}

Hero::~Hero(){}

bool Hero::takeDamage(int hpDmage, int initiativeDamage, AttackType type){
    if(evasionType_ == NO_TYPE || type != evasionType_){
        hp_ -= hpDmage;
        initiativeDelta_ -= initiativeDamage;
        return true;
    }
    return false;
}

bool Hero::takePoison(int durationOfPoisoning){
    durationOfPoisoning_ += durationOfPoisoning;
}

void Hero::rest(){
    initiative_ = std::min(initiative_ + initiativeDelta_ + 1, 1);
    initiativeDelta_ = 0;
    durationOfPoisoning_ = std::max(durationOfPoisoning_ - 1, 0);
}

void Hero::printParams(std::ostream & out) const{
    out << "hp = " << hp_ << "; initiative = " << initiative_ << "; duration of poisoning = " << durationOfPoisoning_;
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

const bool Hero::isPoisoned() const{
    return durationOfPoisoning_ > 0;
}

std::ostream & operator<<(std::ostream & out, const Hero & hero){
    hero.printParams(out);
    return out;
}