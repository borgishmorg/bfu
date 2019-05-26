#include "Dish.hpp"
#include <string>

using DataBaseNS::Dish;

Dish::Dish(std::string name, std::string type, std::string country):
    name_(name), type_(type), country_(country){}

Dish::~Dish(){}

const std::string & Dish::getName() const{
    return name_;
}

const std::string & Dish::getType() const{
    return type_;
}

const std::string & Dish::getCountry() const{
    return country_;
}