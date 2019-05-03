#ifndef __POTION_OF_HEALTH__
#define __POTION_OF_HEALTH__

#include <cstdlib>

#include "Potion.hpp"

namespace BattleRoyale{
    class PotionOfHealth: public Potion{
        public:
            PotionOfHealth();
            ~PotionOfHealth();

            virtual void drink(Player & drinker, Screen & screen) override;
    };
}
#endif