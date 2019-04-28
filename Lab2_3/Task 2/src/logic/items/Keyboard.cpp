#include "Keyboard.hpp"

using BattleRoyale::Keyboard;

Keyboard::Keyboard():
    Item("Keyboard", 2, 1){}

Keyboard::~Keyboard(){};

void Keyboard::use(Player & user, Map & map, Screen & screen){
    if (stats_.durability_ <= 0 || !user.isActive() || user.getStats().AP_ < stats_.cost_)
        throw user.getName() + " can't use " + name_ + " now!";
    user.addAP(-stats_.cost_);
    stats_.durability_--;

    CharMatrix data(screen.getHeight(), screen.getWeight());
    data.fill("Enter some command:", 12, 30);

    screen.drawData(data);
    std::string command;
    std::cin >> command;
    if(command == "name"){
        data.clear();
        data.fill("Enter new name:", 12, 30);
        screen.drawData(data);
        std::cin >> command;
        user.setName(command);
    }
}

const std::string Keyboard::toString() const{
    return toShortString();
}