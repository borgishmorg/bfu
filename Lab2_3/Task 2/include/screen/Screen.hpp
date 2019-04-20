#ifndef __SCREEN__
#define __SCREEN__

#include <vector>
#include <iostream>

#include "CharMatrix.hpp"
#include "ScreenElement.hpp"

namespace BattleRoyale{
    class Screen{
        public:
            Screen(unsigned int height, unsigned int weight);
            ~Screen();

            void addElement(ScreenElement&);
            void update();
            
            void draw() const;
        private:
            unsigned int height_;
            unsigned int weight_;
            CharMatrix data_;
            std::vector<ScreenElement*> elements_;
    };
}

#endif