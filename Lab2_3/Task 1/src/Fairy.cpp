#include "Fairy.hpp"

using Arena::Fairy;
using Arena::Hero;
using Arena::AttackType;

Fairy::Fairy():
    Hero("Fairy", 30){}

Fairy::~Fairy(){};

bool Fairy::attack(Hero & hero, AttackType type){
    if(getInitiative() > 0){
        --initiativeDelta_;
        switch (type)
        {
            case UP:{
                std::cout << "Fairy is trying to stun her enemy" << std::endl;
                return hero.takeDamage(0, 1, UP);
            }
            case MIDDLE:{
                std::cout << "Fairy is stinging her enemy" << std::endl;
                if(hero.isPoisoned())
                    return hero.takeDamage(20, 0, MIDDLE);
                else
                    return hero.takeDamage(2, 0, MIDDLE);
            }
            case DOWN:{
                std::cout << "Fairy is giving her enemy an old fruit" << std::endl; 
                hero.takePoison(10);
                return true;
            }
            default:{
                std::cout << "Fairy is doing nothing" << std::endl;
                return true;
            }
        }
    }else{
        std::cout << "Fairy can't attack now" << std::endl;
        return false;
    }
}