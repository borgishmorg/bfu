#include "Screen.hpp"

using BattleRoyale::Screen;

Screen::Screen(std::shared_ptr<Map> map):
    mapElement_(map, 0, 0), height_(HEIGHT), weight_(WEIGHT), data_(HEIGHT, WEIGHT){}

Screen::~Screen(){};



void Screen::focusAtPlayer(std::shared_ptr<Player> player){
    player_ = player;
    mapElement_.focusAtPlayer(player);
}

void Screen::lookAtCell(std::shared_ptr<Cell> cell){
    cell_ = cell;
}



void Screen::update(){
    mapElement_.update();
    mapElement_.draw(data_);
}



void Screen::draw() const{
    std::cout << data_.toString();
}



const unsigned int Screen::HEIGHT = 24;
const unsigned int Screen::WEIGHT = 80;
const unsigned int Screen::MAP_ELEMENT_HPOS = 0;
const unsigned int Screen::MAP_ELEMENT_WPOS = 0;
