#include "Hero.hpp"

namespace Arena{
    class Vampire: public Hero{
        public:
            Vampire();
            ~Vampire();

            virtual bool attack(Hero & hero, AttackType type) override;
    };
}