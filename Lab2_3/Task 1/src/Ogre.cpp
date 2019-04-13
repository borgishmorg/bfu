#include "Ogre.hpp"

using Arena::AttackType;
using Arena::Ogre;
using Arena::Hero;

Ogre::Ogre():
    Arena::Hero(200){}

Ogre::~Ogre(){};

bool Ogre::attack(Hero & hero, AttackType type){
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
    }
}