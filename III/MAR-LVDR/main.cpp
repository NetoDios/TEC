#include <iostream>
#include "Bitacora.h"
using namespace std;
/**
La funcionalidad de este codigo es encontrar las 5 direcciones de ip más repetidas (sin considerar el puerto) partiendo de los registros del archivo bitacora (los cuales estan previamente ordenados por ip); para lo cual se hace dentro de una estructura de Binary Search Tree, tomando los valores posicionados mas a la derecha.


  02/11/2020
*/

int main(){
  Bitacora* bitacora = new Bitacora( "bitacora.txt" ) ;
  bitacora -> top(5) ;
  return 0;
}