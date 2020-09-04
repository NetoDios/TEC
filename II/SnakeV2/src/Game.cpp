#include "Game.h"
#include "Board.h"
#include "Console.h"
#include "Player.h"
#include "Dice.h"
#include "Tile.h"
#include "Snake.h"
#include "Ladder.h"
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <windows.h>
using namespace std;

Game::Game(){
    turn=0;
};
void Game::rules(){
    system("CLS");
    cout<<"The game is simple, you'll each take turns to roll the die\n";
    cout<<"if the square is already taken you won't move.\n\n";
    cout<<"Everyone starts in the first square, there are three types\n";
    cout<<"of squares:\n";
    cout<<"\tSimple squares (does nothing)\n";
    cout<<"\tLadders (boosts you 3 squares) they have this sign  >>\n";
    cout<<"\tSnakes (backs off 3 squares) they have this sign  <<\n\n";
    cout<<"Press C to continue next turn, or E to end the game:";
    return;
}
string Game::getPlayerName(int index){
    cout<<"Player "<<index<<endl;
    cout<<"Enter the player's name: ";
    string auxName;
    cin>>auxName;
    while(auxName.length()<4){
        cout<<"Names must be at least 4 characters long and no space\n";
        cout<<"Enter the player's name: ";
        cin>>auxName;
    }
    return auxName;
}
bool Game::stillPlaying(){
    char check='C';
    if(toupper(type)=='M') cin>>check;
    while(toupper(check)!='C' && toupper(check)!='E')
    {
        cout<<"Invalid option, please press C to continue next turn or E to end the game\n";
        cin>>check;
    }
    if(toupper(check)=='C') return true;
    else {
        system("CLS");
        cout<<"Thanks for playing!!!\n";
        return false;
    }
}
bool Game::won(Player gamer){
    if(gamer.getPosition()!=tam) return false;
    system("CLS");
    cout<<gamer.getName()<<" won this round\n";
    return true;
}
void Game::finish(vector<Console>logs){
    cout<<"-- GAME OVER --\n";
    for(int i=0;i<(int)logs.size();i++)
    {
        cout<<i+1<<" "<<logs[i];
    }
}
void Game::setSize(){
    cout<<"Define the size of the board: ";
    cin>>tam;
    while(tam<15 || tam>999){
        if(tam>999)cout<<"Invalid input, the board can't be larger than 999 tiles\n";
        if(tam<15)cout<<"Invalid input, the board can't be shorter than 10 tiles\n";
        cout<<"Pleas enter a valid number: ";
        cin>>tam;
    }
}
void Game::setSnakes(){
    cout<<"Define the number of snakes in the board: ";
    cin>>serp;
    int auxM=int(tam/4);
    int auxm=max(3,auxM-6);
    while(serp<auxm || serp>auxM){
        if(serp>auxM)cout<<"Invalid input, the maximum snakes in the board is "<<auxM<<"\n";
        if(serp<auxm)cout<<"Invalid input, the minimum snakes in the board is "<<auxm<<"\n";
        cout<<"Pleas enter a valid number: ";
        cin>>serp;
    }
}
void Game::setLadders(){
    cout<<"Define the number of ladders in the board: ";
    cin>>esca;
    int auxM=int(tam/4);
    int auxm=max(3,auxM-6);
    while(serp<auxm || serp>auxM){
        if(serp>auxM)cout<<"Invalid input, the maximum ladders in the board is "<<auxM<<"\n";
        if(serp<auxm)cout<<"Invalid input, the minimum ladders in the board is "<<auxm<<"\n";
        cout<<"Pleas enter a valid number: ";
        cin>>esca;
    }
}
void Game::setPlayers(){
    cout<<"Indicate the number of players: ";
    cin>>juga;
    while(juga<2 || juga>98){
        if(juga>98)cout<<"Invalid input, the maximum number of players is 98\n";
        if(juga<2)cout<<"Invalid input, the minimum number of players is 2\n";
        cout<<"Pleas enter a valid number: ";
        cin>>juga;
    }
}
void Game::setTurns(){
    cout<<"Indicate the maximum number of turns for each player in the game: ";
    cin>>maxTurn;
    while(juga<2 || juga>99){
        if(juga>30)cout<<"Invalid input, each player can only have 30 turns\n";
        if(juga<2)cout<<"Invalid input, the minimum number of players is 2\n";
        cout<<"Pleas enter a valid number: ";
        cin>>maxTurn;
    }
    maxTurn*=juga;
}
void Game::setGameType(){
    cout<<"Indicate the game type [A = Automatic] [M = Manual]: ";
    cin>>type;
    while(toupper(type)!='A' && toupper(type)!='M'){
        cout<<"Invalid input\n\t[A = Automatic] [M = Manual]: ";
        cin>>type;
    }
}
void Game::start(){
    srand(time(NULL));
    setPlayers();
    vector<Player> players;
    for(int i=1;i<=juga;i++) players.push_back(Player(getPlayerName(i),i));
    vector<Console>logs;
    setSize();
    setSnakes();
    setLadders();
    setTurns();
    setGameType();
    Board myBoard=Board(tam,serp,esca);
    Dice myDie=Dice();
    rules();
    while(stillPlaying()&&turn<maxTurn)
    {
        system("CLS");
        cout<<players[turn%juga].getName()<<endl;
        logs.push_back(myBoard.update(players[turn%juga],myDie,tam));
        players[turn%juga]+(logs.back().getChange());
        if(won(players[turn%juga])) break;
        myBoard.printBoard(tam);
        turn=(turn+1);
        Sleep(1000);
    }
    finish(logs);
}
