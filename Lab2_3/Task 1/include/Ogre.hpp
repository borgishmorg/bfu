#ifndef __OGRE__
#define __OGRE__

#include "Hero.hpp"

namespace Arena{
    class Ogre: public Arena::Hero{
        public:
            Ogre();
            ~Ogre();

            virtual bool attack(Arena::Hero &, AttackType) override;
    };    
}

#endif