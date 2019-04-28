#include "Keyboard.hpp"

using BattleRoyale::Keyboard;

Keyboard::Keyboard():
    Item("Keyboard", 2){}

Keyboard::~Keyboard(){};

void Keyboard::use(){

}

const std::string Keyboard::toString() const{
    return toShortString();
}