#ifndef __GAME__
#define __GAME__

#include "BattleRoyale.hpp"

namespace BattleRoyale{
    class Game{
        public:
            Game();
            ~Game();

            void play();            
        private:
            const unsigned int SCREEN_HEIGHT = 24;
            const unsigned int SCREEN_WEIGHT = 80;

            Screen screen;
            MapScreenElement mapElement;
    };
}

#endif