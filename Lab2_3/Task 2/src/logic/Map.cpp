#include "Map.hpp"

using BattleRoyale::Map;
using BattleRoyale::Cell;

Map::Map(){
    cells_.resize(HEIGHT);
    for(unsigned int i = 0; i < HEIGHT; i++){
        //cells_.push_back(std::vector<std::shared_ptr<Cell> > ());
        for (unsigned int j = 0; j < WEIGHT; j++)
            if(i != 0 && i != HEIGHT - 1 &&
               j != 0 && j != WEIGHT - 1)
                cells_.at(i).push_back(std::make_shared<Cell>(Cell::Type::GRASS, i, j));
            else
                cells_.at(i).push_back(std::make_shared<Cell>(Cell::Type::WALL, i, j));
    }
}

Map::~Map(){}



std::shared_ptr<Cell> Map::at(unsigned int hPos, unsigned int wPos){
    return cells_.at(hPos).at(wPos);
}


std::shared_ptr<Cell> Map::atRandomPos(){
    int h, w;
    do{
        h = rand()%HEIGHT;
        w = rand()%WEIGHT;
    }while (at(h, w)->getType() != Cell::Type::GRASS ||
            at(h, w)->getPlayers().size() != 0 ||
            at(h, w)->getItems().size() != 0);
    return at(h, w);
}



const unsigned int Map::HEIGHT = 25;
const unsigned int Map::WEIGHT = 25;