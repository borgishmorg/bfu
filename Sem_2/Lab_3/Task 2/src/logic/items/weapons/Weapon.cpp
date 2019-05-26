#include "Weapon.hpp"

using BattleRoyale::Weapon;

Weapon::WeaponStats::WeaponStats(int damage, int deathChance, int distance):
    damage_(damage), deathChance_(deathChance), distance_(distance){};

Weapon::WeaponStats::~WeaponStats(){}



Weapon::Weapon(std::string name, unsigned int durability, unsigned int cost, int damage, int deathChance, int distance):
    Item(name, durability, cost), weaponStats_(damage, deathChance, distance){}

Weapon::~Weapon(){};



void Weapon::use(Player & user, Map & map, Screen & screen){
    if (stats_.durability_ <= 0 || !user.isActive() || user.getStats().AP_ < stats_.cost_)
        throw user.getName() + " can't use " + name_ + " now!";
    
    int n;
    CharMatrix data(screen.getHeight(), screen.getWidth());
    std::vector<std::shared_ptr<Player> > targets = map.getPlayersInRadius(*user.getPos(), weaponStats_.distance_);

    if(targets.empty())
        throw "There is no players in action radius of " + name_; 

    data.fill("Choose target:", 8, 33);
    for(int i = 0; i < targets.size(); i++)
        data.fill(std::to_string(i+1) + ": " + targets.at(i)->toShortString() ,10 + i, 30);
    screen.drawData(data);

    std::cin >> n;

    if(n <= 0 || n > targets.size())
        throw "There is no target with index " + std::to_string(n);
    
    attack(user, *targets.at(n-1), screen);

    if (targets.at(n-1)->getStats().HP_ <= 0 
        && rand()%100 < weaponStats_.deathChance_){
        targets.at(n-1)->die();
        user.addUpgradePoints(1);
        user.addScore(10);
        screen.drawMessage(user.getName() + " kill " + targets.at(n-1)->getName() + " with " + name_);
    }

    user.takeFatigue(stats_.cost_);
    stats_.durability_--;
}

void Weapon::attack(Player & user, Player & target, Screen & screen){
    target.takeDamage(weaponStats_.damage_);
    screen.drawMessage(target.getName() + " takes " + std::to_string(weaponStats_.damage_) + " damage with " + name_);
    system("pause");
}