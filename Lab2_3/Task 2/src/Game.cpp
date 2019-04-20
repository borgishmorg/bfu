#include "Game.hpp"

using BattleRoyale::Game;

Game::Game():
    screen(SCREEN_HEIGHT, SCREEN_WEIGHT), 
    mapElement(0, 0){
        screen.addElement(mapElement);
    }

Game::~Game(){};



void Game::play(){
    screen.update();
    screen.draw();
}