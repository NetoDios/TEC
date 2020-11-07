#ifndef CONSOLE_H
#define CONSOLE_H
#include "Player.h"
#include <iostream>
using namespace std;

class Console
{
    public:
        Console(int,int,int,int,char);
        int getChange();
        friend ostream& operator<<(ostream&, const Console&);
    private:
        int player;
        int positionI;
        int die;
        char type;
        int positionF;
};

#endif // CONSOLE_H
