#include "shared_mutex.hpp"
#include "hierarchical_mutex.hpp"
#include "thread_guard.hpp"
#include "rand.hpp"
#include <mutex>
#include <chrono>
#include <thread>
#include <iostream>
#include <fstream>
#include <string>

#define time() chrono::steady_clock::now()

using namespace std;
using namespace chrono;

const unsigned int N = 1e3;
const unsigned int K = thread::hardware_concurrency() - 1;
const unsigned int MAX_TIME_MS = 10;
const unsigned int RATIO = 10;

shared_mutex m;
mutex io_mutex;

ofstream logger("log.txt");
steady_clock::time_point begin_t;

void log(string s, steady_clock::time_point time){
    lock_guard<mutex> lock(io_mutex);
    logger << duration_cast<milliseconds>(time-begin_t).count() 
           <<" ms; " << this_thread::get_id() << " id; " << s << "\n";
}
/*
###################################################################################
*/
void read(){
    m.shared_lock();
    int tmp = 1+rand()%MAX_TIME_MS;
    log("Start reading " + to_string(tmp), time());
    this_thread::sleep_for(milliseconds(tmp));
    log("Stop reading", time());
    m.shared_unlock();
}

void write(){
    m.lock();
    int tmp = 1 + rand()%MAX_TIME_MS;
    log("Start writing " + to_string(tmp), time());
    this_thread::sleep_for(milliseconds(tmp));
    log("Stop writing", time());
    m.unlock();
}

bool wait_flag = true;

void work(){
    while(wait_flag);
    for(int i = 0; i < N; i++)
        if(rand() % RATIO)
            read();
        else
            write(); 
}

void shared_mutex_test(){
    int count = 1;
    while (count--){
        srand(time().time_since_epoch().count());
        thread_guard guard;

        for(int i = 0; i < K; i++) guard.push_back(thread(work));
        
        begin_t = time();
        wait_flag = false;
        guard.join();
        auto end = time();
        
        cout << "Work time: " << duration_cast<milliseconds>(end-begin_t).count() << "ms." << endl;
    }
}
/*
###################################################################################
*/
void hierarchical_mutex_test(){
    try{
        hierarchical_mutex a(1000), b(500), c(0);
        a.lock();
        b.lock();
        c.lock();
        c.unlock();
        b.unlock();
        a.unlock();
        cout << "Success\n";
    }catch(char const* s){ cout << s << endl; }
    try{
        hierarchical_mutex a(1000), b(500);
        a.lock();
        b.lock();
        a.unlock();
        b.unlock();
        cout << "Success\n";
    }catch(char const* s){ cout << s << endl; }
    try{
        hierarchical_mutex a(1000), b(500);
        b.lock();
        a.lock();
        a.unlock();
        b.unlock();
        cout << "Success\n";
    }catch(char const* s){ cout << s << endl; }
}
/*
###################################################################################
*/
int main(){
    shared_mutex_test();
    hierarchical_mutex_test();
}
/*

N = 1000
K = 3
MAX_TIME_MS = 10
RATIO = 10

Shared mutex test:
    Work time: 7328ms.
    Work time: 7391ms.
    Work time: 7276ms.
    Work time: 7306ms.
    Work time: 7231ms.
Usual mutex test:
    Work time: 16784ms.
    Work time: 16566ms.
    Work time: 16851ms.
    Work time: 16584ms.
    Work time: 16589ms.
Single thread test:
    Work time: 5646ms.
    Work time: 5481ms.
    Work time: 5492ms.
    Work time: 5505ms.
    Work time: 5590ms.

Huerarchical mutex test:
    Success
    Y can't unlock this mutex
    Y can't lock this mutex

*/