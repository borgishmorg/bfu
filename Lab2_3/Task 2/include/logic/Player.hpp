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

            void turn();

            const std::string & getName() const;
            int getIP() const;
            int getAP() const;
            int getHP() const;
            int getCP() const;
            const std::string  getHPBar() const;
            std::shared_ptr<Cell> getPos();

            void setPos(std::shared_ptr<Cell>);
            void addIP(int delta);
            void addAP(int delta);
            void addHP(int delta);
            void addCP(int delta);

            const std::string toString() const;
            bool isDead() const;
            bool isMovable() const;
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

            bool dead_;

            std::vector<std::shared_ptr<Item> > items_;
            
            static const int INITIAL_IP;
            static const int INITIAL_AP;
            static const int INITIAL_HP;
            static const int INITIAL_CP;
    };

}

#endif