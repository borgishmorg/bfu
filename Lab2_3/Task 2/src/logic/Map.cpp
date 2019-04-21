#include "Map.hpp"

using BattleRoyale::Map;
using BattleRoyale::Cell;
using BattleRoyale::CellType;

Map::Map(){
    for(unsigned int i = 0; i < HEIGHT; i++){
        cells_.push_back(std::vector<Cell>());
        for (unsigned int j = 0; j < WEIGHT; j++)
            if(i != 0 && i != HEIGHT - 1 &&
               j != 0 && j != WEIGHT - 1)
                cells_.at(i).push_back(Cell(GRASS, i, j));
            else
                cells_.at(i).push_back(Cell(WALL, i, j));
    }
}

Map::~Map(){}

Cell & Map::at(unsigned int hPos, unsigned int wPos){
    return cells_.at(hPos).at(wPos);
}

const unsigned int Map::HEIGHT = 10;
const unsigned int Map::WEIGHT = 10;