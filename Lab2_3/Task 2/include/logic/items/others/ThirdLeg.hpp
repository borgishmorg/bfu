#ifndef __THIRD_LEG__
#define __THIRD_LEG__

#include "Item.hpp"

namespace BattleRoyale{
    class ThirdLeg: public Item{
        public:
            ThirdLeg();
            ~ThirdLeg();

            virtual void use(Player & user, Map & map, Screen & screen) override;
    };
}
#endif