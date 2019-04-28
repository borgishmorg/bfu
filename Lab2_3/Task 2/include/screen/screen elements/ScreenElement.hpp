#ifndef __SCREEN_ELEMENT__
#define __SCREEN_ELEMENT__

namespace BattleRoyale{
    class ScreenElement;
}

#include "CharMatrix.hpp"

namespace BattleRoyale{
    class ScreenElement{
        public:
            ScreenElement(unsigned int hPos, unsigned int wPos, unsigned int height, unsigned int weight);
            ~ScreenElement();

            virtual void update() = 0;
            virtual void draw(CharMatrix &);
        protected:
            unsigned int hPos_;
            unsigned int wPos_;
            unsigned int height_;
            unsigned int weight_;
            CharMatrix data_;
    };
}

#endif