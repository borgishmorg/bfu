#ifndef __APPLE__
#define __APPLE__

#include "Item.hpp"

namespace BattleRoyale{
    class Apple: public Item{
        public:
            Apple();
            ~Apple();

            virtual void use(Player & user, Map & map, Screen & screen) override;
    };
}
#endif