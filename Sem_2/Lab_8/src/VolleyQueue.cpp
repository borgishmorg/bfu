#include "VolleyQueue.hpp"

void VolleyQueue::push(Volley volley){
    if(volley.empty())
        return;

    std::unique_lock<std::mutex> lock(m_);
    volleys_.push(volley);
    notify();
}

Projectile VolleyQueue::getProjectile(int shipNumber){
    std::unique_lock<std::mutex> lock(m_);

    Projectile tmp = volleys_.front().getProjectile(shipNumber);

    if(volleys_.front().empty())
        volleys_.pop();
    
    if(!volleys_.front().empty())
        notify();
    return tmp;
}

bool VolleyQueue::haveProjectile(int shipNumber){
    std::unique_lock<std::mutex> lock(m_);
    if(volleys_.empty())
        return false;
    return volleys_.front().haveProjectile(shipNumber);
}



void VolleyQueue::notify(){
    if(!volleys_.empty())
        cv.notify_all();
}