#ifndef __DATA_BASE__
#define __DATA_BASE__

#include "Cook.hpp"
#include "Dish.hpp"
#include "Guest.hpp"

#include <iostream>
#include <map>
#include <string>
#include <functional>

namespace DataBaseNS
{
    Comparator getComparator();
    Comparator getComparatorByCookName(std::string name);
    Comparator getComparatorByDishName(std::string name);
    Comparator getComparatorByDishType(std::string type);
    Comparator getComparatorByDishCountry(std::string country);
    Comparator getComparatorByRate(int rate);

    class DataBase{
        public:
            DataBase();
            ~DataBase();
            void addCook(std::string name);
            void addDish(std::string name, std::string type, std::string country);
            void addGuest(std::string name);
            void addReview(std::string guestName, std::string dishName, std::string cookName, int rate);

            double getStatistics(Comparator cmp) const;
        private:
            std::map<std::string, Cook> cooks;
            std::map<std::string, Dish> dishes;
            std::map<std::string, Guest> guests;
    };
} 
#endif