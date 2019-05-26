#include <iostream>
#include <vector>
#include <string>
#include "DataBase.hpp"

using namespace std;
using namespace DataBaseNS;

int main()
{
    DataBase base;
    base.addGuest("Pupa");
    base.addGuest("Lupa");

    base.addCook("Maxim");
    base.addCook("Mimax");
    base.addCook("SpongeBob");

    base.addDish("Chocolate cake", "Dessert", "Italy");
    base.addDish("Borscht", "Hot dishes", "Russia");
    base.addDish("Krabby Patty", "Snacks", "USA");
    base.addDish("Lasagna", "Hot dishes", "Italy");
    base.addDish("Okroshka", "Cold dishes", "Russia");
    base.addDish("Panini", "Shacks", "Italy");
    base.addDish("Charlotte", "Dessert", "Germany");

    base.addReview("Pupa", "Chocolate cake", "Maxim", 2);
    base.addReview("Pupa", "Krabby Patty", "SpongeBob", 5);
    base.addReview("Pupa", "Lasagna", "Maxim", 5);
    base.addReview("Pupa", "Okroshka", "Mimax", 3);
    base.addReview("Pupa", "Charlotte", "Maxim", 4);
    base.addReview("Lupa", "Krabby Patty", "SpongeBob", 5);
    base.addReview("Lupa", "Borscht", "Mimax", 3);
    base.addReview("Lupa", "Panini", "Maxim", 5);
    base.addReview("Lupa", "Lasagna", "Maxim", 5);
    base.addReview("Lupa", "Okroshka", "Mimax", 2);

    cout << base.getStatistics(getComparator()) << std::endl
         << base.getStatistics(getComparatorByCookName("SpongeBob")) << std::endl
         << base.getStatistics(getComparatorByDishName("Panini")) << std::endl
         << base.getStatistics(getComparatorByDishType("Dessert")) << std::endl
         << base.getStatistics(getComparatorByDishCountry("Russia")) << std::endl
         << base.getStatistics(getComparatorByRate(0b110001)) << std::endl;

    return 0;
}
/*
    Output:
        3.8875
        5
        5
        3
        2.78125
        4.8125
*/