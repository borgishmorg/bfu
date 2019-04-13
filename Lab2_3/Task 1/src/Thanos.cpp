#include "Thanos.hpp"

using Arena::AttackType;
using Arena::Hero;
using Arena::Thanos;

Thanos::Thanos():
    Hero("Thanos", 2018){};

Thanos::~Thanos(){};

bool Thanos::attack(Hero & hero, AttackType type){ 
    std::cout << "Thanos is destroying half of the enemy body" << std::endl;
    if(hero.getHp() == 1)
        return hero.takeDamage(1, 0, THANOS);
    else
        return hero.takeDamage(hero.getHp()/2, 0, THANOS);    
}

bool Thanos::takeDamage(int hpDamage, int initiativeDamage, AttackType type){
    return false;
}

void Thanos::printParams(std::ostream & out) const{
    Hero::printParams(out);
    out << "; stones = all (What did it cost?)" ;
}