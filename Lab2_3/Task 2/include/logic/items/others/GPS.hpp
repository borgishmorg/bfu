#ifndef __GPS__
#define __GPS__

#include "Item.hpp"

namespace BattleRoyale{
    class GPS: public Item{
        public:
            GPS();
            ~GPS();

            virtual void use(Player & user, Map & map, Screen & screen) override;

            virtual const std::string toString() const override;
    };
}
#endif