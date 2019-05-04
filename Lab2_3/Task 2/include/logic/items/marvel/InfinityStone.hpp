#ifndef __INFINITY_STONE__
#define __INFINITY_STONE__

#include "Item.hpp"

namespace BattleRoyale{
    class InfinityStone: public Item{
        public:
            enum Type{NO_TYPE, REALITY, SOUL, MIND, SPACE, TIME, POWER};

            InfinityStone(Type type);
            ~InfinityStone();

            virtual void use(Player & user, Map & map, Screen & screen) override;

            virtual const std::string toShortString() const override;
            virtual const std::string toString() const override;

            static Type stringToType(std::string);
            static std::string typeToString(Type);
        private:
            Type type_;
    };
}

#endif