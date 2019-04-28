#ifndef __ITEM__
#define __ITEM__

#include <string>
#include <vector>
#include <memory>

namespace BattleRoyale{
    class Item;
}

#include "Cell.hpp"
#include "Player.hpp"

namespace BattleRoyale{
    class Item{
        public:
            struct Stats
            {
                unsigned int durability_;

                Stats(unsigned int durability);
                ~Stats();
            };
            

            Item(std::string name, unsigned int durability);
            ~Item();

            virtual void use() = 0;
            virtual const std::string toString() const = 0;
            virtual const std::string toShortString() const;

            const std::string & getName() const;
            bool isBroken() const;
        protected:
            std::string name_;
            
            Stats stats_;
            Stats maxStats_;
    };
}

#endif