#ifndef __SNIPER_RIFLE__
#define __SNIPER_RIFLE__

#include <cstdlib>

#include "Weapon.hpp"

namespace BattleRoyale{
    class SniperRifle: public Weapon{
        public:
            SniperRifle();
            ~SniperRifle();
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