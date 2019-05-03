#ifndef __POTION__
#define __POTION__

#include "Item.hpp"

namespace BattleRoyale{
    class Potion: public Item{
        public:
            Potion(std::string name);
            ~Potion();

            virtual void drink(Player & drinker, Screen & screen) = 0;
            virtual void use(Player & user, Map & map, Screen & screen) override;
    };
}
#endif