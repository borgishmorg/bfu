#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int n = 1000000;
int l = -1000000;
int r = 1000000;

long long randLongLong(){
    return (((((rand()*(RAND_MAX+1ll) + rand())*(RAND_MAX+1ll) + rand()))*(RAND_MAX+1ll) + rand())*(RAND_MAX+1ll) + rand());
}

int main(){
    srand(1);
    ofstream out("vector.txt");
    out << n << endl;
    for(int i = 0; i < n; i++)
        out << randLongLong() % (r - l + 1) + l << " ";
    out << endl;
    for(int i = 0; i < n; i++)
        out << randLongLong() % (r - l + 1) + l << " ";
    out << endl;
    
    return 0;
}