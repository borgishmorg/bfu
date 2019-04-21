#ifndef __SCREEN__
#define __SCREEN__

#include <vector>
#include <iostream>

#include "CharMatrix.hpp"
#include "ScreenElement.hpp"
#include "MapScreenElement.hpp"
#include "Player.hpp"
#include "Cell.hpp"

namespace BattleRoyale{
    class Screen{
        public:
            Screen(std::shared_ptr<Map> map);
            ~Screen();

            void focusAtPlayer(std::shared_ptr<Player>);
            void lookAtCell(std::shared_ptr<Cell>);

            void update();
            
            void draw() const;
        private:
            MapScreenElement mapElement_;

            unsigned int height_;
            unsigned int weight_;
            CharMatrix data_;

            std::shared_ptr<Player> player_;
            std::shared_ptr<Cell> cell_;

            static const unsigned int HEIGHT;
            static const unsigned int WEIGHT;
            static const unsigned int MAP_ELEMENT_HPOS;
            static const unsigned int MAP_ELEMENT_WPOS;

    };
}

#endif