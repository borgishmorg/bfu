#ifndef __SHARED_MUTEX__
#define __SHARED_MUTEX__

#include <mutex>
#include <chrono>
#include <thread>
#include <set>

class shared_mutex{
    public:
        shared_mutex();
        ~shared_mutex();

        void lock();
        void shared_lock();
        void unlock();
        void shared_unlock();
    private:
        std::set<std::thread::id> threads_;
        std::mutex m_, threadsMutex_;
};
#endif