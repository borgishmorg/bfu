#include "Arena.hpp"

#include <memory>
#include <iostream>
#include <string>

using namespace Arena;
using namespace std;

unique_ptr<Hero> getHeroByString(std::string hero){
    if(hero == "Ogre")
        return make_unique<Ogre>();
    if(hero == "Fairy")
        return make_unique<Fairy>();
    if(hero == "Vampire")
        return make_unique<Vampire>();
    if(hero == "Knight")
        return make_unique<Knight>();
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

    int initiativeHero1;
    int initiativeHero2;

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
        cout << heroType1 << " ( " << hero1->getHp() << " )"<< endl;
        cout << heroType2 << " ( " << hero2->getHp() << " )"<< endl;
        hero1->rest();
        hero2->rest();
        hero1->setEvasionType(NO_TYPE);
        hero2->setEvasionType(NO_TYPE);

        initiativeHero1 = hero1->getInitiative();
        initiativeHero2 = hero2->getInitiative();
        
        if(initiativeHero1 > 0){
            cout << "Enter " << player1 << " attack and evasion type:" << endl;
            cin >> attackPlayer1 >> evasionPlayer1;
        }
        if(initiativeHero2 > 0){
            cout << "Enter " << player2 << " attack and evasion type:" << endl;
            cin >> attackPlayer2 >> evasionPlayer2;
        }
        hero1->setEvasionType(stringToAttackType(evasionPlayer1));
        hero2->setEvasionType(stringToAttackType(evasionPlayer2));


        if(hero1->attack(*hero2, stringToAttackType(attackPlayer1)))
            cout << "Success" << endl;
        else
            cout << "Failure" << endl;
        
        if(hero2->attack(*hero1, stringToAttackType(attackPlayer2)))
            cout << "Success" << endl;
        else
            cout << "Failure" << endl;
        
        

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