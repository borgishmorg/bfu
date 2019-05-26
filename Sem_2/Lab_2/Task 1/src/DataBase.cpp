#include "DataBase.hpp"

using DataBaseNS::DataBase;
using DataBaseNS::Comparator;
using DataBaseNS::Review;

Comparator DataBaseNS::getComparator(){
    return [](const Review & review){
        return true;
    };
}

Comparator DataBaseNS::getComparatorByCookName(std::string name){
    return [name](const Review & review){
        return review.cook.getName() == name;
    };
}

Comparator DataBaseNS::getComparatorByDishName(std::string name){
    return [name](const Review & review){
        return review.dish.getName() == name;
    };
}
Comparator DataBaseNS::getComparatorByDishType(std::string type){
    return [type](const Review & review){
        return review.dish.getType() == type;
    };
}

Comparator DataBaseNS::getComparatorByDishCountry(std::string country){
    return [country](const Review & review){
        return review.dish.getCountry() == country;
    };
}

Comparator DataBaseNS::getComparatorByRate(int rate){
    return [rate](const Review & review){
        return review.rate == 5 && (rate & 1<<5) ||
               review.rate == 4 && (rate & 1<<4) ||
               review.rate == 3 && (rate & 1<<3) ||
               review.rate == 2 && (rate & 1<<2) ||
               review.rate == 1 && (rate & 1<<1) ||
               review.rate == 0 && (rate & 1<<0);
    };
}
/*
=================== DataBase methods =======================
*/

DataBase::DataBase(){}

DataBase::~DataBase(){}

void DataBase::addCook(std::string name){
    cooks.insert({name, Cook(name)});
}

void DataBase::addDish(std::string name, std::string type, std::string country){
    dishes.insert({name, Dish(name, type, country)});
}

void DataBase::addGuest(std::string name){
    guests.insert({name, Guest(name)});
}

void DataBase::addReview(std::string guestName, std::string dishName, std::string cookName, int rate){
    try{
        guests.at(guestName).addReview({dishes.at(dishName), cooks.at(cookName), rate});
    }catch(...){}
}


double DataBase::getStatistics(Comparator cmp)const{
    double numerator = 0, 
           denominator = 0;
    for(const auto & guest: guests){
        if(guest.second.getWeight() > 0 && guest.second.getRate(cmp) > 0){
            numerator += guest.second.getWeight() * guest.second.getRate(cmp);
            denominator += guest.second.getWeight();
        }
    }
    if(denominator > 0)
        return numerator/denominator;
    return 0;
}
