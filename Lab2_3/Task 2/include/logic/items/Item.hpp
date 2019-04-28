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
#include "Map.hpp"
#include "CharMatrix.hpp"
#include "Screen.hpp"

namespace BattleRoyale{
    class Item{
        public:
            struct Stats
            {
                unsigned int durability_;
                unsigned int cost_;

                Stats(unsigned int durability, unsigned int cost);
                ~Stats();
            };
            

            Item(std::string name, unsigned int durability, unsigned int cost);
            ~Item();

            virtual void use(Player & user, Map & map, Screen & screen) = 0;
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