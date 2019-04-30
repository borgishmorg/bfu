#ifndef __Label__
#define __Label__

#include <string>
#include <iostream>

#include "Item.hpp"

namespace BattleRoyale{
    class Label: public Item {
        public:
            Label();
            ~Label();
            virtual void use(Player & user, Map & map, Screen & screen) override;
    };
}

#endif