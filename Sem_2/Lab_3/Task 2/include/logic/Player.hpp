#ifndef __PLAYER__
#define __PLAYER__

#include <memory>
#include <vector>
#include <string>
#include <cstdlib>

namespace BattleRoyale{
    class Player;
}

#include "Cell.hpp"
#include "Item.hpp"

namespace BattleRoyale{

    class Player{
        public:
            enum StatType{NO_TYPE, IP, AP, HP, CP};

            struct Stats{
                int IP_; //initiative points
                int AP_; //action points
                int HP_; //health points
                int CP_; //capacity points

                Stats(int IP, int AP, int HP, int CP);
                ~Stats();
            };

            Player(std::string, std::shared_ptr<Cell>);
            ~Player();

            void dropItem(int n);
            void removeItem(int n);
            void turn();
            void heal();
            void die();
            void upgrade(StatType type);
            void upgrade(StatType type, int dLevel);

            void takeDamage(int damage);
            void takeFatigue(int fatigue);

            void setName(std::string);
            void setPos(std::shared_ptr<Cell>);
            void addScore(int delta);
            void addUpgradePoints(int delta);
            void addItem(std::shared_ptr<Item> item);

            const std::string & getName() const;
            int getScore() const;
            const Stats & getStats() const;
            const Stats & getMaxStats() const;
            int getUpgradePoints() const;
            std::shared_ptr<Cell> getPos();
            std::shared_ptr<Item> getItem(int n);
            const std::string toString() const;
            const std::string toShortString() const;
            bool isDead() const;
            bool isActive() const;

            static StatType stringToStatType(std::string type);
        private:
            std::string name_;
            std::shared_ptr<Cell> pos_;
            Stats stats_;
            Stats maxStats_;
            int score_;
            int upgradePoints_;
            bool dead_;

            std::vector<std::shared_ptr<Item> > items_;
            
            void addCP(int delta);
            void addIP(int delta);
            void addAP(int delta);
            void addHP(int delta);
            
            static const int INITIAL_IP;
            static const int INITIAL_AP;
            static const int INITIAL_HP;
            static const int INITIAL_CP;
    };

}

#endif