#include "Game.hpp"

using namespace BattleRoyale;

Game::Game(const unsigned int NUMBER_OF_PLAYERS):
    NUMBER_OF_PLAYERS_(NUMBER_OF_PLAYERS), gameContinue(NUMBER_OF_PLAYERS > 0),
    map_(), screen_(map_), 
    playersQueue_([](std::shared_ptr<Player> a, std::shared_ptr<Player> b){ return a->getStats().IP_ > b->getStats().IP_; }){
        
        for (unsigned int i = 0; i < NUMBER_OF_PLAYERS_; i++){
            players_.push_back(std::make_shared<Player>("Player " + std::to_string(i+1), map_.atRandomPos()));
            players_.back()->getPos()->addPlayer(players_.at(i));
            players_.back()->addItem(std::make_shared<Label>());
        }

        for(int i = 0; i < 2; i++) 
            map_.atRandomPos()->addItem(std::make_shared<Label>());
        for(int i = 0; i < 5; i++)
            map_.atRandomPos()->addItem(std::make_shared<Bow>());
        for(int i = 0; i < 5; i++)
            map_.atRandomPos()->addItem(std::make_shared<Sword>());
        for(int i = 0; i < 3; i++)
            map_.atRandomPos()->addItem(std::make_shared<AK47>());
        for(int i = 0; i < 3; i++)
            map_.atRandomPos()->addItem(std::make_shared<GrenadeLauncher>());
        for(int i = 0; i < 1; i++)
            map_.atRandomPos()->addItem(std::make_shared<SniperRifle>());

        turn();
    }

Game::~Game(){};



void Game::play(){
    while (gameContinue){
        std::string command;
        
        screen_.focusAtPlayer(player_);
        screen_.draw();
        if(player_->isDead()){
            screen_.drawMessage(player_->getName() + " is dead!");
            system("pause");
            turn();
        } 

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
    std::shared_ptr<Cell> pos;
    std::string direction;
    std::string message;
    int di = 0, dj = 0;
    
    std::cin >> direction;

    if(direction == "up" || direction == "u") di = -1;
    else if(direction == "down" || direction == "d") di = 1;
    else if(direction == "left" || direction == "l") dj = -1;
    else if(direction == "right" || direction == "r") dj = 1;
    else{
        screen_.drawMessage(player_->getName() + " can't move " + direction);
        return;
    }

    pos = map_.at(player_->getPos()->getHPos() + di, 
                  player_->getPos()->getWPos() + dj);

    if(!player_->isActive())
        message = player_->getName() + " can't move now!";
    else if(pos->getType() == Cell::Type::GRASS){
        player_->getPos()->removePlayer(player_);
        pos->addPlayer(player_);
        player_->setPos(pos);
        player_->addAP(-1);

        message = player_->getName() + " lacation:\n" + player_->getPos()->toString();
    }else
        message = player_->getName() + " can't go there!";
    
    screen_.drawMessage(message);
}

void Game::turn(){
    while (!playersQueue_.empty() && (*playersQueue_.begin())->isDead()){
        playersQueue_.erase(playersQueue_.begin());
    }
    if(playersQueue_.empty()) playersQueueInit();
    if(playersQueue_.empty()){    
        end();
        return;
    }

    player_ = *playersQueue_.begin();
    playersQueue_.erase(playersQueue_.begin());

    screen_.focusAtPlayer(player_);
    screen_.drawMessage(player_->getName() + " turn\n");
}

void Game::look(){
    std::string message;
    char w;
    int h;
    int di, dj;

    std::cin >> w >> h;

    if(w < 'A' || w > 'Q' || h < 0 || h > 16){
        screen_.drawMessage(player_->getName() + " look at: Unknown place");
        return;
    }
    
    di = h - 8;
    dj = w - 'I';
    message = player_->getName() + " look at: ";
    
    try{
        message += w + std::to_string(h) + "\n"; 
        message += map_.at(player_->getPos()->getHPos() + di,
                           player_->getPos()->getWPos() + dj)->toString();
    }catch(...){
        message += "Unknown place";
    }
    
    screen_.drawMessage(message);
}

void Game::take(){
    std::string message;
    std::shared_ptr<Item> item;
    int n;
    
    std::cin >> n;
    --n;
    
    try{
        item = player_->getPos()->getItems().at(n);
    }catch(...){
        screen_.drawMessage(player_->getName() + " can't find this item!\n");
        return;
    }

    try{
        player_->addItem(item);
        player_->addAP(-1);
        player_->getPos()->removeItem(item);

        message = player_->getName() + " lacation:\n" + player_->getPos()->toString(); 
    }catch(std::string e){
        screen_.drawMessage(e);
        return;
    }

    screen_.drawMessage(message);
}

void Game::drop(){
    int n;

    std::cin >> n;
    --n;

    try{
        player_->dropItem(n);
        screen_.drawMessage(player_->getName() + " has dropped the item");
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
    std::shared_ptr<Item> item;
    int n;

    std::cin >> n;
    --n;
    
    try{
        item = player_->getItem(n);
    }catch(...){
        screen_.drawMessage(player_->getName() + " don't have this item!");
        return;
    }
    try{
        item->use(*player_, map_, screen_);
        if(item->isBroken()) player_->removeItem(n);
    }catch(std::string e){
        screen_.drawMessage(e);
    }
}

void Game::upgrade(){
    std::string type;

    std::cin >> type;
    
    try{
        if (type == "IP" || type == "ip") player_->upgrade(0);
        else if (type == "AP" || type == "ap") player_->upgrade(1);
        else if (type == "HP" || type == "hp") player_->upgrade(2);
        else if (type == "CP" || type == "cp") player_->upgrade(3);
        else screen_.drawMessage(player_->getName() + " can't upgrade " + type);
    }catch(std::string e){
        screen_.drawMessage(e);
    }
}

void Game::suicide(){
    player_->die();

    screen_.drawMessage(player_->getName() + " successfully suicide");
    system("pause");

    turn();
}

void Game::scoreboard(){
    CharMatrix data(screen_.getHeight(), screen_.getWidth());
    
    data.fill("Scoreboard:", 2, 33);
    for(int i = 0; i < players_.size(); i++)
        data.fill(players_.at(i)->toShortString() + " - " + std::to_string(players_.at(i)->getScore()), 4 + i, 27);

    screen_.drawData(data);
    system("pause");
}

void Game::end(){
    CharMatrix data(screen_.getHeight(), screen_.getWidth());
    
    data.fill("End!", 11, 38);
    gameContinue = false;
    
    screen_.drawData(data);
    system("pause");
}



void Game::playersQueueInit(){
    playersQueue_.clear();
    
    for(auto player: players_)
        if (!(player->isDead())){
            player->addScore(1);
            player->turn();
            playersQueue_.insert(player);
        }
}