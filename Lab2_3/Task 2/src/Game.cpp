#include "Game.hpp"

using namespace BattleRoyale;

Game::Game():
    map_(), screen_(std::shared_ptr<Map>(&map_)){
        players_.push_back(Player("Player 1", std::make_shared<Cell>(map_.at(1, 1))));
        players_.push_back(Player("Player 2", std::make_shared<Cell>(map_.at(5, 5))));
        map_.at(1, 1).addPlayer(std::make_shared<Player>(players_.at(0)));
        map_.at(5, 5).addPlayer(std::make_shared<Player>(players_.at(1)));
    }

Game::~Game(){};



void Game::play(){
    screen_.update();
    screen_.draw();

    screen_.focusAtPlayer(std::make_shared<Player>(players_.at(0)));
    screen_.update();
    screen_.draw();
    screen_.focusAtPlayer(std::make_shared<Player>(players_.at(1)));
    screen_.update();
    screen_.draw();
}