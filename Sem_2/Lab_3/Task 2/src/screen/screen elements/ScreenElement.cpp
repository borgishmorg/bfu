#include "ScreenElement.hpp"

using BattleRoyale::ScreenElement;



ScreenElement::ScreenElement(unsigned int hPos, unsigned int wPos, unsigned int height, unsigned int width):
    hPos_(hPos), wPos_(wPos), height_(height), width_(width), data_(height, width){}

ScreenElement::~ScreenElement(){}



void ScreenElement::draw(CharMatrix & matrix){
    update();
    matrix.fill(data_, hPos_, wPos_);
}