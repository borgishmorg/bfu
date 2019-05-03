#ifndef __STONE__
#define __STONE__

#include "Weapon.hpp"

namespace BattleRoyale{
    class Stone: public Weapon{
        public:
            Stone();
            ~Stone();
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