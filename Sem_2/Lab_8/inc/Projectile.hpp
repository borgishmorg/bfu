#ifndef __PROJECTILE__
#define __PROJECTILE__

enum class ShipSystemType{NO_TYPE = 0, ENGINE = 1, WEAPON = 2, BAR = 3};
enum class ProjectileType{NO_TYPE = 0, NUKE = 1, EMP = 2};

struct Projectile{
    int            damage_;
    int            shipNumber_;
    ShipSystemType systemType_;
    ProjectileType type_;

    Projectile(
        int            damage     = 0, 
        int            shipNumber = 0, 
        ShipSystemType systemType = ShipSystemType::NO_TYPE, 
        ProjectileType type       = ProjectileType::NO_TYPE
        ):
        damage_(damage),
        shipNumber_(shipNumber), 
        systemType_(systemType),
        type_(type)
        {}
};
#endif