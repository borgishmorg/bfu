#ifndef __POTION_OF_CHEERFULNESS__
#define __POTION_OF_CHEERFULNESS__

#include <cstdlib>

#include "Potion.hpp"

namespace BattleRoyale{
    class PotionOfCheerfulness: public Potion{
        public:
            PotionOfCheerfulness();
            ~PotionOfCheerfulness();

            virtual void drink(Player & drinker, Screen & screen) override;
    };
}
#endif