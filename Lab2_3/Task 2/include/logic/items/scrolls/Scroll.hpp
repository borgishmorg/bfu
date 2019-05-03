#ifndef __SCROLL__
#define __SCROLL__

#include <iostream>

#include "Item.hpp"
#include "MapScreenElement.hpp"

namespace BattleRoyale{
    class Scroll: public Item{
        public:
            Scroll(std::string name, unsigned int durability, unsigned int cost);
            ~Scroll();

            virtual void spell(Cell & target, Screen & screen) = 0;
            virtual void use(Player & user, Map & map, Screen & screen) override;
    };
}
#endif