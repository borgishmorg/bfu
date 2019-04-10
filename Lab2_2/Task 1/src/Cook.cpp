#include "Cook.hpp"
#include <string>

using DataBaseNS::Cook;

Cook::Cook(std::string name):
    name_(name){}

Cook::~Cook(){}

const std::string & Cook::getName() const{
    return name_;
}