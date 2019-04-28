#include "GameScreen.hpp"

using BattleRoyale::GameScreen;

GameScreen::GameScreen(Map & map):
    Screen(HEIGHT, WEIGHT), 
    mapElement_(map, 0, 0),
    playerElement_(PLAYER_ELEMENT_HPOS, PLAYER_ELEMENT_WPOS),
    messageElement_(MESSAGE_ELEMENT_HPOS, MESSAGE_ELEMENT_WPOS){
        addElement(mapElement_);
        addElement(playerElement_);
        addElement(messageElement_);
    }

GameScreen::~GameScreen(){};



void GameScreen::focusAtPlayer(std::shared_ptr<Player> player){
    mapElement_.focusAtPlayer(player);
    playerElement_.focusAtPlayer(player);
}



void GameScreen::drawMessage(std::string message){
    messageElement_.showMessage(message);
    draw();
}



const unsigned int GameScreen::HEIGHT = 24;
const unsigned int GameScreen::WEIGHT = 80;
const unsigned int GameScreen::MAP_ELEMENT_HPOS = 0;
const unsigned int GameScreen::MAP_ELEMENT_WPOS = 0;
const unsigned int GameScreen::PLAYER_ELEMENT_HPOS = 0;
const unsigned int GameScreen::PLAYER_ELEMENT_WPOS = 24;
const unsigned int GameScreen::MESSAGE_ELEMENT_HPOS = 12;
const unsigned int GameScreen::MESSAGE_ELEMENT_WPOS = 24;
