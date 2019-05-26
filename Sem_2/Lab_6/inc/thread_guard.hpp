#ifndef __THREAD_GUARD__
#define __THREAD_GUARD__

#include <vector>
#include <thread>

class thread_guard{
    public:
        ~thread_guard(){ join(); }
        void join(){for(auto & p: v_) if( p.joinable()) p.join(); }
        void push_back(std::thread p){ v_.push_back(move(p)); }
    private:
        std::vector<std::thread> v_;
};

#endif