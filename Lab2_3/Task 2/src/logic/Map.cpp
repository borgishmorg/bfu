#include "Map.hpp"

using BattleRoyale::Map;
using BattleRoyale::Cell;
using BattleRoyale::CellType;

Map::Map(){
    cells_.resize(HEIGHT);
    for(unsigned int i = 0; i < HEIGHT; i++){
        //cells_.push_back(std::vector<std::shared_ptr<Cell> > ());
        for (unsigned int j = 0; j < WEIGHT; j++)
            if(i != 0 && i != HEIGHT - 1 &&
               j != 0 && j != WEIGHT - 1)
                cells_.at(i).push_back(std::make_shared<Cell>(GRASS, i, j));
            else
                cells_.at(i).push_back(std::make_shared<Cell>(WALL, i, j));
    }
}

Map::~Map(){}



std::shared_ptr<Cell> Map::at(unsigned int hPos, unsigned int wPos){
    return cells_.at(hPos).at(wPos);
}

const unsigned int Map::HEIGHT = 100;
const unsigned int Map::WEIGHT = 100;