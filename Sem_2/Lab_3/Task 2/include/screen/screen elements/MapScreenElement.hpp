#ifndef __MAP_SCREEN_ELEMENT__
#define __MAP_SCREEN_ELEMENT__

#include <memory>

#include "CharMatrix.hpp"
#include "ScreenElement.hpp"
#include "Player.hpp"
#include "Map.hpp"

namespace BattleRoyale{
    class MapScreenElement: public ScreenElement{
        public:
            MapScreenElement(Map & map, unsigned int hPos, unsigned int wPos);
            ~MapScreenElement();

            void focusAtPlayer(std::shared_ptr<Player>);
            void focusAtPlayer(Player &);
            
            virtual void update() override;
        private:
            CharMatrix viewData_;

            Map & map_;
            std::shared_ptr<Cell> playerPos_;
            
            static const std::string BACKGROUND_DATA;
            static const unsigned int HEIGHT;
            static const unsigned int WIDTH;
            static const unsigned int VIEW_DATA_HEIGHT;
            static const unsigned int VIEW_DATA_WIDTH;
            static const unsigned int VIEW_DATA_HPOS;
            static const unsigned int VIEW_DATA_WPOS;
    };
}

#endif