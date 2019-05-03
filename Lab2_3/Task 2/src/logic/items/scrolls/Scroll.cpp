#include "Scroll.hpp"

using BattleRoyale::Scroll;

Scroll::Scroll(std::string name, unsigned int durability, unsigned int cost):
    Item(name, durability, cost){}

Scroll::~Scroll(){}


void Scroll::use(Player & user, Map & map, Screen & screen){
    if(!user.isActive() || user.getStats().AP_ < stats_.cost_)
        throw user.getName() + " can't use " + name_ + " now!";
    
    CharMatrix data(screen.getHeight(), screen.getWidth());
    MapScreenElement element(map, 0, 0);
    int h;
    char w;

    element.focusAtPlayer(user);
    element.draw(data);
    data.fill("Enter target position:", 12, 42);
    screen.drawData(data);
    
    std::cin >> w >> h;
    
    if(w < 'A' || 'Q' < w || h < 0 || 16 < h)
        throw user.getName() + " can't use " + name_ + " on position " + w + std::to_string(h) + "!";
    std::cout << user.getPos()->getHPos() << " " << user.getPos()->getWPos() << std::endl;
    try{
        spell(*(map.at(user.getPos()->getHPos() + h - 8, user.getPos()->getWPos() + w - 'I')), screen);
    }catch(...){
        throw user.getName() + " can't use " + name_ + " on position " + w +  std::to_string(h) +"!";
    }

    user.addAP(-stats_.cost_);
    --stats_.durability_;
}