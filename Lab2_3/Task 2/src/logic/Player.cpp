#include "Player.hpp"

using BattleRoyale::Player;
using BattleRoyale::Cell;

#include <iostream>

Player::Player(std::string name, std::shared_ptr<Cell> pos):
    name_(name), pos_(pos),
    maxAP_(INITIAL_AP), maxCP_(INITIAL_CP), maxHP_(INITIAL_HP), maxIP_(INITIAL_IP),
    AP_(INITIAL_AP), CP_(INITIAL_CP), HP_(INITIAL_HP), IP_(INITIAL_IP){}

Player::~Player(){
    pos_ = nullptr;
    for(auto & item: items_)
        item = nullptr;
    items_.clear();
}




const std::string & Player::getName() const{
    return name_;
}

std::shared_ptr<Cell> Player::getPos(){
    return pos_;
}



void Player::setPos(std::shared_ptr<Cell> pos){
    pos_ = pos;
}



const int Player::INITIAL_IP = 0;
const int Player::INITIAL_AP = 3;
const int Player::INITIAL_HP = 100;
const int Player::INITIAL_CP = 2;