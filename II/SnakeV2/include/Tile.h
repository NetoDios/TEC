#ifndef TILE_H
#define TILE_H
#include "Player.h"
#include <string>
using std::string;

class Tile
{
    public:
        Tile(int);
        bool isLadder();
        bool isSnake();
        bool isPlayer();
        bool isFree();
        int getLogic();
        int sizeOf();
        char getType();
        string getShow();
        void setBack();
        void update(Player);
    protected:
        int logic;
        string show,original;
        char indicator; /// 0:Disponible    -1:Snake    99:Ladder   N:Player
    private:
};

#endif // TILE_H
