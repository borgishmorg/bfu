#include "Game.hpp"

using namespace BattleRoyale;

Game::Game(const unsigned int NUMBER_OF_PLAYERS, int mapHeight, int mapWidth):
    NUMBER_OF_PLAYERS_(NUMBER_OF_PLAYERS), DANGER_PERIOD_(5), turnCounter_(0), gameContinue_(NUMBER_OF_PLAYERS > 0),
    map_(mapHeight, mapWidth), screen_(map_), 
    playersQueue_([](std::shared_ptr<Player> a, std::shared_ptr<Player> b){ return a->getStats().IP_ > b->getStats().IP_; }){
        
        for (unsigned int i = 0; i < NUMBER_OF_PLAYERS_; i++){
            players_.push_back(std::make_shared<Player>("Player " + std::to_string(i+1), map_.atRandomPos()));
            players_.back()->getPos()->addPlayer(players_.at(i));
            players_.back()->addItem(std::make_shared<Label>());
        }

        for(int i = 0; i < 50; i++){
            map_.atRandomPos()->addItem(std::make_shared<Stone>());
            map_.atRandomPos()->addItem(std::make_shared<Apple>());
        }
        for(int i = 0; i < 20; i++){
            map_.atRandomPos()->addItem(std::make_shared<Bow>());
            map_.atRandomPos()->addItem(std::make_shared<Sword>());
        }
        for(int i = 0; i < 15; i++){
            map_.atRandomPos()->addItem(std::make_shared<AK47>());
            map_.atRandomPos()->addItem(std::make_shared<PotionOfHealth>());
            map_.atRandomPos()->addItem(std::make_shared<PotionOfCheerfulness>());
        }
        for(int i = 0; i < 10; i++){
            map_.atRandomPos()->addItem(std::make_shared<ScrollOfWall>());
            map_.atRandomPos()->addItem(std::make_shared<GrenadeLauncher>());
            map_.atRandomPos()->addItem(std::make_shared<ScrollOfClumsiness>());
        }
        for(int i = 0; i < 5; i++){
            map_.atRandomPos()->addItem(std::make_shared<Label>());
            map_.atRandomPos()->addItem(std::make_shared<GPS>());
            map_.atRandomPos()->addItem(std::make_shared<SniperRifle>());
            map_.atRandomPos()->addItem(std::make_shared<Backpack>());
            map_.atRandomPos()->addItem(std::make_shared<ThirdLeg>());
        }  

        map_.atRandomPos()->addItem(std::make_shared<InfinityGauntlet>());
        map_.atRandomPos()->addItem(std::make_shared<InfinityStone>(InfinityStone::MIND));
        map_.atRandomPos()->addItem(std::make_shared<InfinityStone>(InfinityStone::POWER));
        map_.atRandomPos()->addItem(std::make_shared<InfinityStone>(InfinityStone::REALITY));
        map_.atRandomPos()->addItem(std::make_shared<InfinityStone>(InfinityStone::SOUL));
        map_.atRandomPos()->addItem(std::make_shared<InfinityStone>(InfinityStone::SPACE));
        map_.atRandomPos()->addItem(std::make_shared<InfinityStone>(InfinityStone::TIME));
        
        turn();
    }

Game::~Game(){};



void Game::play(){
    while (gameContinue_){
        std::string command;
        
        screen_.focusAtPlayer(player_);
        screen_.draw();
        if(player_->isDead()){
            screen_.drawMessage(player_->getName() + " is dead!");
            system("pause");
            turn();
            continue;
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
        else if (command == "fix") fix();
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

    try{
        pos = map_.at(player_->getPos()->getHPos() + di, 
                      player_->getPos()->getWPos() + dj);
    }catch(...){
        screen_.drawMessage(player_->getName() + " can't move " + direction);
        return;
    }

    if(!player_->isActive())
        message = player_->getName() + " can't move now!";
    else if(pos->getType() == Cell::Type::GRASS){
        player_->getPos()->removePlayer(player_);
        pos->addPlayer(player_);
        player_->setPos(pos);
        player_->takeFatigue(1);

        message = player_->getName() + " lacation:\n" + player_->getPos()->toString();
    }else
        message = player_->getName() + " can't go there!";
    
    screen_.drawMessage(message);
}

void Game::turn(){
    while (!playersQueue_.empty() && (*playersQueue_.begin())->isDead()){
        playersQueue_.erase(playersQueue_.begin());
    }
    if(playersQueue_.empty()){
        turnCounter_++;
        if(turnCounter_ % DANGER_PERIOD_ == 0){
            map_.moveWalls();
            screen_.drawMessage("Ancient danger is moving!");
            system("pause");
        } 
        playersQueueInit();
        if(playersQueue_.size() == 1){
            player_ = *playersQueue_.begin();
            screen_.focusAtPlayer(player_);
            win();
            return;
        }
    }

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
    
    try{
        std::cin >> w >> h;
        std::shared_ptr<Cell> cell = map_.at(*player_, w, h);
        message = player_->getName() + " looks at " + w + std::to_string(h) + ":\n" + cell->toString();
    }catch(std::string e){
        screen_.drawMessage(player_->getName() + " looks at: " + e);
        return;
    }
    
    screen_.drawMessage(message);
}

void Game::take(){
    std::string message;
    std::shared_ptr<Item> item;
    int n;
    
    std::cin >> n;
    
    try{
        item = player_->getPos()->getItems().at(n-1);
    }catch(...){
        screen_.drawMessage(player_->getName() + " can't find this item!\n");
        return;
    }

    try{
        player_->addItem(item);
        player_->takeFatigue(1);
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

    try{
        player_->dropItem(n-1);
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
        player_->upgrade(Player::stringToStatType(type));
    }catch(std::string e){
        screen_.drawMessage(e);
    }
}

void Game::suicide(){
    player_->die();
}

void Game::scoreboard(){
    CharMatrix data(screen_.getHeight(), screen_.getWidth());
    std::vector<std::shared_ptr<Player>> players = players_;
    sort(players.begin(), players.end(), [](std::shared_ptr<Player> a, std::shared_ptr<Player> b){ return a->getScore() > b->getScore();});

    data.fill("Scoreboard:", 2, 33);
    for(int i = 0; i < players.size(); i++)
        data.fill(players.at(i)->toShortString() + " - " + std::to_string(players.at(i)->getScore()), 4 + i, 27);

    screen_.drawData(data);
    system("pause");
}

void Game::win(){
    CharMatrix data(screen_.getHeight(), screen_.getWidth());
    
    data.fill("End!", 11, 38);
    data.fill(player_->getName() + " won!", 12, 37 - player_->getName().size()/2);
    
    screen_.drawData(data);
    system("pause");
    end();
}

void Game::end(){
    CharMatrix data(screen_.getHeight(), screen_.getWidth());
    
    scoreboard();

    data.fill("End!", 11, 38);
    gameContinue_ = false;
    
    screen_.drawData(data);
    system("pause");
}

void Game::fix(){
    screen_.fix();
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