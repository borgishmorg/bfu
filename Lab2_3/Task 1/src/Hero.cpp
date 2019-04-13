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

Hero::Hero(std::string name, int hp):
    name_(name), hp_(hp), hpDelta_(0), initiative_(1), initiativeDelta_(0), durationOfPoisoning_(0), evasionType_(NO_TYPE){}

Hero::~Hero(){}

bool Hero::takeDamage(int hpDmage, int initiativeDamage, AttackType type){
    if(evasionType_ == NO_TYPE || type != evasionType_){
        hpDelta_ -= hpDmage;
        initiativeDelta_ -= initiativeDamage;
        return true;
    }
    return false;
}

bool Hero::takePoison(int durationOfPoisoning){
    durationOfPoisoning_ += durationOfPoisoning;
}

void Hero::rest(){
    evasionType_ = NO_TYPE;

    initiative_ = std::min(initiative_ + initiativeDelta_ + 1, 1);
    initiativeDelta_ = 0;

    hp_ = std::max(hp_ + hpDelta_, 0);
    hpDelta_ = 0;

    durationOfPoisoning_ = std::max(durationOfPoisoning_ - 1, 0);
}

void Hero::printParams(std::ostream & out) const{
    out << "hp = " << hp_ << "; initiative = " << initiative_ << "; duration of poisoning = " << durationOfPoisoning_;
}

void Hero::setEvasionType(AttackType type){
    evasionType_ = type;
}

const std::string & Hero::getName() const{
    return name_;
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