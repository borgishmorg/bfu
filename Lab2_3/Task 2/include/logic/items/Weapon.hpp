#ifndef __WEAPON__
#define __WEAPON__

#include <cstdlib>

#include "Item.hpp"

namespace BattleRoyale{
    class Weapon: public Item{
        public:
            struct WeaponStats{
                int damage_;
                int deathChance_;
                int distance_;

                WeaponStats(int damage, int deathChance, int distance);
                ~WeaponStats();
            };
            
            Weapon(std::string name, unsigned int durability, unsigned int cost, int damage, int deathChance, int distance);
            ~Weapon();

            virtual void use(Player & user, Map & map, Screen & screen) override;
            virtual void attack(Player & target, Screen & screen);
            virtual void backfire(Player & user, Screen & screen);
        private:
            WeaponStats weaponStats_;
    };
}

#endif