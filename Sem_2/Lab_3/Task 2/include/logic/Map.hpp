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
            Map(int height, int width);
            ~Map();

            void moveWalls();

            std::shared_ptr<Cell> at(unsigned int hPos, unsigned int wPos);
            std::shared_ptr<Cell> at(Player & player, char w, int h);
            std::shared_ptr<Cell> atRandomPos();
            
            std::vector<std::shared_ptr<Player> > getPlayersInRadius(Cell & cell, int radius);
        private:
            std::vector< std::vector< std::shared_ptr<Cell> > > cells_;

            int upWall_;
            int downWall_;
            int leftWall_;
            int rightWall_;

            const int HEIGHT_;
            const int WIDTH_;
    };
}
#endif