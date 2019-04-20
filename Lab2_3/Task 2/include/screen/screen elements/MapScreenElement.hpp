#ifndef __MAP_SCREEN_ELEMENT__
#define __MAP_SCREEN_ELEMENT__

#include "ScreenElement.hpp"

namespace BattleRoyale{
    class MapScreenElement: public ScreenElement{
        public:
            MapScreenElement(unsigned int hPos, unsigned int wPos);
            ~MapScreenElement();

            virtual void update() override;
        protected:
            
    };
}

#endif