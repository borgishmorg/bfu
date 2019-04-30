#ifndef __ITEM__
#define __ITEM__

#include <string>
#include <memory>

namespace BattleRoyale{
    class Item;
}

#include "Map.hpp"
#include "Player.hpp"
#include "Screen.hpp"

namespace BattleRoyale{
    class Item{
        public:
            struct Stats
            {
                unsigned int durability_;
                unsigned int cost_;
                bool droppable_;

                Stats(unsigned int durability, unsigned int cost, bool droppable);
                ~Stats();
            };
            

            Item(std::string name, unsigned int durability, unsigned int cost);
            ~Item();

            virtual void use(Player & user, Map & map, Screen & screen) = 0;
            virtual const std::string toString() const;
            virtual const std::string toShortString() const;

            const std::string & getName() const;
            bool isBroken() const;
            bool isDroppable() const;
        protected:
            std::string name_;
            
            Stats stats_;
    };
}
#endif