#include "Volley.hpp"

Projectile Volley::getProjectile(int shipNumber){
    Projectile tmp;
    
    for(auto it = begin(); it != end(); it++)
        if(it->shipNumber_ == shipNumber){
            tmp = *it;
            erase(it);
            break;
        }
    
    return tmp;
}

bool Volley::haveProjectile(int shipNumber){
    for(auto & p: *this)
        if(p.shipNumber_ == shipNumber)
            return true;
    return false;
}