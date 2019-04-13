#ifndef __Hero__
#define __Hero__

#include <string>
#include <iostream>

namespace Arena{
    
    enum AttackType{NO_TYPE, UP, MIDDLE, DOWN};

    AttackType stringToAttackType(std::string);

    class Hero{
        public:

            Hero(int hp);
            ~Hero();

            virtual bool attack(Hero &, AttackType) = 0;
            virtual bool takeDamage(int hpDamage, int initiativeDamage, AttackType type);
            virtual void rest();

            void setEvasionType(AttackType);
            const int getHp() const;
            const int getInitiative() const;
            const bool isAlive() const;
        protected:
            int hp_;
            int initiative_;
            AttackType evasionType_;
    };

}

#endif