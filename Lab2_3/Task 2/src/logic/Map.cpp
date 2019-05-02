#include "Map.hpp"

using BattleRoyale::Map;
using BattleRoyale::Cell;
using BattleRoyale::Player;

Map::Map(){
    cells_.resize(HEIGHT);
    for(unsigned int i = 0; i < HEIGHT; i++)
        for (unsigned int j = 0; j < WIDTH; j++)
            if(i != 0 && i != HEIGHT - 1 &&
               j != 0 && j != WIDTH - 1)
                cells_.at(i).push_back(std::make_shared<Cell>(Cell::Type::GRASS, i, j));
            else
                cells_.at(i).push_back(std::make_shared<Cell>(Cell::Type::WALL, i, j));
}

Map::~Map(){}



std::shared_ptr<Cell> Map::at(unsigned int hPos, unsigned int wPos){
    return cells_.at(hPos).at(wPos);
}

std::shared_ptr<Cell> Map::atRandomPos(){
    int h, w;

    do{
        h = rand()%HEIGHT;
        w = rand()%WIDTH;
    }while (at(h, w)->getType() != Cell::Type::GRASS ||
            at(h, w)->getPlayers().size() != 0 ||
            at(h, w)->getItems().size() != 0);
    
    return at(h, w);
}



std::vector<std::shared_ptr<Player> > Map::getPlayersInRadius(Cell & cell, int radius){
    std::vector<std::shared_ptr<Player> > res;
    int h = cell.getHPos();
    int w = cell.getWPos();

    for(int i = std::max(h - radius, 0); i <= std::min(h + radius, (int) HEIGHT - 1); i++){
        for(int j = std::max(w - radius, 0); j <= std::min(w + radius, (int) WIDTH - 1); j++){
            if((i-h)*(i-h)+(j-w)*(j-w) <= radius*radius){
                try{
                    res.insert(res.end(), at(i, j)->getPlayers().begin(), at(i, j)->getPlayers().end());
                }catch(...){
                    //this case is impossible
                }
            }
        }
    }
    
    sort(res.begin(), res.end(), [h, w](std::shared_ptr<Player> a, std::shared_ptr<Player> b)->bool{
        int ah = a->getPos()->getHPos();
        int aw = a->getPos()->getWPos();
        int bh = b->getPos()->getHPos();
        int bw = b->getPos()->getWPos();
        return (ah-h)*(ah-h)+(aw-w)*(aw-w) < (bh-h)*(bh-h)+(bw-w)*(bw-w);
    });

    return res;
}



const unsigned int Map::HEIGHT = 100;
const unsigned int Map::WIDTH = 100;