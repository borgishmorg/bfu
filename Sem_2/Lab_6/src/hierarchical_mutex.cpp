#include "hierarchical_mutex.hpp"

hierarchical_mutex::hierarchical_mutex(int priority):
    priority_(priority){}

hierarchical_mutex::~hierarchical_mutex(){}



void hierarchical_mutex::lock(){
    if(priority_ > thisThreadPriority_)
        throw "Y can't lock this mutex";
    m_.lock();
    lastPriority_ = thisThreadPriority_;
    thisThreadPriority_ = priority_;
}

void hierarchical_mutex::unlock(){
    if(thisThreadPriority_ != priority_)
        throw "Y can't unlock this mutex";
    thisThreadPriority_ = lastPriority_;
    m_.unlock();
}

thread_local int hierarchical_mutex::thisThreadPriority_ = INT_MAX;