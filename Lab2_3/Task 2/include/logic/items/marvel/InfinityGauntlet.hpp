#ifndef __INFINITY_GAUNTLET__
#define __INFINITY_GAUNTLET__

#include <vector>

#include "Item.hpp"
#include "InfinityStone.hpp"

namespace BattleRoyale{
    class InfinityGauntlet: public Item{
        public:
            InfinityGauntlet();
            ~InfinityGauntlet();

            virtual void use(Player & user, Map & mao, Screen & screen) override;

            virtual const std::string toString() const override;
        private:
            enum State{EMPTY, FULL, BROKEN};

            State state_;
    };
}
#endif