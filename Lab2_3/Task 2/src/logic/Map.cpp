#include "Map.hpp"

using BattleRoyale::Map;
using BattleRoyale::Cell;
using BattleRoyale::Player;

Map::Map(int height, int width):
    HEIGHT_(height), WIDTH_(width),
    upWall_(0), downWall_(height-1), leftWall_(0), rightWall_(width-1){
    cells_.resize(HEIGHT_);
    for(int i = 0; i < HEIGHT_; i++)
        for (int j = 0; j < WIDTH_; j++)
            if(i != 0 && i != HEIGHT_ - 1 &&
               j != 0 && j != WIDTH_ - 1)
                cells_.at(i).push_back(std::make_shared<Cell>(Cell::GRASS, i, j));
            else
                cells_.at(i).push_back(std::make_shared<Cell>(Cell::WALL, i, j));
}

Map::~Map(){}



void Map::moveWalls(){
    int way = rand() % 4;
    if(way == 0) upWall_++;
    else if(way == 1) downWall_--;
    else if(way == 2) leftWall_++;
    else  rightWall_--;

    for(int i = 0; i < HEIGHT_; i++)
        for (int j = 0; j < WIDTH_; j++)
            if(i <= upWall_ || i >= downWall_ ||
               j <= leftWall_ || j >= rightWall_)
                at(i, j)->setType(Cell::WALL);
}



std::shared_ptr<Cell> Map::at(unsigned int hPos, unsigned int wPos){
    return cells_.at(hPos).at(wPos);
}

std::shared_ptr<Cell> Map::at(Player & player, char w, int h){
    int di, dj;

    if(w < 'A' || w > 'Q' || h < 0 || h > 16)
        throw "Unknown place";
    
    di = h - 8;
    dj = w - 'I';
    
    try{
        return at(player.getPos()->getHPos() + di, player.getPos()->getWPos() + dj);
    }catch(...){
        throw "Unknown place";
    }
}

std::shared_ptr<Cell> Map::atRandomPos(){
    int h, w;

    do{
        h = rand()%HEIGHT_;
        w = rand()%WIDTH_;
    }while (at(h, w)->getType() != Cell::Type::GRASS ||
            at(h, w)->getPlayers().size() != 0 ||
            at(h, w)->getItems().size() != 0);
    
    return at(h, w);
}



std::vector<std::shared_ptr<Player> > Map::getPlayersInRadius(Cell & cell, int radius){
    std::vector<std::shared_ptr<Player> > res;
    int h = cell.getHPos();
    int w = cell.getWPos();

    for(int i = std::max(h - radius, 0); i <= std::min(h + radius, HEIGHT_ - 1); i++){
        for(int j = std::max(w - radius, 0); j <= std::min(w + radius, WIDTH_ - 1); j++){
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