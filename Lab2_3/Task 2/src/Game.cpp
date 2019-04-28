#include "Game.hpp"

using namespace BattleRoyale;

Game::Game(const unsigned int NUMBER_OF_PLAYERS):
    NUMBER_OF_PLAYERS_(NUMBER_OF_PLAYERS), gameContinue(NUMBER_OF_PLAYERS > 0),
    map_(), screen_(map_), 
    playersQueue_([](std::shared_ptr<Player> a, std::shared_ptr<Player> b){ return a->getStats().IP_ > b->getStats().IP_; }){
        
        for (unsigned int i = 0; i < NUMBER_OF_PLAYERS_; i++){
            players_.push_back(std::make_shared<Player>("Player " + std::to_string(i+1), map_.atRandomPos()));
            players_.back()->getPos()->addPlayer(players_.at(i));
        }
            
        map_.atRandomPos()->addItem(std::make_shared<Keyboard>());
        map_.atRandomPos()->addItem(std::make_shared<Keyboard>());
        map_.atRandomPos()->addItem(std::make_shared<Keyboard>());
        map_.atRandomPos()->addItem(std::make_shared<Keyboard>());
        map_.atRandomPos()->addItem(std::make_shared<Keyboard>());
        map_.atRandomPos()->addItem(std::make_shared<Keyboard>());

        turn();
    }

Game::~Game(){};



void Game::play(){
    while (gameContinue){
        screen_.focusAtPlayer(player_);
        screen_.draw();

        std::string command;
        std::cin >> command;

        if (command == "move") move();
        else if (command == "turn") turn();
        else if(command == "look") look();
        else if(command == "take") take();
        else if(command == "drop") drop();
        else if(command == "heal") heal();
        else if(command == "use") use();
        else if(command == "upgrade") upgrade();
        else if(command == "suicide") suicide();
        else if(command == "scoreboard" || command == "score") scoreboard();
        else if (command == "exit") return;
        else screen_.drawMessage("\"" + command + "\" command doesn't exist\n");
    }
}

void Game::move(){
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
    

    std::shared_ptr<Cell> newCell = map_.at(player_->getPos()->getHPos() + di, 
                                            player_->getPos()->getWPos() + dj);
    if(!player_->isActive()){
        screen_.drawMessage("You can't go now!");
    }else if(newCell->getType() == Cell::Type::GRASS){
        player_->getPos()->removePlayer(player_);
        newCell->addPlayer(player_);
        player_->setPos(newCell);
        player_->addAP(-1);

        std::string message = "Your lacation:\n";
        message += player_->getPos()->toString();
        screen_.drawMessage(message);
    }else{
        screen_.drawMessage("You can't go there!");
    }
    
}

void Game::turn(){
    if (playersQueue_.empty())
        playersQueueInit();
    
    do{
        if(playersQueue_.empty()){
            end();
            return;
        }
        player_ = *playersQueue_.begin();
        playersQueue_.erase(playersQueue_.begin());
    }while (player_->isDead());
    
    
    screen_.focusAtPlayer(player_);
    screen_.drawMessage(player_->getName() + " turn\n");
}

void Game::look(){
    char w;
    int h;
    std::cin >> w >> h;
    int di = h - 8;
    int dj = w - 'I';
    std::string message = std::string() + "You look at " + w + std::to_string(h) + ":\n";
    try{
        message += map_.at(player_->getPos()->getHPos() + di, player_->getPos()->getWPos() + dj)->toString();
    }catch(...){
        message += "Unknown place\n";
    }
    screen_.drawMessage(message);
}

void Game::take(){
    int n;
    std::shared_ptr<Item> item;
    std::cin >> n;
    n--;
    
    try{
        item = player_->getPos()->getItems().at(n);
    }catch(...){
        screen_.drawMessage("I can't find this item!\n");
        return;
    }

    try{
        player_->addItem(item);
        player_->addAP(-1);
        player_->getPos()->removeItem(item);

        std::string message = "Your lacation:\n";
        message += player_->getPos()->toString();
        screen_.drawMessage(message);
    }catch(std::string e){
        screen_.drawMessage(e);
    }
}

void Game::drop(){
    int n;
    std::cin >> n;
    try{
        std::shared_ptr<Item> item = player_->throwItem(n-1);
        player_->getPos()->addItem(item);
        screen_.drawMessage(player_->getName() + " has dropped the " + item->getName());
    }catch(std::string e){
        screen_.drawMessage(e);
    }
}

void Game::heal(){
    try{
        player_->heal();
        screen_.drawMessage(player_->getName() + " successfully healed\n");
    }catch(std::string e){
        screen_.drawMessage(e);
    }
}

void Game::use(){
    int n;
    std::cin >> n;
    std::shared_ptr<Item> item;
    try{
        item = player_->getItem(n-1);
    }catch(...){
        screen_.drawMessage(player_->getName() + " don't have this item!");
        return;
    }
    try{
        item->use(*player_, map_, screen_);
        if(item->isBroken()) player_->removeItem(n-1);
    }catch(std::string e){
        screen_.drawMessage(e);
    }
}

void Game::upgrade(){
    std::string type;
    std::cin >> type;
    try{
        if (type == "IP" || type == "ip"){
            player_->upgrade(0);
        }else if (type == "AP" || type == "ap"){
            player_->upgrade(1);
        }else if (type == "HP" || type == "hp"){
            player_->upgrade(2);
        }else if (type == "CP" || type == "cp"){
            player_->upgrade(3);
        }else{
            screen_.drawMessage(player_->getName() + " can't upgrade " + type);
        }
    }catch(std::string e){
        screen_.drawMessage(e);
    }
}

void Game::suicide(){
    player_->die();
    screen_.drawMessage(player_->getName() + " successfully suicide");
    screen_.draw();
    system("pause");
    turn();
}

void Game::scoreboard(){
    CharMatrix data(screen_.getHeight(), screen_.getWidth());
    std::string score = "   \n";
    data.fill("Scoreboard:", 2, 33);
    for(int i = 0; i < players_.size(); i++){
        data.fill(players_.at(i)->toShortString() + " - " + std::to_string(players_.at(i)->getScore()), 4 + i, 27);
    }
    screen_.drawData(data);
    system("pause");
}

void Game::end(){
    gameContinue = false;
    CharMatrix data(screen_.getHeight(), screen_.getWidth());
    data.fill("End!", 11, 38);
    screen_.drawData(data);
    system("pause");
}



void Game::playersQueueInit(){
    playersQueue_.clear();
    for(auto player: players_){
        if (!player->isDead())
        {
            player->addScore(1);
            player->turn();
            playersQueue_.insert(player);
        }
    }       
}