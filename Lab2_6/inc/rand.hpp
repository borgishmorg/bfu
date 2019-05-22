#ifndef __RAND__
#define __RAND__

#include <random>

std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> dist(0,INT_MAX);

int rand(){
    int rnd = dist(rng);
    return rnd;
}
#endif