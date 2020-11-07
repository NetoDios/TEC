#ifndef GAME_H
#define GAME_H
#include "Console.h"
#include "Player.h"
#include <vector>
using namespace std;

class Game
{
    public:
        Game();
        void rules();
        string getPlayerName(int);
        bool stillPlaying();
        bool won(Player);
        void finish(vector<Console>);
        void setSize();
        void setSnakes();
        void setLadders();
        void setPlayers();
        void setTurns();
        void setGameType();
        void start();
    protected:

    private:
        int turn,maxTurn;
        int tam,serp,esca,juga;
        char type;
};

#endif // GAME_H
