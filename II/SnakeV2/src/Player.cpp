#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(){}
Player::Player(string _name,int inx){
    name=_name;
    tag=name.substr(0,4);
    index=inx;
    pos=1;
}
string Player::getName(){return name;}
string Player::getTag(){return tag;}
int Player::getPosition(){return pos;}
int Player::getIndex(){return index;}
void Player::operator + (int change){pos+=change;}
void Player::debbug(){
    cout<<"NAME="<<name<<endl;
    cout<<"TAG="<<tag<<endl;
    cout<<"INDEX="<<index<<endl;
    cout<<"POSITION="<<pos<<endl;
}
