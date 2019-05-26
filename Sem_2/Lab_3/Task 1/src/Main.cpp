#include "Arena.hpp"

#include <memory>
#include <iostream>
#include <string>

using namespace Arena;
using namespace std;

int roundCounter = 1;

string player1 = "Player 1";
string player2 = "Player 2";

unique_ptr<Hero> hero1;
unique_ptr<Hero> hero2;

unique_ptr<Hero> inputHero(){
    string hero;
    while(true){
        cout << "Enter the name of your hero:" << endl;
        cin >> hero;
        if(hero == "Ogre")
            return make_unique<Ogre>();
        if(hero == "Fairy")
            return make_unique<Fairy>();
        if(hero == "Vampire")
            return make_unique<Vampire>();
        if(hero == "Knight")
            return make_unique<Knight>();
        if(hero == "Thanos")
            return make_unique<Thanos>();
        cout << "\"" << hero << "\" hero dosn't exist\nTry again." << endl;
    }
}

void init(){
    cout << "\"" << player1 << "\""<< endl; 
    hero1 = inputHero();
    cout << "\"" << player2 << "\""<< endl; 
    hero2 = inputHero();
}

bool isEnd(){
    if (!hero1->isAlive() && !hero2->isAlive()){
        cout << "\nFriendship won" << endl;
        return true;
    }
    if (hero1->isAlive() && !hero2->isAlive()){
        cout << "\n" << player1 << " won" << endl;
        return true;
    }
    if (!hero1->isAlive() && hero2->isAlive()){
        cout << "\n" << player2 << " won" << endl;
        return true;
    }
    return false;
}

bool play(){
    string attackPlayer1;
    string attackPlayer2;
    string evasionPlayer1;
    string evasionPlayer2;

    cout << "=========================== Round: " << roundCounter << "===========================" << endl;
    cout << hero1->getName() << " ( " << *hero1 << " )"<< endl;
    cout << hero2->getName() << " ( " << *hero2 << " )"<< endl;

    if(hero1->getInitiative() > 0){
        cout << "Enter " << player1 << " attack and evasion type:" << endl;
        cin >> attackPlayer1 >> evasionPlayer1;
    }
    if(hero2->getInitiative() > 0){
        cout << "Enter " << player2 << " attack and evasion type:" << endl;
        cin >> attackPlayer2 >> evasionPlayer2;
    }
    hero1->setEvasionType(stringToAttackType(evasionPlayer1));
    hero2->setEvasionType(stringToAttackType(evasionPlayer2));

    cout << "\tLog:\n";

    if(hero1->attack(*hero2, stringToAttackType(attackPlayer1)))
        cout << "Success" << endl;
    else
        cout << "Failure" << endl;
    
    if(hero2->attack(*hero1, stringToAttackType(attackPlayer2)))
        cout << "Success" << endl;
    else
        cout << "Failure" << endl;
    
    hero1->rest();
    hero2->rest();

    return !isEnd();
}

int main(){
    init();
    while(play()) ++roundCounter;    
    return 0;
}