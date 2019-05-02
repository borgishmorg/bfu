#ifndef __SWORD__
#define __SWORD__

#include "Weapon.hpp"

namespace BattleRoyale{
    class Sword: public Weapon{
        public:
            Sword();
            ~Sword();
        private:
            static const std::string NAME_;
            static const int DURABILITY_;
            static const int COST_;
            static const int DAMAGE_;
            static const int DEATH_CHANCE_;
            static const int DISTANCE_;
    };
}
#endif