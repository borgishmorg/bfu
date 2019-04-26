#ifndef __ITEM__
#define __ITEM__

#include <string>

namespace BattleRoyale{
    class Item;
}

#include "Cell.hpp"
#include "Player.hpp"

namespace BattleRoyale{
    class Item{
        public:
            Item(std::string name, unsigned int durability);
            ~Item();

            virtual void use(Cell & destination) = 0;
            virtual const std::string toString() const = 0;

            bool isBroken() const;
        protected:
            std::string name_;
            unsigned int durability_;
    };
}

#endif