#ifndef __VOLLEY_QUEUE__
#define __VOLLEY_QUEUE__

#include "Volley.hpp"
#include "Projectile.hpp"

#include <mutex>
#include <condition_variable>
#include <queue>

class VolleyQueue{
    public:
        void push(Volley);
        Projectile getProjectile(int shipNumber);
        bool haveProjectile(int shipNumber);

        std::condition_variable cv;
    private:
        void notify();

        std::queue<Volley> volleys_;
        std::mutex m_;
};
#endif