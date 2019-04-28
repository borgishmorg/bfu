#include "MessageScreenElement.hpp"
#include <iostream>

using BattleRoyale::MessageScreenElement;
MessageScreenElement::MessageScreenElement(unsigned int hPos, unsigned int wPos):
    viewData_(VIEW_DATA_HEIGHT, VIEW_DATA_WIDTH), ScreenElement(hPos, wPos, HEIGHT, WIDTH){
        data_.fill(BACKGROUND_DATA);
    };

MessageScreenElement::~MessageScreenElement(){};


void MessageScreenElement::showMessage(std::string message){
    viewData_.clear();
    viewData_.fill(message);
}


void MessageScreenElement::update(){
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
const unsigned int MessageScreenElement::WIDTH = 56;
const unsigned int MessageScreenElement::VIEW_DATA_HEIGHT = 8;
const unsigned int MessageScreenElement::VIEW_DATA_WIDTH = 52;
const unsigned int MessageScreenElement::VIEW_DATA_HPOS = 2;
const unsigned int MessageScreenElement::VIEW_DATA_WPOS = 2;