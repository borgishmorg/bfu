#ifndef __SCROLL_OF_CLUMSINESS__
#define __SCROLL_OF_CLUMSINESS__

#include <cstdlib>

#include "Scroll.hpp"

namespace BattleRoyale{
    class ScrollOfClumsiness: public Scroll{
        public:
            ScrollOfClumsiness();
            ~ScrollOfClumsiness();

            virtual void spell(Cell & target, Screen & screen) override;
        private:
            static const unsigned int DURABILITY_;
            static const unsigned int COST_;
            static const unsigned int CHANCE_OF_LOSS_;
    };
}
#endif