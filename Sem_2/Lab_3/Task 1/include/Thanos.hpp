#ifndef __THANOS__
#define __THANOS__

#include "Hero.hpp"

namespace Arena{
    class Thanos: public Hero{
        public:
            Thanos();
            ~Thanos();

            virtual bool attack(Hero & hero, AttackType type) override;
            virtual bool takeDamage(int hpDamage, int initiativeDamage, AttackType type) override;
            
            virtual void printParams(std::ostream & out) const override;
    };
}

#endif