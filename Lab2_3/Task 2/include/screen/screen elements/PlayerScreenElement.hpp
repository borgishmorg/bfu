#ifndef __PLAYER_SCREEN_ELEMENT__
#define __PLAYER_SCREEN_ELEMENT__

#include <memory>

#include "CharMatrix.hpp"
#include "ScreenElement.hpp"
#include "Player.hpp"
#include "Cell.hpp"

namespace BattleRoyale{
    class PlayerScreenElement: public ScreenElement{
        public:
            PlayerScreenElement(unsigned int hPos, unsigned int wPos);
            ~PlayerScreenElement();

            void focusAtPlayer(std::shared_ptr<Player>);

            virtual void update() override;
        private:
            CharMatrix viewData_;

            std::shared_ptr<Player> player_;
            
            static const std::string BACKGROUND_DATA;
            static const unsigned int HEIGHT;
            static const unsigned int WEIGHT;
            static const unsigned int VIEW_DATA_HEIGHT;
            static const unsigned int VIEW_DATA_WEIGHT;
            static const unsigned int VIEW_DATA_HPOS;
            static const unsigned int VIEW_DATA_WPOS;
    };
}

#endif