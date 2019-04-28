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
    
    enum CellType{GRASS, WALL};
    
    class Cell{
        public:
            Cell(CellType, unsigned int hPos, unsigned int wPos);
            ~Cell();

            CellType getType() const;
            unsigned int getHPos() const;
            unsigned int getWPos() const;

            std::vector<std::shared_ptr<Player> > & getPlayers();
            std::vector<std::shared_ptr<Item> > & getItems();

            std::string toString() const;

            void setType(CellType);
            void addPlayer(std::shared_ptr<Player>);
            void addItem(std::shared_ptr<Item>);

            void removePlayer(std::shared_ptr<Player>);
            void removePlayer(Player *);
            void removeItem(std::shared_ptr<Item>);

            static char charFromCellType(CellType);
            static std::string stringFromCellType(CellType);
        private:
            CellType type_;
            unsigned int hPos_;
            unsigned int wPos_;
            
            std::vector<std::shared_ptr<Player> > players_;
            std::vector<std::shared_ptr<Item> > items_;


    };
}

#endif