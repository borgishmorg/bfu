#ifndef __CELL__
#define __CELL__

#include <memory>
#include <vector>

namespace BattleRoyale{
    class Cell;
}

#include "Item.hpp"
#include "Player.hpp"
#include "CharMatrix.hpp"

namespace BattleRoyale{
    class Cell{
        public:
            enum Type{GRASS, WALL};

            Cell(Type, unsigned int hPos, unsigned int wPos);
            ~Cell();

            Type getType() const;
            unsigned int getHPos() const;
            unsigned int getWPos() const;

            std::vector<std::shared_ptr<Player> > & getPlayers();
            std::vector<std::shared_ptr<Item> > & getItems();

            std::string toString() const;

            void setType(Type);
            void addPlayer(std::shared_ptr<Player>);
            void addItem(std::shared_ptr<Item>);

            void removePlayer(std::shared_ptr<Player>);
            void removePlayer(Player *);
            void removeItem(std::shared_ptr<Item>);

            static char charFromCellType(Type);
            static std::string stringFromCellType(Type);
        private:
            Type type_;
            unsigned int hPos_;
            unsigned int wPos_;
            
            std::vector<std::shared_ptr<Player> > players_;
            std::vector<std::shared_ptr<Item> > items_;
    };
}

#endif