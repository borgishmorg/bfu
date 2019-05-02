#ifndef __AK47__
#define __AK47__

#include <cstdlib>

#include "Weapon.hpp"

namespace BattleRoyale{
    class AK47: public Weapon{
        public:
            AK47();
            ~AK47();

            virtual void attack(Player & user, Player & target, Screen & screen) override;
        private:
            static const std::string NAME_;
            static const int DURABILITY_;
            static const int COST_;
            static const int DAMAGE_;
            static const int DEATH_CHANCE_;
            static const int DISTANCE_;
    };
}
#endif