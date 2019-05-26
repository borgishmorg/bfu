#include "ScrollOfWall.hpp"

using BattleRoyale::ScrollOfWall;

ScrollOfWall::ScrollOfWall():
    Scroll("Scroll of Wall", DURABILITY_, COST_){}

ScrollOfWall::~ScrollOfWall(){}



void ScrollOfWall::spell(Cell & target, Screen & screen){
    if(!target.getPlayers().empty())
        screen.drawMessage(name_ + " can't place the wall there!\nPlace should be empty!");
    else if(target.getType() == Cell::WALL)
        screen.drawMessage(name_ + " can't place the wall there!\nThe wall is already there!");
    else{
        target.setType(Cell::WALL);
        screen.drawMessage(name_ + " has successfully placed the wall!");
    }  
}



const unsigned int ScrollOfWall::DURABILITY_ = 5U;
const unsigned int ScrollOfWall::COST_ = 1U;