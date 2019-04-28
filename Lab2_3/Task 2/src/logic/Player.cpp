#include "Player.hpp"

using BattleRoyale::Player;
using BattleRoyale::Cell;
using BattleRoyale::Item;

#include <iostream>

Player::Stats::Stats(int IP, int AP, int HP, int CP):
    IP_(IP), AP_(AP), HP_(HP), CP_(CP){}

Player::Stats::~Stats(){}


Player::Player(std::string name, std::shared_ptr<Cell> pos):
    name_(name), pos_(pos),
    maxStats_(INITIAL_IP, INITIAL_AP, INITIAL_HP, INITIAL_CP),
    stats_(INITIAL_IP, INITIAL_AP, INITIAL_HP, 0), 
    score_(-1), dead_(false){}

Player::~Player(){
    pos_ = nullptr;
    for(auto & item: items_)
        item = nullptr;
    items_.clear();
}



void Player::turn(){
    stats_.AP_ = maxStats_.AP_;
}

void Player::heal(){
    if(stats_.AP_ <= 0){
        throw name_ + " can't heal now!\n";
    }else if(stats_.HP_ >= maxStats_.HP_){
        throw name_ + " already have max health!\n";
    }else{
        addHP(5);
        addAP(-1);
    }
}


const std::string & Player::getName() const{
    return name_;
}

int Player::getScore() const{
    return score_;
}

const Player::Stats & Player::getStats() const{
    return stats_;
}

const Player::Stats & Player::getMaxStats() const{
    return maxStats_;
}

std::shared_ptr<Cell> Player::getPos(){
    return pos_;
}



std::shared_ptr<Item> Player::throwItem(int n){
    if (stats_.HP_ <= 0)
        throw name_ + " can't drop item now!";
    std::shared_ptr<Item> item;
    try{
        item = items_.at(n);
    }catch(...){
        throw name_ + " doesn't have this item!";
    }
    items_.erase(items_.begin()+n);
    addCP(-1);
    return item;
}

void Player::die(){
    dead_ = true;
    pos_->removePlayer(this);
}



void Player::setPos(std::shared_ptr<Cell> pos){
    pos_ = pos;
}

void Player::addScore(int delta){
    score_ += delta;
}

void Player::addIP(int delta){
    stats_.IP_ = std::min(maxStats_.IP_, stats_.IP_ + delta);
}

void Player::addAP(int delta){
    stats_.AP_ = std::min(maxStats_.AP_, stats_.AP_ + delta);
}

void Player::addHP(int delta){
    stats_.HP_ = std::min(maxStats_.HP_, stats_.HP_ + delta);
}

void Player::addCP(int delta){
    stats_.CP_ = std::min(maxStats_.CP_, stats_.CP_ + delta);
}

void Player::addItem(std::shared_ptr<Item> item){
    if(!isActive()){
        throw getName() + " can't take " + item->getName() + " now \n";
    }else if(stats_.CP_ >= maxStats_.CP_){
        throw getName() + " haven't empty slot\n";
    }else{
        stats_.CP_++;
        items_.push_back(item);
    }
}



const std::string Player::toString() const{
    std::string res;
    res = name_ + " ( HP " + std::to_string(stats_.HP_) + "/" + std::to_string(maxStats_.HP_) + "  " +
                     "AP " + std::to_string(stats_.AP_) + "/" + std::to_string(maxStats_.AP_) + "  " +
                     "IP " + std::to_string(stats_.IP_) + "/" + std::to_string(maxStats_.IP_) + " )\n";
    res += "Items ("+ std::to_string(stats_.CP_) + "/" + std::to_string(maxStats_.CP_) +"):\n";
    for(int i = 0; i < items_.size(); i++){
        res += std::to_string(i+1) + ": " + items_.at(i)->toShortString() + "  ";
    }
    return res;
}

const std::string Player::toShortString() const{
    std::string res = name_;
    if(dead_){
        res += " (DEAD) ";
    }else{
        res += " (" + std::to_string(stats_.HP_) + "/" + std::to_string(maxStats_.HP_) + ") " ;
    }
    return res;
}

bool Player::isDead() const{
    return dead_;
}

bool Player::isActive() const{
    return stats_.HP_ > 0 && stats_.AP_ > 0;
}


const int Player::INITIAL_IP = 0;
const int Player::INITIAL_AP = 3;
const int Player::INITIAL_HP = 100;
const int Player::INITIAL_CP = 2;