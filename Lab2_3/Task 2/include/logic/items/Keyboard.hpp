#ifndef __KEYBOARD__
#define __KEYBOARD__

#include "Item.hpp"

namespace BattleRoyale{
    class Keyboard: public Item {
        public:
            Keyboard();
            ~Keyboard();
            virtual void use(Cell & destination) override;
            virtual const std::string toString() const override;
    };
    
}

#endif