#include "Player.hpp"

using BattleRoyale::Player;
using BattleRoyale::Cell;

#include <iostream>

Player::Player(std::string name, std::shared_ptr<Cell> pos):
    name_(name), pos_(pos),
    maxAP_(INITIAL_AP), maxCP_(INITIAL_CP), maxHP_(INITIAL_HP), maxIP_(INITIAL_IP),
    AP_(INITIAL_AP), CP_(0), HP_(INITIAL_HP), IP_(INITIAL_IP), 
    dead_(false){}

Player::~Player(){
    pos_ = nullptr;
    for(auto & item: items_)
        item = nullptr;
    items_.clear();
}



void Player::turn(){
    AP_ = maxAP_;
}



const std::string & Player::getName() const{
    return name_;
}

int Player::getIP() const{
    return IP_;
}

int Player::getAP() const{
    return AP_;
}

int Player::getHP() const{
    return HP_;
}

int Player::getCP() const{
    return CP_;
}

const std::string Player::getHPBar() const{
    return "(" + std::to_string(HP_) + "/" + std::to_string(maxHP_) + ")";
}

std::shared_ptr<Cell> Player::getPos(){
    return pos_;
}



void Player::setPos(std::shared_ptr<Cell> pos){
    pos_ = pos;
}

void Player::addIP(int delta){
    IP_ = std::min(maxIP_, IP_ + delta);
}

void Player::addAP(int delta){
    AP_ = std::min(maxAP_, AP_ + delta);
}

void Player::addHP(int delta){
    HP_ = std::min(maxHP_, HP_ + delta);
}

void Player::addCP(int delta){
    CP_ = std::min(maxCP_, CP_ + delta);
}

void Player::addItem(std::shared_ptr<Item> item){
    if(!isActive()){
        throw getName() + " can't take " + item->getName() + " now \n";
    }else if(CP_ >= maxCP_){
        throw getName() + " haven't empty slot\n";
    }else{
        CP_++;
        items_.push_back(item);
    }
}



const std::string Player::toString() const{
    std::string res;
    res = name_ + " ( HP " + std::to_string(HP_) + "/" + std::to_string(maxHP_) + "  " +
                     "AP " + std::to_string(AP_) + "/" + std::to_string(maxAP_) + "  " +
                     "IP " + std::to_string(IP_) + "/" + std::to_string(maxIP_) + " )\n";
    res += "Items ("+ std::to_string(CP_) + "/" + std::to_string(maxCP_) +"):\n";
    for(int i = 0; i < items_.size(); i++){
        res += std::to_string(i+1) + ": " + items_.at(i)->toString() + "  ";
    }
    return res;
}

bool Player::isDead() const{
    return dead_;
}

bool Player::isActive() const{
    return HP_ > 0 && AP_ > 0;
}


const int Player::INITIAL_IP = 0;
const int Player::INITIAL_AP = 3;
const int Player::INITIAL_HP = 100;
const int Player::INITIAL_CP = 2;