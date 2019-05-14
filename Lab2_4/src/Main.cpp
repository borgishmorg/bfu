#include <iostream>
#include <fstream>
#include <thread>
#include <string>
#include <vector>
#include <chrono>
#include <mutex>

using namespace std;

mutex m;

class thread_guard{
    public:
        ~thread_guard(){
            join();
        }
        void save(thread && th){
            threads_.push_back(move(th));
        }
        void join(){
            for(auto & th: threads_)
                if(th.joinable())
                    th.join();    
        }
    private:
        vector<thread> threads_;
};

void input(int & n, long long * &  v1, long long * &  v2, string file = "vector.txt"){
    ifstream in(file);
    in >> n;
    v1 = new long long[n];
    v2 = new long long[n];
    for(int i = 0; i < n; i++)
        in >> v1[i];
    for(int i = 0; i < n; i++)
        in >> v2[i];
}

void scalarProduct(long long * v1, long long * v2, int n, long long & res){
    int cnt = 1; // just for speed test
    long long tres = 0;
    while (cnt--){
        tres = 0;
        for(int i = 0; i < n; i++)
            tres += v1[i] * v2[i];
    }
    res = tres;
    m.lock();
    cout <<this_thread::get_id() << "  " << res << endl;
    m.unlock();
}



int main(){
    
    int n;
    long long * v1;
    long long * v2;

    input(n, v1, v2);

    int threadCount = thread::hardware_concurrency() - 1;
    int l = n/(threadCount+1);
    long long finalRes = 0;
    long long res[threadCount+1];
    thread_guard guard;

    cout << "hardware_concurrency: " << thread::hardware_concurrency() << endl << endl;
    


    cout << "Multithread test:"<< endl;

    auto begin = std::chrono::steady_clock::now();

    for(int i = 0; i < threadCount; i++){
        guard.save(thread(scalarProduct, v1 + l*i, v2 + l*i, l, ref(res[i])));
    }
    scalarProduct( v1 + l*(threadCount), v2 + l*(threadCount), n-l*(threadCount), res[threadCount]);
    
    guard.join();
    
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    cout << "The time: " << elapsed_ms.count() << " ms\n";
    
    for(int i = 0; i <= threadCount; i++)
        finalRes += res[i];
    cout << finalRes << endl;



    cout << endl << "One thread test:"<< endl;
    begin = std::chrono::steady_clock::now();
    
    scalarProduct(v1, v2, n, finalRes);
    
    end = std::chrono::steady_clock::now();
    elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    cout << "The time: " << elapsed_ms.count() << " ms\n";
    
    cout << finalRes << endl;

    return 0;
}
/*
Speed test:

cnt = 1000

Multithread test:
4  248479325230752240
3  249579926681321254
1  250793181484630242
2  251215654664459437
The time: 1197 ms
1000068088061163173

One thread test:
1  1000068088061163173
The time: 2620 ms
1000068088061163173
------------------------------------------------------
cnt = 100000

Multithread test:
2  251215654664459437
1  250793181484630242
3  249579926681321254
4  248479325230752240
The time: 118022 ms
1000068088061163173

One thread test:
1  1000068088061163173
The time: 263691 ms
1000068088061163173
*/