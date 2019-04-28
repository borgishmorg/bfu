#ifndef __KEYBOARD__
#define __KEYBOARD__

#include <string>
#include <iostream>

#include "Item.hpp"

namespace BattleRoyale{
    class Keyboard: public Item {
        public:
            Keyboard();
            ~Keyboard();
            virtual void use(Player & user, Map & map, Screen & screen) override;
            virtual const std::string toString() const override;
    };
}

#endif