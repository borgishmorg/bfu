#include "InfinityGauntlet.hpp"

using BattleRoyale::InfinityGauntlet;
using BattleRoyale::InfinityStone;

InfinityGauntlet::InfinityGauntlet():
    Item("Empty Infinity Gauntlet", 1, 2000000000), state_(EMPTY){};

InfinityGauntlet::~InfinityGauntlet(){}



void InfinityGauntlet::use(Player & user, Map & map, Screen & screen){
    if(!user.isActive())
        throw user.getName() + " can't use " + name_ + " now!";
    
    switch (state_){
        case EMPTY:{
            int cnt = 0;
            
            for(int i = 0; i < user.getStats().CP_; i++)
                if(InfinityStone::stringToType(user.getItem(i)->getName()) != InfinityStone::NO_TYPE)
                    cnt++;
            
            if(cnt != 6){
                screen.drawMessage(user.getName() + " doesn't have all the Infinity Stones!");
                return;
            }

            for(int i = user.getStats().CP_ - 1; i >= 0; i--)
                if(InfinityStone::stringToType(user.getItem(i)->getName()) != InfinityStone::NO_TYPE)
                    user.removeItem(i);

            screen.drawMessage(user.getName() + " has finished the Infinity Gauntlet!");

            name_ = "Infinity Gauntlet";
            state_ = FULL;
            return;
        }
        case FULL:{
            std::string msg;
            bool dead = true;
            std::vector<std::shared_ptr<Player> > players = map.getPlayersInRadius(*user.getPos(), 1000);

            for(auto & player: players){
                if (player.get() == &user) continue;
                if(dead){
                    player->die();
                    user.addScore(10);
                    msg += player->getName() + " has vanished...\n";
                } 
                dead = !dead;
            }

            screen.drawMessage(msg + "Fate has come true!");

            user.takeFatigue(-user.getStats().AP_);
            name_ = "Broken Infinity Gauntlet";
            stats_.droppable_ = false;
            state_ = BROKEN;
            return;
        }
        case BROKEN:{
            screen.drawMessage(user.getName() + " feels a sense of accomplishment");
            return;
        }
    }
}



const std::string InfinityGauntlet::toString() const{
    return name_;
}