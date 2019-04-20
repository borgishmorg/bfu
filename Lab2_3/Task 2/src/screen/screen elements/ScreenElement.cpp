#include "ScreenElement.hpp"

using BattleRoyale::ScreenElement;

ScreenElement::ScreenElement(unsigned int hPos, unsigned int wPos, unsigned int height, unsigned int weight):
    hPos_(hPos), wPos_(wPos), height_(height), weight_(weight), data_(height, weight){}

ScreenElement::~ScreenElement(){}

void ScreenElement::draw(CharMatrix & matrix) const{
    matrix.fill(data_, hPos_, wPos_);
}