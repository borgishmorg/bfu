#include "Screen.hpp"

using BattleRoyale::Screen;

Screen::Screen(unsigned int height, unsigned int weight):
    height_(height), weight_(weight), data_(height, weight){}

Screen::~Screen(){
    elements_.clear();
};



void Screen::addElement(ScreenElement & element){
    elements_.push_back(&element);
}
void Screen::draw(){
    for(ScreenElement * element: elements_){
        //element->update();
        element->draw(data_);
    }
    system("cls");
    std::cout << data_.toString();
}

void Screen::drawData(const CharMatrix & data){
    data_.clear();
    data_.fill(data);
    system("cls");
    std::cout << data_.toString();
}



unsigned int Screen::getHeight() const{
    return height_;
}

unsigned int Screen::getWeight() const{
    return weight_;
}
