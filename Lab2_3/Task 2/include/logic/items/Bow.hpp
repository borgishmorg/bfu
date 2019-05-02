#ifndef __BOW__
#define __BOW__

#include "Weapon.hpp"

namespace BattleRoyale{
    class Bow: public Weapon{
        public:
            Bow();
            ~Bow();
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