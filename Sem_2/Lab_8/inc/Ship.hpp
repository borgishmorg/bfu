#ifndef __SHIP__
#define __SHIP__

#include "Projectile.hpp"
#include <string>

class Ship{
    public:
        Ship();

        void takeDamage(Projectile);

        std::string toString() const;
    private:
        int engineHP_;
        int weaponHP_;
        int barHP_;

        bool engine_debuff_;
        bool weapon_debuff_;
        bool bar_debuff_;

        static const int MAX_ENGINE_HP_;
        static const int MAX_WEAPON_HP_;
        static const int MAX_BAR_HP_;
};
#endif