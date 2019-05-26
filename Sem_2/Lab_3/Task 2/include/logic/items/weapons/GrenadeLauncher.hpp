#ifndef __GRENADE_LAUNCHER__
#define __GRENADE_LAUNCHER__

#include <cstdlib>

#include "Weapon.hpp"

namespace BattleRoyale{
    class GrenadeLauncher: public Weapon{
        public:
            GrenadeLauncher();
            ~GrenadeLauncher();

            virtual void attack(Player & user, Player & target, Screen & screen) override;
        private:
            int backfireChance_;

            static const std::string NAME_;
            static const int DURABILITY_;
            static const int COST_;
            static const int DAMAGE_;
            static const int DEATH_CHANCE_;
            static const int DISTANCE_;
            static const int BACKFIRE_CHANCE_;
    };
}
#endif