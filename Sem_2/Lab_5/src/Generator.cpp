#include <ctime>
#include <complex>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void generate(int n){
    ofstream out("input" + to_string(n) + ".txt");
    for(int i = 0; i < 100000; i++){
        if(rand()%2){
            out << '+' << complex<int>(rand(), rand()) << '\n';
        }else{
            out << "-\n";
        }
    }
}

int main(){
    srand(time(NULL));
    
    for(int i:{1, 2, 3})
        generate(i);
    
    return 0;
}