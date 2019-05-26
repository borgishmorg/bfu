#ifndef __FAIRY__
#define __FAIRY__

#include "Hero.hpp"

namespace Arena{
    class Fairy: public Hero{
        public:
            Fairy();
            ~Fairy();

            virtual bool attack(Hero & hero, AttackType type) override;
    };
}

#endif