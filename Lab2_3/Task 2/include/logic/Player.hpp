#ifndef __PLAYER__
#define __PLAYER__

#include <memory>
#include <vector>
#include <string>

namespace BattleRoyale{
    class Player;
}

#include "Cell.hpp"

namespace BattleRoyale{

    class Player{
        public:
            Player(std::string, std::shared_ptr<Cell>);
            ~Player();

            const std::string & getName() const;
            std::shared_ptr<Cell> getPos();

            void setPos(std::shared_ptr<Cell>);
        private:
            std::string name_;
            std::shared_ptr<Cell> pos_;

            int maxIP_; //initiative points
            int maxAP_; //action points
            int maxHP_; //health points
            int maxCP_; //capacity points
            
            int IP_; //initiative points
            int AP_; //action points
            int HP_; //health points
            int CP_; //capacity points

            std::vector<std::shared_ptr<Item> > items_;
            
            static const int INITIAL_IP;
            static const int INITIAL_AP;
            static const int INITIAL_HP;
            static const int INITIAL_CP;
    };

}

#endif