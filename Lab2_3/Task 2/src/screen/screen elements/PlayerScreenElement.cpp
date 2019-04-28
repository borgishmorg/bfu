#include "PlayerScreenElement.hpp"
#include <iostream>

using BattleRoyale::PlayerScreenElement;

PlayerScreenElement::PlayerScreenElement(unsigned int hPos, unsigned int wPos):
    viewData_(VIEW_DATA_HEIGHT, VIEW_DATA_WIDTH), ScreenElement(hPos, wPos, HEIGHT, WIDTH){
        data_.fill(BACKGROUND_DATA);
    };

PlayerScreenElement::~PlayerScreenElement(){
    player_ = nullptr;
};



void PlayerScreenElement::focusAtPlayer(std::shared_ptr<Player> player){
    player_ = player;
    update();
}

void PlayerScreenElement::update(){
    viewData_.clear();
    viewData_.fill(player_->toString());
    data_.fill(viewData_, VIEW_DATA_HPOS, VIEW_DATA_WPOS);
}

const std::string PlayerScreenElement::BACKGROUND_DATA = std::string()+
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

const unsigned int PlayerScreenElement::HEIGHT = 12;
const unsigned int PlayerScreenElement::WIDTH = 56;
const unsigned int PlayerScreenElement::VIEW_DATA_HEIGHT = 8;
const unsigned int PlayerScreenElement::VIEW_DATA_WIDTH = 52;
const unsigned int PlayerScreenElement::VIEW_DATA_HPOS = 2;
const unsigned int PlayerScreenElement::VIEW_DATA_WPOS = 2;