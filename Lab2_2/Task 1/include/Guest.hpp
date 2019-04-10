#ifndef __GUEST__
#define __GUEST__

#include "Dish.hpp"
#include "Cook.hpp"

#include <vector>
#include <string>
#include <functional>

namespace DataBaseNS
{
    struct Review
    {
        const Dish & dish;
        const Cook & cook;
        const int rate;
        Review(const Dish & dish_, const Cook & cook_, const int rate_):
            dish(dish_), cook(cook_), rate(rate_){}
        Review(const Cook & cook_, const Dish & dish_, const int rate_):
            dish(dish_), cook(cook_), rate(rate_){}
    };
    
    typedef std::function<bool(const Review &)> Comparator;

    class Guest
    {
    public:  
        Guest(std::string);
        ~Guest();
        void addReview(Review);
        double getRate(Comparator) const;
        double getWeight() const;
    private:
        std::string name_;
        double weight_;
        std::vector<Review> reviews_;

        void updateWeight();
    };
} 
#endif