#include "Player.hpp"

using BattleRoyale::Player;
using BattleRoyale::Cell;
using BattleRoyale::Item;

#include <iostream>

Player::Stats::Stats(int IP, int AP, int HP, int CP):
    IP_(IP), AP_(AP), HP_(HP), CP_(CP){}

Player::Stats::~Stats(){}
/*
============================================================================================================
*/
Player::Player(std::string name, std::shared_ptr<Cell> pos):
    name_(name), pos_(pos),
    maxStats_(INITIAL_IP, INITIAL_AP, INITIAL_HP, INITIAL_CP),
    stats_(INITIAL_IP, INITIAL_AP, INITIAL_HP, 0), 
    score_(-1), upgradePoints_(0), dead_(false){}

Player::~Player(){
    pos_ = nullptr;
    for(auto & item: items_)
        item = nullptr;
    items_.clear();
}
/*
============================================================================================================
*/
void Player::dropItem(int n){
    if (stats_.HP_ <= 0)
        throw name_ + " can't drop item now!";
    
    try{
        if(!getItem(n)->isDroppable())
            throw getItem(n)->getName() + " can't be dropped!";
    }catch(std::string e){
        throw e;
    }
    pos_->addItem(getItem(n));
    removeItem(n);
}

void Player::removeItem(int n){
    items_.erase(items_.begin()+n);
    addCP(-1);
}

void Player::turn(){
    stats_.AP_ = std::max(stats_.AP_, maxStats_.AP_);
}

void Player::heal(){
    if(stats_.AP_ <= 0)
        throw name_ + " can't heal now!\n";
    if(stats_.HP_ >= maxStats_.HP_)
        throw name_ + " already have max health!\n";
    
    addHP(5);
    addAP(-1);
}

void Player::die(){
    dead_ = true;
    stats_.HP_ = std::min(0, stats_.HP_);
    pos_->removePlayer(this);
}

void Player::upgrade(StatType type){
    if (type == NO_TYPE || upgradePoints_ <= 0) 
        throw name_ + " can't upgrade this";
    
    switch (type){
        case IP:{
            int deltaIP = 5 + rand()%6;
            stats_.IP_ += deltaIP;
            maxStats_.IP_ += deltaIP;
            break;
        }
        case AP:{
            int deltaAP = 2 + rand()%4;
            //stats_.AP_ += deltaAP;
            maxStats_.AP_ += deltaAP;
            break;
        }
        case HP:{
            int deltaHP = 10 + rand()%31;
            if(stats_.HP_ > 0) stats_.HP_ += deltaHP;
            maxStats_.HP_ += deltaHP;
            break;
        }
        case CP:{
            int deltaCP = 1 + rand()%2;
            //stats_.CP_ += deltaCP;
            maxStats_.CP_ += deltaCP;
            break;
        }    
    }
    upgradePoints_--;
}

void Player::upgrade(StatType type, int dLevel){
    if (type == NO_TYPE || upgradePoints_ <= 0) 
        throw name_ + " can't upgrade this";
    
    switch (type){
        case IP:{
            stats_.IP_ += dLevel;
            maxStats_.IP_ += dLevel;
            break;
        }
        case AP:{
            //stats_.AP_ += deltaAP;
            maxStats_.AP_ += dLevel;
            break;
        }
        case HP:{
            if(stats_.HP_ > 0) stats_.HP_ += dLevel;
            maxStats_.HP_ += dLevel;
            break;
        }
        case CP:{
            //stats_.CP_ += deltaCP;
            maxStats_.CP_ += dLevel;
            break;
        }    
    }
    upgradePoints_--;
}
/*
============================================================================================================
*/
void Player::takeDamage(int damage){
    addHP(-damage);
}

void Player::takeFatigue(int fatigue){
    addAP(-fatigue);
}
/*
============================================================================================================
*/
void Player::setName(std::string name){
    name_ = name;
}

void Player::setPos(std::shared_ptr<Cell> pos){
    pos_ = pos;
}

void Player::addScore(int delta){
    score_ += delta;
}

void Player::addUpgradePoints(int delta){
    upgradePoints_ += delta;
}

void Player::addItem(std::shared_ptr<Item> item){
    if(!isActive())
        throw getName() + " can't take " + item->getName() + " now!\n";
    if(stats_.CP_ >= maxStats_.CP_)
        throw getName() + " haven't empty space!\n";
    
    addCP(1);
    items_.push_back(item);
}
/*
============================================================================================================
*/
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

int Player::getUpgradePoints() const{
    return upgradePoints_;
}

std::shared_ptr<Cell> Player::getPos(){
    return pos_;
}

std::shared_ptr<Item> Player::getItem(int n){
    try{
        return items_.at(n);
    }catch(...){
        throw name_ + " doesn't have this item!";
    } 
}

const std::string Player::toString() const{
    std::string res = name_;

    res += " ( HP " + std::to_string(stats_.HP_) + "/" + std::to_string(maxStats_.HP_) + "  " +
              "AP " + std::to_string(stats_.AP_) + "/" + std::to_string(maxStats_.AP_) + "  " +
              "IP " + std::to_string(stats_.IP_) + "/" + std::to_string(maxStats_.IP_) + " ) ";
    
    if(upgradePoints_ > 0) res += " New level!";
    
    res += "\nItems ("+ std::to_string(stats_.CP_) + "/" + std::to_string(maxStats_.CP_) +"):\n";
    
    for(int i = 0; i < items_.size(); i++)
        res += std::to_string(i+1) + ": " + items_.at(i)->toString() + "  ";
    
    return res;
}

const std::string Player::toShortString() const{
    std::string res = name_;
    
    if(dead_) res += " (DEAD) ";
    else res += " (" + std::to_string(stats_.HP_) + "/" + std::to_string(maxStats_.HP_) + ")" ;
    
    return res;
}

bool Player::isDead() const{
    return dead_;
}

bool Player::isActive() const{
    return stats_.HP_ > 0 && stats_.AP_ > 0;
}
/*
============================================================================================================
*/
Player::StatType Player::stringToStatType(std::string type){
    if (type == "IP" || type == "ip") return IP;
    else if (type == "AP" || type == "ap") return AP;
    else if (type == "HP" || type == "hp") return HP;
    else if (type == "CP" || type == "cp") return CP;
    else return NO_TYPE;
}
/*
============================================================================================================
*/
void Player::addIP(int delta){
    stats_.IP_ = std::min(maxStats_.IP_, stats_.IP_ + delta);
}

void Player::addAP(int delta){
    stats_.AP_ += delta;
    //stats_.AP_ = std::min(maxStats_.AP_, stats_.AP_ + delta);
}

void Player::addHP(int delta){
    stats_.HP_ = std::min(maxStats_.HP_, stats_.HP_ + delta);
}

void Player::addCP(int delta){
    stats_.CP_ = std::min(maxStats_.CP_, stats_.CP_ + delta);
}
/*
============================================================================================================
*/
const int Player::INITIAL_IP = 0;
const int Player::INITIAL_AP = 3;
const int Player::INITIAL_HP = 100;
const int Player::INITIAL_CP = 2;