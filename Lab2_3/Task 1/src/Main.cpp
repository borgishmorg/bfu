#include "Arena.hpp"

#include <memory>
#include <iostream>
#include <string>

using namespace Arena;
using namespace std;

unique_ptr<Hero> getHeroByString(std::string hero){
    if(hero == "Ogre")
        return make_unique<Ogre>();
    throw "\""+hero+"\" hero dosn't exist";
}

void play(){
    string player1 = "Player 1";
    string player2 = "Player 2";
    string heroType1;
    string heroType2;
    string attackPlayer1;
    string evasionPlayer1;
    string attackPlayer2;
    string evasionPlayer2;

    unique_ptr<Hero> hero1;
    unique_ptr<Hero> hero2;

    selectHero1:
    try
    {
        cout << "\"" << player1 << "\" enter the name of your hero:" << endl;
        cin >> heroType1;
        hero1 = getHeroByString(heroType1);
    }
    catch(string e)
    {
        cout << e << "\nTry again." << endl;
        goto selectHero1;
    }

    selectHero2:
    try
    {
        cout << "\"" << player2 << "\" enter the name of your hero:" << endl;
        cin >> heroType2;
        hero2 = getHeroByString(heroType2);
    }
    catch(string e)
    {
        cout << e << "\nTry again." << endl;
        goto selectHero2;
    }
    

    
    while (true)
    {
        hero1->rest();
        hero2->rest();
        cin >> attackPlayer1 >> evasionPlayer1 >> attackPlayer2 >> evasionPlayer2;

        hero1->setEvasionType(stringToAttackType(evasionPlayer1));
        hero2->setEvasionType(stringToAttackType(evasionPlayer2));

        hero1->attack(*hero2, stringToAttackType(attackPlayer1));
        hero2->attack(*hero1, stringToAttackType(attackPlayer2));

        if (!hero1->isAlive() && !hero2->isAlive()){
            cout << "Friendship won" << endl;
            return;
        }
        if (hero1->isAlive() && !hero2->isAlive()){
            cout << player1 << " won" << endl;
            return;
        }
        if (!hero1->isAlive() && hero2->isAlive()){
            cout << player2 << " won" << endl;
            return;
        }
        
    }
    
}

int main(){
    play();    
    return 0;
}