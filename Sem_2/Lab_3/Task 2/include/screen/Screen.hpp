#ifndef __SCREEN__
#define __SCREEN__

#include <vector>
#include <iostream>
#include <string>

#include "CharMatrix.hpp"
#include "ScreenElement.hpp"

namespace BattleRoyale{
    class Screen{
        public:
            Screen(unsigned int height, unsigned int width);
            ~Screen();

            virtual void draw();
            virtual void drawData(const CharMatrix & data);
            virtual void drawMessage(std::string message) = 0;

            void fix();
            void addElement(ScreenElement &);

            unsigned int getHeight() const;
            unsigned int getWidth() const;
        private:
            CharMatrix data_;

            std::vector<ScreenElement*> elements_;
    };
}

#endif