#ifndef __KNIGHT__
#define __KNIGHT__

#include "Hero.hpp"

namespace Arena{
    class Knight: public Hero{
        public:
            Knight();
            ~Knight();

            virtual bool attack(Hero & hero, AttackType type) override;
            virtual bool takeDamage(int hpDamage, int initiativeDamage, AttackType type) override;
            virtual void rest() override;
            virtual void printParams(std::ostream & out) const override;
        protected:
            int armorDelta_;
        private:
            int armor_;
            int maxArmor_;
    };
}

#endif