#ifndef __VOLLEY__
#define __VOLLEY__

#include "Projectile.hpp"
#include <vector>

class Volley: public std::vector<Projectile>{
    public:
        Projectile getProjectile(int shipNumber);
        bool haveProjectile(int shipNumber);
    private:
};
#endif