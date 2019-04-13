#include "Hero.hpp"

namespace Arena{
    class Knight: public Hero{
        public:
            Knight();
            ~Knight();

            virtual bool attack(Hero & hero, AttackType type) override;
            virtual bool takeDamage(int hpDamage, int initiativeDamage, AttackType type) override;
        protected:
            int armor_;
            int maxArmor_;
    };
}