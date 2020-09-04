#ifndef BOARD_H
#define BOARD_H
#include "Console.h"
#include "Player.h"
#include "Dice.h"
#include "Tile.h"

class Board
{
    public:
        Board(int,int,int);
        void printBoard(int);
        Console update(Player,Dice,int);
    protected:

    private:
        Tile *mainBoard[1000];
        int boardSize;
};

#endif // BOARD_H
