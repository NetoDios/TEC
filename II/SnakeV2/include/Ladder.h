#ifndef LADDER_H
#define LADDER_H
#include "Tile.h"

class Ladder:public Tile
{
    public:
        Ladder(int);
    protected:

    private:
        int change;
};

#endif // LADDER_H
