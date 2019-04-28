#ifndef __SCREEN__
#define __SCREEN__

#include <vector>
#include <iostream>

#include "CharMatrix.hpp"
#include "ScreenElement.hpp"

namespace BattleRoyale{
    class Screen{
        public:
            Screen(unsigned int height, unsigned int width);
            ~Screen();

            void addElement(ScreenElement &);

            virtual void draw();
            virtual void drawData(const CharMatrix & data);

            unsigned int getHeight() const;
            unsigned int getWidth() const;
        private:
            std::vector<ScreenElement*> elements_;

            unsigned int height_;
            unsigned int width_;
            CharMatrix data_;
    };
}

#endif