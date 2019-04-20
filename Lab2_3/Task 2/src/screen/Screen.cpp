#include "Screen.hpp"

using BattleRoyale::Screen;

Screen::Screen(unsigned int height, unsigned int weight):
    height_(height), weight_(weight), data_(height, weight){};

Screen::~Screen(){};



void Screen::addElement(ScreenElement & element){
    elements_.push_back(&element);
}

void Screen::update(){
    for(int i = 0; i < elements_.size(); ++i)
        elements_.at(i)->draw(data_);
}



void Screen::draw() const{
    std::cout << data_.toString();
}
