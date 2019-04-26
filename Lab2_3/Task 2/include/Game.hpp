#ifndef __GAME__
#define __GAME__

#include <vector>
#include <memory>
#include <iostream>
#include <string>

#include "BattleRoyale.hpp"

namespace BattleRoyale{
    class Game{
        public:
            Game();
            ~Game();

            void play();            
        private:
            Map map_;
            Screen screen_;
            
            std::vector<std::shared_ptr<Player> > players_;
    };
}

#endif