#include "Projectile.hpp"
#include "Volley.hpp"
#include "VolleyQueue.hpp"
#include "Ship.hpp"
#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <chrono>
#include <cstdlib>
#include <string>

using namespace std;

int shipCount = 5;
int volleysCount = 20;

bool finish = false;

const int MAX_DAMAGE = 600;

VolleyQueue volleyQueue;

void print(string s){
    static mutex m_cout;
    m_cout.lock();
    cout << s << endl;
    m_cout.unlock();
}

void enemy(){
    this_thread::sleep_for(chrono::seconds(1));

    while(volleysCount--){
        Volley volley;
        print("\nEnemy attack!!!");
        int cnt = rand()%7 + 1;
        while(cnt--)
            volley.emplace_back
            (
                rand()%MAX_DAMAGE + 1,
                rand()%shipCount + 1,
                static_cast<ShipSystemType>(rand()%3 + 1),
                static_cast<ProjectileType>(rand()%2 + 1)
            );
        volleyQueue.push(volley);
        this_thread::sleep_for(chrono::milliseconds(1));
    }
    finish = true;
    volleyQueue.cv.notify_all();
}


Ship ships[100];

void ship(int shipNumber){
    static mutex m_ship;

    Ship& ship = ships[shipNumber];

    print("Ship " + to_string(shipNumber) + " " + ship.toString());

    while(!finish){
        unique_lock<mutex> lock(m_ship);
        volleyQueue.cv.wait(lock, [shipNumber](){return volleyQueue.haveProjectile(shipNumber) || finish;});
        
        if(finish)
            break;
        
        Projectile p = volleyQueue.getProjectile(shipNumber);
        ship.takeDamage(p);
        print("Ship " + to_string(shipNumber) + " " + ship.toString());
    }
}


int main(){
    vector<thread> ths;

    print("Earth Fleet:");
    ths.emplace_back(enemy);
    for(int i = 1; i <= shipCount; i++)
        ths.emplace_back(ship, i);

    for(auto & t: ths)
        t.join();
    
    print("\nEarth Fleet Now:");
    for(int i = 1; i <= shipCount; i++)
        print("Ship " + to_string(i) + " " + ships[i].toString());

    return 0;
}
/*
Earth Fleet:
Ship 1 (ENG:1000/1000 WEA:300/300 BAR:100/100) Debuffs: 0 0 0
Ship 3 (ENG:1000/1000 WEA:300/300 BAR:100/100) Debuffs: 0 0 0
Ship 4 (ENG:1000/1000 WEA:300/300 BAR:100/100) Debuffs: 0 0 0
Ship 2 (ENG:1000/1000 WEA:300/300 BAR:100/100) Debuffs: 0 0 0
Ship 5 (ENG:1000/1000 WEA:300/300 BAR:100/100) Debuffs: 0 0 0

...
Some epic battle
...

Earth Fleet Now:
Ship 1 (ENG:288/1000 WEA:0/300 BAR:0/100) Debuffs: 0 1 1
Ship 2 (DESTROYED)
Ship 3 (ENG:555/1000 WEA:40/300 BAR:0/100) Debuffs: 0 0 1
Ship 4 (ENG:375/1000 WEA:127/300 BAR:0/100) Debuffs: 0 0 1
Ship 5 (ENG:376/1000 WEA:300/300 BAR:45/100) Debuffs: 1 0 0
*/