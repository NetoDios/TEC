#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using std::string;

class Player
{
    public:
        Player();
        Player(string,int);
        string getName();
        string getTag();
        int getPosition();
        int getIndex();
        void operator + (const int);
        void debbug();
    protected:

    private:
        string name,tag;
        int index,pos;
};

#endif // PLAYER_H
