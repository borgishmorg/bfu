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

    base.addReview("Pupa", "Chocolate cake", "Maxim", 2);
    base.addReview("Pupa", "Krabby Patty", "SpongeBob", 5);
    base.addReview("Lupa", "Krabby Patty", "SpongeBob", 5);
    base.addReview("Lupa", "Borscht", "Mimax", 3);

    cout << base.getStatistics(getComparator()) << std::endl
         << base.getStatistics(getComparatorByCookName("SpongeBob")) << std::endl;

    return 0;
}