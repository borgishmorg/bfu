#ifndef __SCROLL_OF_WALL__
#define __SCROLL_OF_WALL__

#include "Scroll.hpp"

namespace BattleRoyale{
    class ScrollOfWall: public Scroll{
        public:
            ScrollOfWall();
            ~ScrollOfWall();

            virtual void spell(Cell & target, Screen & screen) override;
        private:
            static const unsigned int DURABILITY_;
            static const unsigned int COST_;
    };
}
#endif