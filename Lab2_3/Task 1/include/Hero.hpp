#ifndef __Hero__
#define __Hero__

#include <string>
#include <iostream>

namespace Arena{
    
    enum AttackType{NO_TYPE, UP, MIDDLE, DOWN};

    AttackType stringToAttackType(std::string);

    class Hero{
        public:

            Hero(std::string name, int hp);
            ~Hero();

            virtual bool attack(Hero &, AttackType) = 0;
            virtual bool takeDamage(int hpDamage, int initiativeDamage, AttackType type);
            virtual bool takePoison(int durationOfPoisoning);
            virtual void rest();
            virtual void printParams(std::ostream &) const;

            void setEvasionType(AttackType);
            const std::string & getName() const;
            const int getHp() const;
            const int getInitiative() const;
            const bool isAlive() const;
            const bool isPoisoned() const;
        protected:
            std::string name_;
            int hpDelta_;
            int initiativeDelta_;
            int durationOfPoisoning_;
            AttackType evasionType_;
        private:
            int hp_;
            int initiative_;
    };

}

std::ostream & operator<<(std::ostream & out, const Arena::Hero & hero);

#endif