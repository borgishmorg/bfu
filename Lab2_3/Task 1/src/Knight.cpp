#include "Knight.hpp"

using Arena::AttackType;
using Arena::Hero;
using Arena::Knight;

Knight::Knight():
    Hero("Knight", 150), armor_(50), armorDelta_(0), maxArmor_(90){};

Knight::~Knight(){};

bool Knight::attack(Hero & hero, AttackType type){
    if(initiative_ > 0){
        --initiative_;
        switch (type)
        {
            case UP:{
                std::cout << "Knight is raising his shield" << std::endl;
                armorDelta_ = std::min(armor_ + 10, maxArmor_);
                return true;        
            }
            case MIDDLE:{
                std::cout << "Knight is attacking by shield" << std::endl;
                bool res = hero.takeDamage(armor_, 0, MIDDLE);
                armorDelta_ -= 10;
                return res;
            }
            case DOWN:{
                std::cout << "Knight is taking vow of silence" << std::endl;
                hpDelta_ -= 50;
                armorDelta_ = maxArmor_ - armor_;
                return true;
            }
            default:{
                std::cout << "Knight is doing nothing" << std::endl;
                return true;
            }
        }
    }else{
        std::cout << "Knight can't attack now" << std::endl;
        return false;
    }
}

bool Knight::takeDamage(int hpDamage, int initiativeDamage, AttackType type){
    return Hero::takeDamage(hpDamage*armor_/100, initiativeDamage, type);
}

void Knight::rest(){
    Hero::rest();
    armor_ = std::max(0, std::min(armor_ + armorDelta_, maxArmor_));
    armorDelta_ = 0;
}

void Knight::printParams(std::ostream & out) const{
    Hero::printParams(out);
    out << "; armor = " << armor_;
}