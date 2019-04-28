#ifndef __MESSAGE_SCREEN_ELEMENT__
#define __MESSAGE_SCREEN_ELEMENT__

#include <string>

#include "CharMatrix.hpp"
#include "ScreenElement.hpp"

namespace BattleRoyale{
    class MessageScreenElement: public ScreenElement{
        public:
            MessageScreenElement(unsigned int hPos, unsigned int wPos);
            ~MessageScreenElement();

            void showMessage(std::string message);

            virtual void update() override;
        private:
            CharMatrix viewData_;
            
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