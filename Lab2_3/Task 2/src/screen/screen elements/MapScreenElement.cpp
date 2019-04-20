#include "MapScreenElement.hpp"

using BattleRoyale::MapScreenElement;

MapScreenElement::MapScreenElement(unsigned int hPos, unsigned int wPos):
    ScreenElement(hPos, wPos, 24, 24){
        data_.fill(" +--------------------+ ", 0);
        data_.fill("++                    ++", 1);
        data_.fill("|   ABCDEFGHIJKLMNOPR  |", 2);
        data_.fill("|  +-----------------+ |", 3);
        data_.fill("| 0|                 | |", 4);
        data_.fill("| 1|                 | |", 5);
        data_.fill("| 2|                 | |", 6);
        data_.fill("| 3|                 | |", 7);
        data_.fill("| 4|                 | |", 8);
        data_.fill("| 5|                 | |", 9);
        data_.fill("| 6|                 | |", 10);
        data_.fill("| 7|                 | |", 11);
        data_.fill("| 8|                 | |", 12);
        data_.fill("| 9|                 | |", 13);
        data_.fill("|10|                 | |", 14);
        data_.fill("|11|                 | |", 15);
        data_.fill("|12|                 | |", 16);
        data_.fill("|13|                 | |", 17);
        data_.fill("|14|                 | |", 18);
        data_.fill("|15|                 | |", 19);
        data_.fill("|16|                 | |", 20);
        data_.fill("|  +-----------------+ |", 21);
        data_.fill("++                    ++", 22);
        data_.fill(" +--------------------+ ", 23);
    };

MapScreenElement::~MapScreenElement(){};

void MapScreenElement::update(){

}