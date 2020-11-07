#include "Tile.h"
#include <iostream>
using namespace std;

Tile::Tile(int index){
    show=to_string(index);
    original=to_string(index);
    logic=0;
    indicator='N';
}
bool Tile::isLadder(){
    if(logic==99) return true;
    return false;
}
bool Tile::isSnake(){
    if(logic==-1) return true;
    return false;
}
bool Tile::isPlayer(){
    if(logic!=0 && logic!=-1 && logic!=99) return true;
    return false;
}
bool Tile::isFree(){
    if(logic==0) return true;
    return false;
}
int Tile::getLogic(){ return logic;}
int Tile::sizeOf(){ return show.length();}
char Tile::getType(){return indicator;}
string Tile::getShow(){return show;}
void Tile::setBack(){
    show=original;
    logic=0;
}
void Tile::update(Player gamer){
    show=gamer.getTag();
    logic=gamer.getIndex();
}
