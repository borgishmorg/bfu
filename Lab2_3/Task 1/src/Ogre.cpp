#include "Ogre.hpp"

using Arena::AttackType;
using Arena::Ogre;
using Arena::Hero;

Ogre::Ogre():
    Arena::Hero(200){}

Ogre::~Ogre(){};

bool Ogre::attack(Hero & hero, AttackType type){
    if(initiative_ > 0){
        --initiative_;
        switch (type)
        {
            case UP:{
                std::cout << "Ogre is hitting on the head" << std::endl; 
                return hero.takeDamage(40, 0, UP);
            }
            case MIDDLE:{
                std::cout << "Ogre is hitting on the cheast" << std::endl; 
                return hero.takeDamage(40, 0, MIDDLE);
            }
            case DOWN:{
                std::cout << "Ogre is picking his nose" << std::endl; 
                return true;
            }
            default:{
                std::cout << "Ogre is doing nothing" << std::endl;
                return true;
            }
        }
    }else{
        std::cout << "Ogre can't attack now" << std::endl;
        return false;
    }
}