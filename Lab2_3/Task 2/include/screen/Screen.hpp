#ifndef __SCREEN__
#define __SCREEN__

#include <vector>
#include <iostream>

#include "CharMatrix.hpp"
#include "ScreenElement.hpp"
#include "MapScreenElement.hpp"
#include "PlayerScreenElement.hpp"
#include "MessageScreenElement.hpp"
#include "Player.hpp"
#include "Cell.hpp"

namespace BattleRoyale{
    class Screen{
        public:
            Screen(Map & map);
            ~Screen();

            void focusAtPlayer(std::shared_ptr<Player>);
            void showMessage(std::string message);

            void update();
            
            void draw() const;
        private:
            MapScreenElement mapElement_;
            PlayerScreenElement playerElement_;
            MessageScreenElement messageElement_;

            unsigned int height_;
            unsigned int weight_;
            CharMatrix data_;

            static const unsigned int HEIGHT;
            static const unsigned int WEIGHT;
            static const unsigned int MAP_ELEMENT_HPOS;
            static const unsigned int MAP_ELEMENT_WPOS;
            static const unsigned int PLAYER_ELEMENT_HPOS;
            static const unsigned int PLAYER_ELEMENT_WPOS;
            static const unsigned int MESSAGE_ELEMENT_HPOS;
            static const unsigned int MESSAGE_ELEMENT_WPOS;

    };
}

#endif