#ifndef __HIERARCHICAL_MUTEX__
#define __HIERARCHICAL_MUTEX__

#include <mutex>

class hierarchical_mutex{
    public:
        hierarchical_mutex(int priority);
        ~hierarchical_mutex();

        void lock();
        void unlock();
    private:
        int priority_;
        int lastPriority_;
        static thread_local int thisThreadPriority_;
        std::mutex m_;
};
#endif