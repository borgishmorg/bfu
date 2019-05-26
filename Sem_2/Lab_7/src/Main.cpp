#include <iostream>
#include <fstream>
#include <future>
#include <list>
#include <algorithm>
#include <chrono>
#include <cmath>

#define now() (chrono::steady_clock::now())
#define to_milliseconds(A) (chrono::duration_cast<chrono::milliseconds>(A).count())

using namespace std;

list<int> input(){
    ifstream in("input.txt");
    list<int> res = list<int>();
    int n, tmp;
    in >> n;
    while(n--){
        in >> tmp;
        res.push_back(tmp);  
    }
    return move(res);
}

mutex mut;
int cnt = 1;
int max_d = log2(thread::hardware_concurrency());

list<int> fast_sort(list<int> a, int d = 0){
    if(a.empty()) return a;

    int m = a.front();
    auto ml_it = partition(a.begin(), a.end(), [m](int a){return a < m;});
    auto mr_it = partition(ml_it, a.end(), [m](int a){return a <= m;});

    list<int> l, mid;

    l.splice(l.end(), a, a.begin(), ml_it);
    mid.splice(mid.end(), a, ml_it, mr_it);

    
    launch type = launch::deferred;
    
    if(d < max_d)
        type = launch::async; 

    future<list<int>> ll = async(type, fast_sort, move(l), d + 1);

    a = fast_sort(move(a), d + 1);
    a.splice(a.begin(), move(mid));
    a.splice(a.begin(), ll.get());

    return move(a);
}

int main(){
    int cnt = 5;
    list<int> a;
    ofstream out("output.txt");
    chrono::steady_clock::time_point t1, t2;

    cout << "Multithreading test\n";
    for(int i = 0; i < cnt; i++){
        a = move(input());
        
        t1 = now();
        a = fast_sort(move(a));
        t2 = now();
        
        cout << "\tTime: " << to_milliseconds(t2-t1) << "ms.\n"; 
        cout.flush();
    }
    
    max_d = 0;
    cout << "Single thread test\n";
    for(int i = 0; i < cnt; i++){
        a = move(input());
        
        t1 = now();
        a = fast_sort(move(a));
        t2 = now();
        
        cout << "\tTime: " << to_milliseconds(t2-t1) << "ms.\n";
        cout.flush();
    }

    for(int i: a) out << i << " ";

    return 0;
}
/*

Multithreading test
    Time: 5599ms.
    Time: 5607ms.
    Time: 5622ms.
    Time: 5597ms.
    Time: 5592ms.
Single thread test
    Time: 6325ms.
    Time: 6328ms.
    Time: 6370ms.
    Time: 6290ms.
    Time: 6296ms.

*/