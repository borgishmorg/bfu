#include "Keyboard.hpp"

using BattleRoyale::Keyboard;

Keyboard::Keyboard():
    Item("Keyboard", 2){}

Keyboard::~Keyboard(){};

void Keyboard::use(Cell & destination){

}

const std::string Keyboard::toString() const{
    return name_ + "(" + std::to_string(durability_) + ")";
}