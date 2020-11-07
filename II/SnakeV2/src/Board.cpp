#include "Board.h"
#include "Console.h"
#include "Player.h"
#include "Dice.h"
#include "Tile.h"
#include "Snake.h"
#include "Ladder.h"
#include <iostream>
using namespace std;

Board::Board(int tiles,int snakes,int ladders){
    for(int i=1;i<=tiles;i++)
    {
        mainBoard[i]=new Tile(i);
    }
    int aux;
    for(int i=0;i<snakes;i++){
        do{
            aux=rand()%(tiles-4)+4;
        }
        while(!mainBoard[aux]->isFree());
        mainBoard[aux]= new Snake(aux);
    }
    for(int i=0;i<ladders;i++){
        do{
            aux=rand()%(tiles-4)+4;
        }
        while(!mainBoard[aux]->isFree());
        mainBoard[aux]=new Ladder(aux);
    }
}
void Board::printBoard(int tiles){
    cout<<"\t";
    for(int i=1;i<=tiles;i++)
    {
        if(mainBoard[i]->sizeOf()==1) cout<<"  ";
        else if(mainBoard[i]->sizeOf()==2) cout<<" ";
        cout<<mainBoard[i]->getShow()<<" ";
        if(mainBoard[i]->sizeOf()<4) cout<<" ";
        if(i%6==0 &&i!=tiles) cout<<"\n\t";
    }
    cout<<'\n';
}
Console Board::update(Player gamer, Dice die,int bSize){   ///Aun no imprime
    mainBoard[gamer.getPosition()]->setBack();
    int auxMove=die.roll();
    int rolled=auxMove;
    if(mainBoard[gamer.getPosition() + auxMove]->isSnake())
    {
        if(mainBoard[gamer.getPosition() + auxMove - 3]->isFree()) auxMove+=3;
        else auxMove=0;
    }
    else if(mainBoard[gamer.getPosition() + auxMove]->isLadder())
    {
        if(mainBoard[gamer.getPosition() + auxMove + 3]->isFree()) auxMove+=3;
        else auxMove=0;
    }
    else if(mainBoard[gamer.getPosition() + auxMove]->isPlayer()) auxMove=0;
    if(gamer.getPosition()+auxMove >bSize || gamer.getPosition()+auxMove <1) auxMove=0;
    Console log=Console(gamer.getIndex(),gamer.getPosition(),gamer.getPosition()+auxMove,rolled,mainBoard[gamer.getPosition() + auxMove]->getType());
    gamer+auxMove;
    mainBoard[gamer.getPosition()]->update(gamer);
    return log;
}
