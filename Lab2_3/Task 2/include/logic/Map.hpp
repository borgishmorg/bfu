#ifndef __MAP__
#define __MAP__

#include <vector>
#include <memory>

#include "Cell.hpp"

namespace BattleRoyale{

    class Map{
        public:
            Map();
            ~Map();

            std::shared_ptr<Cell> at(unsigned int hPos, unsigned int wPos);
        private:
            std::vector< std::vector< std::shared_ptr<Cell> > > cells_;

            static const unsigned int HEIGHT;
            static const unsigned int WEIGHT;
    };

}

#endif