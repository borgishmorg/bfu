#ifndef __GAME__
#define __GAME__

#include <vector>
#include <memory>
#include <set>
#include <iostream>
#include <cstdlib>
#include <string>

#include "BattleRoyale.hpp"

namespace BattleRoyale{
    class Game{
        public:
            Game(const unsigned int NUMBER_OF_PLAYERS);
            ~Game();

            void play();            
        private:
            void move();
            void turn();
            void look();
            void take();
            void drop();
            void heal();
            void use();
            void upgrade();
            void suicide();
            void scoreboard();
            void end();

            void playersQueueInit();

            const unsigned int NUMBER_OF_PLAYERS_;
            bool gameContinue;
            Map map_;
            GameScreen screen_;
            std::shared_ptr<Player> player_;
            std::vector<std::shared_ptr<Player> > players_;
            std::multiset<std::shared_ptr<Player>, bool (*)(std::shared_ptr<Player>, std::shared_ptr<Player>) > playersQueue_;
    };
}

#endif