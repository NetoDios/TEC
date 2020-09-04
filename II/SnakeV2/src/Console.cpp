#include "Console.h"
#include <iostream>
using namespace std;

Console::Console(int myPlayer,int myPosI,int myPosF,int myDie,char myType){
    player=myPlayer;
    positionI=myPosI;
    positionF=myPosF;
    type=myType;
    die=myDie;
}
int Console::getChange(){return positionF-positionI;}
ostream& operator<<(ostream& output,const Console& log)
{
    output<<log.player<<" ";
    output<<log.positionI<<" ";
    output<<log.die<<" ";
    output<<log.type<<" ";
    output<<log.positionF<<'\n';
    return output;
}
