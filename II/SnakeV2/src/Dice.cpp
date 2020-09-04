#include "Dice.h"
#include <iostream>
#include <windows.h>
using namespace std;

Dice::Dice(){};
void Dice::One(){
    cout<<" _______\n";
    cout<<"|       |\n";
    cout<<"|   #   |\n";
    cout<<"|_______|\n";
}
void Dice::Two(){
    cout<<" _______\n";
    cout<<"| #     |\n";
    cout<<"|       |\n";
    cout<<"|_____#_|\n";
}
void Dice::Three(){
    cout<<" _______\n";
    cout<<"|     # |\n";
    cout<<"|   #   |\n";
    cout<<"|_#_____|\n";
}
void Dice::Four(){
    cout<<" _______\n";
    cout<<"| #   # |\n";
    cout<<"|       |\n";
    cout<<"|_#___#_|\n";
}
void Dice::Five(){
    cout<<" _______\n";
    cout<<"| #   # |\n";
    cout<<"|   #   |\n";
    cout<<"|_#___#_|\n";
}
void Dice::Six(){
    cout<<" _______\n";
    cout<<"| # # # |\n";
    cout<<"|       |\n";
    cout<<"|_#_#_#_|\n";
}
int Dice::roll(){
    int rolled=rand()%6+1;
    switch(rolled){
        case 1:
            One();
            break;
        case 2:
            Two();
            break;
        case 3:
            Three();
            break;
        case 4:
            Four();
            break;
        case 5:
            Five();
            break;
        case 6:
            Six();
            break;
    }
    Sleep(1000);
    return rolled;
}
