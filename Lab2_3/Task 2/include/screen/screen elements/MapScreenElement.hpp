#ifndef __MAP_SCREEN_ELEMENT__
#define __MAP_SCREEN_ELEMENT__

#include <memory>

#include "CharMatrix.hpp"
#include "ScreenElement.hpp"
#include "Player.hpp"
#include "Cell.hpp"
#include "Map.hpp"

namespace BattleRoyale{
    class MapScreenElement: public ScreenElement{
        public:
            MapScreenElement(std::shared_ptr<Map>, unsigned int hPos, unsigned int wPos);
            ~MapScreenElement();

            void focusAtPlayer(std::shared_ptr<Player>);

            virtual void update() override;
        private:
            CharMatrix viewData_;

            std::shared_ptr<Map> map_;
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