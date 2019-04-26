#include "MapScreenElement.hpp"
#include <iostream>

using BattleRoyale::MapScreenElement;

MapScreenElement::MapScreenElement(Map & map, unsigned int hPos, unsigned int wPos):
    viewData_(VIEW_DATA_HEIGHT, VIEW_DATA_WEIGHT), map_(map), ScreenElement(hPos, wPos, HEIGHT, WEIGHT){
        data_.fill(BACKGROUND_DATA);
    };

MapScreenElement::~MapScreenElement(){
    player_ = nullptr;
};



void MapScreenElement::focusAtPlayer(std::shared_ptr<Player> player){
    player_ = player;
    update();
}
void MapScreenElement::update(){
    for(unsigned int i = 0; i < VIEW_DATA_HEIGHT; i++){
        for(unsigned int j = 0; j < VIEW_DATA_WEIGHT; j++){
            if(player_ == nullptr){
                viewData_.at(i, j) = ' ';
            }else if(i == VIEW_DATA_HEIGHT/2  && j == VIEW_DATA_WEIGHT/2){
                viewData_.at(i, j) = 'P';
            }else{
                try{
                    Cell & cell = *map_.at(player_->getPos()->getHPos() + i - VIEW_DATA_HEIGHT/2,
                                        player_->getPos()->getWPos() + j - VIEW_DATA_WEIGHT/2);
                    
                    if(cell.getPlayers().size() != 0)
                        viewData_.at(i, j) = 'E';
                    else if(cell.getItems().size() != 0)
                        viewData_.at(i, j) = 'I';
                    else
                        viewData_.at(i, j) = Cell::charFromCellType(cell.getType());
                }catch(...){
                    viewData_.at(i, j) = ' ';
                }  
            }
            
        }
    }
    data_.fill(viewData_, VIEW_DATA_HPOS, VIEW_DATA_WPOS);
}

const std::string MapScreenElement::BACKGROUND_DATA = std::string()+
            " +--------------------+ "+
            "++                    ++"+
            "|   ABCDEFGHIJKLMNOPR  |"+
            "|  +-----------------+ |"+
            "| 0|                 | |"+
            "| 1|                 | |"+
            "| 2|                 | |"+
            "| 3|                 | |"+
            "| 4|                 | |"+
            "| 5|                 | |"+
            "| 6|                 | |"+
            "| 7|                 | |"+
            "| 8|                 | |"+
            "| 9|                 | |"+
            "|10|                 | |"+
            "|11|                 | |"+
            "|12|                 | |"+
            "|13|                 | |"+
            "|14|                 | |"+
            "|15|                 | |"+
            "|16|                 | |"+
            "|  +-----------------+ |"+
            "++                    ++"+
            " +--------------------+ ";

const unsigned int MapScreenElement::HEIGHT = 24;
const unsigned int MapScreenElement::WEIGHT = 24;
const unsigned int MapScreenElement::VIEW_DATA_HEIGHT = 17;
const unsigned int MapScreenElement::VIEW_DATA_WEIGHT = 17;
const unsigned int MapScreenElement::VIEW_DATA_HPOS = 4;
const unsigned int MapScreenElement::VIEW_DATA_WPOS = 4;