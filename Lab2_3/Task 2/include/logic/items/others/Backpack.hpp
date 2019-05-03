#ifndef __BACKPACK__
#define __BACKPACK__

#include "Item.hpp"

namespace BattleRoyale{
    class Backpack: public Item{
        public:
            Backpack();
            ~Backpack();

            virtual void use(Player & user, Map & map, Screen & screen) override;
    };
}
#endif