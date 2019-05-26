#include "Vampire.hpp"

using Arena::AttackType;
using Arena::Hero;
using Arena::Vampire;

Vampire::Vampire():
    Hero("Vampire", 100){};

Vampire::~Vampire(){};

bool Vampire::attack(Hero & hero, AttackType type){
    if(getInitiative() > 0){
        --initiativeDelta_;
        switch (type)
        {
            case UP:{
                std::cout << "Vampire is stealing stamina of the enemy" << std::endl;
                if(hero.takeDamage(15, 0, UP)){
                    hpDelta_ += 15;
                    return true;
                }
                return false;          
            }
            case MIDDLE:{
                std::cout << "Vampire is hitting by sword" << std::endl;
                return hero.takeDamage(0.8*(100-getHp()), 0, MIDDLE);
            }
            case DOWN:{
                std::cout << "Vampire is kicking his enemy" << std::endl;
                return hero.takeDamage(0.5*getHp(), 0, DOWN);
            }
            default:{
                std::cout << "Vampire is doing nothing" << std::endl;
                return true;
            }
        }
    }else{
        std::cout << "Vampire can't attack now" << std::endl;
        return false;
    }
}