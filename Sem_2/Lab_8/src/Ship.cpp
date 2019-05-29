#include "Ship.hpp"

#define elif else if

Ship::Ship():
    engineHP_(MAX_ENGINE_HP_),
    weaponHP_(MAX_WEAPON_HP_),
    barHP_(MAX_BAR_HP_),
    engine_debuff_(false),
    weapon_debuff_(false),
    bar_debuff_(false){}



void Ship::takeDamage(Projectile proj){
    int delta = 0;
    int dmg = proj.damage_;
    ShipSystemType dist = proj.systemType_;
    ProjectileType type = proj.type_;

    if(engineHP_ <= 0) return;

    if(engine_debuff_){
        engine_debuff_ = false;
        dmg *= 2;
    }
    if(weapon_debuff_)
        weapon_debuff_ = false;
    else
        delta = std::min(dmg, weaponHP_);
    
    if(bar_debuff_){
        bar_debuff_ = false;
        delta /= 2;
        if(dist == ShipSystemType::ENGINE)
            dmg *= 2;
    }

    dmg -= delta;


    if(type == ProjectileType::NUKE){
        if(dist == ShipSystemType::ENGINE)
            engineHP_ = std::max(0, engineHP_ - dmg);
        elif(dist == ShipSystemType::WEAPON)
            weaponHP_ = std::max(0, weaponHP_ - dmg);
        elif(dist == ShipSystemType::BAR)
            barHP_ = std::max(0, barHP_ - dmg);
    }elif(type == ProjectileType::EMP){
        if(dmg > 0)     
            if(dist == ShipSystemType::ENGINE)
                engine_debuff_ = true;
            elif(dist == ShipSystemType::WEAPON)
                weapon_debuff_ = true;
            elif(dist == ShipSystemType::BAR)
                bar_debuff_ = true;
    }

    if(engineHP_ == 0)
        engine_debuff_ = true;
    if(weaponHP_ == 0)
        weapon_debuff_ = true;
    if(barHP_ == 0)
        bar_debuff_ = true;
}

std::string Ship::toString() const{
    if(!engineHP_)
        return "(DESTROYED)";
    
    return "(ENG:" + std::to_string(engineHP_) + "/" + std::to_string(MAX_ENGINE_HP_) +
           " WEA:" + std::to_string(weaponHP_) + "/" + std::to_string(MAX_WEAPON_HP_) +
           " BAR:" + std::to_string(barHP_) + "/" + std::to_string(MAX_BAR_HP_) + ") " +
           "Debuffs: " +
           std::to_string(engine_debuff_) + " " +
           std::to_string(weapon_debuff_) + " " +
           std::to_string(bar_debuff_) + " ";
}



const int Ship::MAX_ENGINE_HP_ = 1000;
const int Ship::MAX_WEAPON_HP_ = 300;
const int Ship::MAX_BAR_HP_ = 100;