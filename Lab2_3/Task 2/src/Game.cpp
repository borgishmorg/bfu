#include "Game.hpp"

using namespace BattleRoyale;

Game::Game(const unsigned int NUMBER_OF_PLAYERS):
    NUMBER_OF_PLAYERS_(NUMBER_OF_PLAYERS), map_(), screen_(map_), 
    playersQueue_([](std::shared_ptr<Player> a, std::shared_ptr<Player> b){ return a->getIP() > b->getIP(); }){
        for (unsigned int i = 0; i < NUMBER_OF_PLAYERS_; i++){
            players_.push_back(std::make_shared<Player>("Player " + std::to_string(i+1), map_.at(2*i+1, 2*i+1)));
            map_.at(2*i+1, 2*i+1)->addPlayer(players_.at(i));
        }
            
        map_.at(2, 3)->addItem(std::make_shared<Keyboard>());
        map_.at(2, 3)->addItem(std::make_shared<Keyboard>());
        map_.at(2, 3)->addItem(std::make_shared<Keyboard>());
        map_.at(1, 2)->addItem(std::make_shared<Keyboard>());
        map_.at(1, 2)->addItem(std::make_shared<Keyboard>());
        map_.at(1, 2)->addItem(std::make_shared<Keyboard>());

        turn();
    }

Game::~Game(){};



void Game::play(){
    std::string command;
    screen_.focusAtPlayer(player_);
    
    while (1){
        screen_.update();
        screen_.draw();

        std::cin >> command;

        if (command == "move") move();
        else if (command == "turn") turn();
        else if(command == "look") look();
        else if(command == "take") take();
        else if(command == "heal") heal();
        else if(command == "scoreboard" || command == "score") scoreboard();
        else if (command == "exit") return;
        else screen_.showMessage("\"" + command + "\" command doesn't exist\n");
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
        screen_.showMessage("You can't go now!");
    }else if(newCell->getType() == GRASS){
        player_->getPos()->removePlayer(player_);
        newCell->addPlayer(player_);
        player_->setPos(newCell);
        player_->addAP(-1);

        std::string message = "Your lacation:\n";
        message += player_->getPos()->toString();
        screen_.showMessage(message);
    }else{
        screen_.showMessage("You can't go there!");
    }
    
}

void Game::turn(){
    if (playersQueue_.empty()){
        playersQueueInit();
    }
    player_ = *playersQueue_.begin();
    playersQueue_.erase(playersQueue_.begin());
    screen_.focusAtPlayer(player_);
    screen_.showMessage("\"" + player_->getName() + "\" turn\n");
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
    screen_.showMessage(message);
}

void Game::take(){
    int n;
    std::shared_ptr<Item> item;
    std::cin >> n;
    n--;
    
    try{
        item = player_->getPos()->getItems().at(n);
    }catch(...){
        screen_.showMessage("I can't find this item!\n");
        return;
    }

    try{
        player_->addItem(item);
        player_->addAP(-1);
        player_->getPos()->removeItem(item);

        std::string message = "Your lacation:\n";
        message += player_->getPos()->toString();
        screen_.showMessage(message);
    }catch(std::string e){
        screen_.showMessage(e);
    }
}

void Game::heal(){
    try{
        player_->heal();
        screen_.showMessage(player_->getName() + " successfully healed\n");
    }catch(std::string e){
        screen_.showMessage(e);
    }
}

void Game::scoreboard(){
    CharMatrix data(screen_.HEIGHT, screen_.WEIGHT);
    std::string score = "   \n";
    data.fill("Scoreboard:", 2, 33);
    for(int i = 0; i < players_.size(); i++){
        data.fill(players_.at(i)->getName() + " " + players_.at(i)->getHPBar(), 4 + i, 30);
    }
    screen_.showData(data);
    screen_.draw();
    system("pause");
}



void Game::playersQueueInit(){
    playersQueue_.clear();
    for(auto player: players_){
        player->turn();
        playersQueue_.insert(player);
    }       
}