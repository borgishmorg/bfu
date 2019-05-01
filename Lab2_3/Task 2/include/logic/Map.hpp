#ifndef __MAP__
#define __MAP__

#include <vector>
#include <memory>
#include <cstdlib>
#include <algorithm>

namespace BattleRoyale{
    class Map;
}

#include "Cell.hpp"
#include "Player.hpp"

namespace BattleRoyale{
    class Map{
        public:
            Map();
            ~Map();

            std::shared_ptr<Cell> at(unsigned int hPos, unsigned int wPos);
            std::shared_ptr<Cell> atRandomPos();

            std::vector<std::shared_ptr<Player> > getPlayersInRadius(Cell & cell, int radius);
        private:
            std::vector< std::vector< std::shared_ptr<Cell> > > cells_;

            static const unsigned int HEIGHT;
            static const unsigned int WIDTH;
    };
}
#endif