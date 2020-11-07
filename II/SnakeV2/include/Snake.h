#ifndef SNAKE_H
#define SNAKE_H
#include "Tile.h"


class Snake:public Tile
{
    public:
        Snake(int);
    protected:

    private:
        int change;
};

#endif // SNAKE_H
