#ifndef __GAME_SCREEN__
#define __GAME_SCREEN__

#include <vector>
#include <iostream>

#include "CharMatrix.hpp"
#include "Screen.hpp"
#include "ScreenElement.hpp"
#include "MapScreenElement.hpp"
#include "PlayerScreenElement.hpp"
#include "MessageScreenElement.hpp"
#include "Player.hpp"

namespace BattleRoyale{
    class GameScreen: public Screen{
        public:
            GameScreen(Map & map);
            ~GameScreen();

            void focusAtPlayer(std::shared_ptr<Player>);
            
            virtual void drawMessage(std::string message);
        private:
            MapScreenElement mapElement_;
            PlayerScreenElement playerElement_;
            MessageScreenElement messageElement_;

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