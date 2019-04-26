#include "MessageScreenElement.hpp"
#include <iostream>

using BattleRoyale::MessageScreenElement;
MessageScreenElement::MessageScreenElement(unsigned int hPos, unsigned int wPos):
    viewData_(VIEW_DATA_HEIGHT, VIEW_DATA_WEIGHT), ScreenElement(hPos, wPos, HEIGHT, WEIGHT){
        data_.fill(BACKGROUND_DATA);
    };

MessageScreenElement::~MessageScreenElement(){};

void MessageScreenElement::update(){
    viewData_.clear();
    // write message screen element realization here !!!
    data_.fill(viewData_, VIEW_DATA_HPOS, VIEW_DATA_WPOS);
}

const std::string MessageScreenElement::BACKGROUND_DATA = std::string()+
            " +----------------------------------------------------+ "+
            "++                                                    ++"+
            "|                                                      |"+
            "|                                                      |"+
            "|                                                      |"+
            "|                                                      |"+
            "|                                                      |"+
            "|                                                      |"+
            "|                                                      |"+
            "|                                                      |"+
            "++                                                    ++"+
            " +----------------------------------------------------+ ";

const unsigned int MessageScreenElement::HEIGHT = 12;
const unsigned int MessageScreenElement::WEIGHT = 56;
const unsigned int MessageScreenElement::VIEW_DATA_HEIGHT = 8;
const unsigned int MessageScreenElement::VIEW_DATA_WEIGHT = 52;
const unsigned int MessageScreenElement::VIEW_DATA_HPOS = 2;
const unsigned int MessageScreenElement::VIEW_DATA_WPOS = 2;