#include "Cell.hpp"

using BattleRoyale::Player;
using BattleRoyale::Item;
using BattleRoyale::Cell;
using BattleRoyale::CharMatrix;



Cell::Cell(Type type, unsigned int hPos, unsigned int wPos):
    type_(type), hPos_(hPos), wPos_(wPos){}

Cell::~Cell(){
    for(auto & player: players_)
        player = nullptr;

    for(auto & item: items_)
        item = nullptr;

    players_.clear();
    items_.clear();
}
/*
=================================================================================================
*/
void Cell::setType(Type type){
    type_ = type;

    if(type == WALL)
        for(auto player: players_)
            player->die();
}

void Cell::addPlayer(std::shared_ptr<Player> player){
    removePlayer(player);
    players_.push_back(player);
}

void Cell::addItem(std::shared_ptr<Item> item){
    removeItem(item);
    items_.push_back(item);
}
/*
=================================================================================================
*/
void Cell::removePlayer(std::shared_ptr<Player> player){
    for(int i = 0; i < players_.size(); i++)
        if(players_.at(i) == player)
            players_.erase(players_.begin() + i);
}

void Cell::removePlayer(Player * player){
    for(int i = 0; i < players_.size(); i++)
        if(players_.at(i).get() == player)
            players_.erase(players_.begin() + i);
}

void Cell::removeItem(std::shared_ptr<Item> item){
    for(int i = 0; i < items_.size(); i++)
        if(items_.at(i) == item)
            items_.erase(items_.begin() + i);
}
/*
=================================================================================================
*/
Cell::Type Cell::getType() const{
    return type_;
}

unsigned int Cell::getHPos() const{
    return hPos_;
}

unsigned int Cell::getWPos() const{
    return wPos_;
}

std::vector<std::shared_ptr<Player> > & Cell::getPlayers(){
    return players_;
}

std::vector<std::shared_ptr<Item> > & Cell::getItems(){
    return items_;
}

std::string Cell::toString() const{
    CharMatrix data(7, 52);
    CharMatrix playersData(6, 26);
    CharMatrix itemsData(6, 26);
    std::string res;

    res = "Type: " + stringFromCellType(type_);
    data.fill(res);

    res = "Players:\n";
    for(unsigned int i = 0; i < players_.size(); i++){
        res += " " + std::to_string(i+1) + ": " + players_.at(i)->toShortString() + "\n";
    }
    playersData.fill(res);

    res = "Items:\n";
    for(unsigned int i = 0; i < items_.size(); i++){
        res += " " + std::to_string(i+1) + ": " + items_.at(i)->toShortString() + "\n";
    }
    
    itemsData.fill(res);
    data.fill(playersData, 1, 0);
    data.fill(itemsData, 1, 26);
    
    return data.toString();
}
/*
=================================================================================================
*/
char Cell::charFromCellType(Type type){
    switch (type)
    {
        case GRASS:
            return ',';
        case WALL:
            return '#';
        default:
            return ' ';
    }
}

std::string Cell::stringFromCellType(Type type){
    switch (type)
    {
        case GRASS:
            return "Grass";
        case WALL:
            return "Wall";
        default:
            return "Unknown";
    }
}