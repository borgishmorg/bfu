#include <thread>
#include <mutex>
#include <stack>
#include <complex>
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

using namespace std;

class thread_guard{
    public:
        ~thread_guard(){
            for(auto & th: ths)
                if(th.joinable())
                    th.join();
        }

        void guard(thread && th){
            ths.push_back(move(th));
        }
    private:
        vector<thread> ths;
};

template<typename T>
class safe_stack{
    public:
        ~safe_stack(){cerr << s_.size() << " " << in_-out_;};
        shared_ptr<T> pop_top();
        void push(T);
    private:
        int in_ = 0, out_ = 0;
        mutex m_;
        stack<T> s_;
};

template<typename T>
shared_ptr<T> safe_stack<T>::pop_top(){
    lock_guard<mutex> lock(m_);
    if(s_.empty())
        return shared_ptr<T>();
    else{
        out_++;
        shared_ptr<T> res = make_shared<T>(s_.top());
        s_.pop();
        return res;
    }
}

template<typename T>
void safe_stack<T>::push(T obj){
    lock_guard<mutex> lock(m_);
    in_++;
    s_.push(obj);
}

void work(int n, safe_stack<complex<int>> & st){
    ifstream in("input" + to_string(n) + ".txt");
    ofstream out("log" + to_string(n) + ".txt");
    char c;
    complex<int> tmp;
    while(in >> c){
        switch(c){
            case '+':
                in >> tmp;
                st.push(tmp);
                out << n << " push " << tmp << "\n";
            break;
            case '-':
                shared_ptr<complex<int>> tmp_ptr = st.pop_top();
                if(tmp_ptr.use_count() == 0)
                    out << n << " pop NULL\n";
                else
                    out << n << " pop " << *tmp_ptr << "\n";
            break;
        }
    }
}

int main(){
    safe_stack<complex<int>> st;
    thread_guard guard;

    for(int i = 1; i <= 3; i++)
        guard.guard(thread(work, i, ref(st)));

    return 0;
}