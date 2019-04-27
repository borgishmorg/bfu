#include "Game.hpp"

using namespace BattleRoyale;

Game::Game():
    map_(), screen_(map_){
        players_.push_back(std::make_shared<Player>("Player 1", map_.at(1, 1)));
        players_.push_back(std::make_shared<Player>("Player 2", map_.at(5, 5)));
        map_.at(1, 1)->addPlayer(players_.at(0));
        map_.at(5, 5)->addPlayer(players_.at(1));
        map_.at(2, 3)->addItem(std::make_shared<Keyboard>());
    }

Game::~Game(){};



void Game::play(){
    int playerId = 0;
    std::string command;
    screen_.focusAtPlayer(players_.at(playerId));
    
    while (1){
        screen_.update();
        screen_.draw();

        std::cin >> command;
        if (command == "move"){
            std::string direction;
            std::cin >> direction;
            int di = 0, dj = 0;
            if(direction == "up" || direction == "u")
                di = -1;
            if(direction == "down" || direction == "d")
                di = 1;
            if(direction == "left" || direction == "l")
                dj = -1;
            if(direction == "right" || direction == "r")
                dj = 1;
            std::shared_ptr<Cell> newCell = map_.at(players_.at(playerId)->getPos()->getHPos() + di, 
                                     players_.at(playerId)->getPos()->getWPos() + dj);

            players_.at(playerId)->getPos()->removePlayer(players_.at(playerId));
            
            newCell->addPlayer(players_.at(playerId));
            
            players_.at(playerId)->setPos(newCell);

            continue;
        }
        if (command == "turn"){
            playerId = (playerId + 1) % players_.size();
            screen_.focusAtPlayer(players_.at(playerId));
            continue;
        }
        if(command == "look"){
            char w;
            int h;
            std::cin >> w >> h;
            int di = h - 8;
            int dj = w - 'I';
            std::string message = std::string() + "You look at " + w + std::to_string(h) + ":\n";
            try{
                message += map_.at(players_.at(playerId)->getPos()->getHPos() + di, players_.at(playerId)->getPos()->getWPos() + dj)->toString();
            }catch(...){
                message += "Unknown\n";
            }
            screen_.showMessage(message);
            continue;
        }
        if (command == "exit"){
            return;
        }
        screen_.showMessage("\"" + command + "\" command doesn't exist\n");
    }
}