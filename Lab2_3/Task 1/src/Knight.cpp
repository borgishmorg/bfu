#include "Knight.hpp"

using Arena::AttackType;
using Arena::Hero;
using Arena::Knight;

Knight::Knight():
    Hero(150), armor_(50), maxArmor_(90){};

Knight::~Knight(){};

bool Knight::attack(Hero & hero, AttackType type){
    if(initiative_ > 0){
        --initiative_;
        switch (type)
        {
            case UP:{
                std::cout << "Knight is raising his shield" << std::endl;
                armor_ = std::min(armor_ + 10, maxArmor_);
                return true;        
            }
            case MIDDLE:{
                std::cout << "Knight is attacking by shield" << std::endl;
                bool res = hero.takeDamage(armor_, 0, MIDDLE);
                armor_ = std::max(0, armor_ - 10);
                return res;
            }
            case DOWN:{
                std::cout << "Knight is taking vow of silence" << std::endl;
                hp_ -= 50;
                armor_ = maxArmor_;
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

void Knight::printParams(std::ostream & out) const{
    Hero::printParams(out);
    out << "; armor = " << armor_;
}