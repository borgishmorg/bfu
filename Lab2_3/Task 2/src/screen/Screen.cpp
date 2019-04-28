#include "Screen.hpp"

using BattleRoyale::Screen;

Screen::Screen(Map & map):
    mapElement_(map, 0, 0),
    playerElement_(PLAYER_ELEMENT_HPOS, PLAYER_ELEMENT_WPOS),
    messageElement_(MESSAGE_ELEMENT_HPOS, MESSAGE_ELEMENT_WPOS),
    height_(HEIGHT), weight_(WEIGHT), data_(HEIGHT, WEIGHT){}

Screen::~Screen(){
};



void Screen::focusAtPlayer(std::shared_ptr<Player> player){
    mapElement_.focusAtPlayer(player);
    playerElement_.focusAtPlayer(player);
}

void Screen::showMessage(std::string message){
    messageElement_.showMessage(message);
}

void Screen::showData(const CharMatrix & data){
    data_.clear();
    data_.fill(data);
}

void Screen::update(){
    mapElement_.update();
    mapElement_.draw(data_);
    playerElement_.update();
    playerElement_.draw(data_);
    messageElement_.update();
    messageElement_.draw(data_);
}



void Screen::draw() const{
    system("cls");
    std::cout << data_.toString();
}



unsigned int Screen::getHeight() const{
    return height_;
}

unsigned int Screen::getWeight() const{
    return weight_;
}

const unsigned int Screen::HEIGHT = 24;
const unsigned int Screen::WEIGHT = 80;
const unsigned int Screen::MAP_ELEMENT_HPOS = 0;
const unsigned int Screen::MAP_ELEMENT_WPOS = 0;
const unsigned int Screen::PLAYER_ELEMENT_HPOS = 0;
const unsigned int Screen::PLAYER_ELEMENT_WPOS = 24;
const unsigned int Screen::MESSAGE_ELEMENT_HPOS = 12;
const unsigned int Screen::MESSAGE_ELEMENT_WPOS = 24;
