#include "shared_mutex.hpp"

shared_mutex::shared_mutex(){}

shared_mutex::~shared_mutex(){}



void shared_mutex::lock(){
    m_.lock();
    shared_unlock();
    while(threads_.size() > 0) 
        std::this_thread::sleep_for(std::chrono::microseconds(1));
}

void shared_mutex::shared_lock(){
    m_.lock();
    threadsMutex_.lock();
    threads_.insert(std::this_thread::get_id());
    threadsMutex_.unlock();
    m_.unlock();
}

void shared_mutex::unlock(){
    m_.unlock();
}

void shared_mutex::shared_unlock(){
    threadsMutex_.lock();
    if(threads_.find(std::this_thread::get_id()) != threads_.end())
        threads_.erase(std::this_thread::get_id());
    threadsMutex_.unlock();
}