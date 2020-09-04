#include "Snake.h"
#include "Tile.h"

Snake::Snake(int index):Tile(index){
    change=-3;
    indicator='S';
    logic=-1;
    original="<<";
    show="<<";
}
