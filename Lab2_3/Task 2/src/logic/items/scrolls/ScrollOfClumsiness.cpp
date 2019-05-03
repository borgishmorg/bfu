#include "ScrollOfClumsiness.hpp"

using BattleRoyale::ScrollOfClumsiness;

ScrollOfClumsiness::ScrollOfClumsiness():
    Scroll("Scroll of Clumsiness", DURABILITY_, COST_){}

ScrollOfClumsiness::~ScrollOfClumsiness(){}



void ScrollOfClumsiness::spell(Cell & target, Screen & screen){
    std::string res;
    for(auto player: target.getPlayers())
        if(rand()%100 < CHANCE_OF_LOSS_ && player->getStats().CP_ > 0){
            int n = rand()%player->getStats().CP_;
            
            if(player->getItem(n).get() == this || !player->getItem(n)->isDroppable()) continue;
            
            res += player->getName() + " lose item!\n";
            player->getPos()->addItem(player->getItem(n));
            player->removeItem(n);
        }
    if(res.empty())
        screen.drawMessage(name_ + " do nothing");
    else
        screen.drawMessage(res);
}



const unsigned int ScrollOfClumsiness::DURABILITY_ = 3U;
const unsigned int ScrollOfClumsiness::COST_ = 2U;
const unsigned int ScrollOfClumsiness::CHANCE_OF_LOSS_ = 50U;