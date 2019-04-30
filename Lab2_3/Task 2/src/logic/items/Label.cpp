#include "Label.hpp"

using BattleRoyale::Label;

Label::Label():
    Item("Label", 1, 0){
        stats_.droppable_ = false;
    }

Label::~Label(){};

void Label::use(Player & user, Map & map, Screen & screen){
    if (stats_.durability_ <= 0 || !user.isActive())
        throw user.getName() + " can't use " + name_ + " now!";
    CharMatrix data(screen.getHeight(), screen.getWidth());
    std::string command;
    data.fill("Enter new name:", 12, 32);
    screen.drawData(data);
    std::cin >> command;
    user.setName(command);
    stats_.durability_--;
}
