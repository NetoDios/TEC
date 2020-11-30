#include <iostream>
#include "Bitacora.h"
using namespace std;
/**
La funcionalidad de este codigo es recorrer la bitacora y mete cada log (fecha e ip) a una hash table para encontrar 

29/11/2020

*/

int main(){
  Bitacora bitacora = Bitacora( "bitacora2.txt" ) ;
  string ip;
  bool seguir;
  do{
    try{
      cout << "Ingrese una ip: ";
      cin >> ip;
      cout << bitacora[ip] << endl;
    }catch( exception& e ){
      cout << e.what() << endl;
    }
    cout << "Quiere continuar [1 : 0]\n";
    cin >> seguir;
  }while(seguir);
  
  return 0;
}