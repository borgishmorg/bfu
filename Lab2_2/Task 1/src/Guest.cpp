#include "Guest.hpp"
#include <string>

using DataBaseNS::Comparator;
using DataBaseNS::Review;
using DataBaseNS::Guest;

Guest::Guest(std::string name):
    name_(name),weight_(0){}

Guest::~Guest(){}

/*
================= PUBLIC METHODS ========================
*/

void Guest::addReview(Review review){
    reviews_.push_back(review);
    updateWeight();
}

double Guest::getRate(Comparator cmp) const{
    double rate = 0;
    int count = 0;
    for(const Review & review : reviews_){
        if(cmp(review)){
            rate = (rate*count + review.rate)/(count + 1);
            ++count;
        }
    }
    return rate;
}

double Guest::getWeight() const{
    return weight_;
}

/*
================= PPIVATE METHODS ==========================
*/

void Guest::updateWeight(){
    if(reviews_.size() < 2){
        weight_ = 0;
        return;
    }
    int count = 0;
    for(const Review & a: reviews_)
        for (const Review & b : reviews_)
            if(a.rate != b.rate)
                ++count;
     weight_ = (count*1.)/(reviews_.size()*(reviews_.size()-1));   
}

