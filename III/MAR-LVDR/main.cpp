#include <iostream>
#include <fstream>
#include <vector>
#include "Logs.h"
#include "DoubleLinkedList.h"
#include "Bitacora.h"
using namespace std;
/**
La funcionalidad de este codigo es hacer busquedas por rangos de fechas en una bitacora desordenada de logins de diversos usuarios en un archivo txt, ingresando el rango que se desea ordenar y resultando un archivo ordenado de dicho rango (con ayuda de algoritmos de ordenamiento y busqueda).


  13/09/2020
*/
// First IP: Jun 1
// Last IP: Oct 30


int main(){
  string myIp, continuar = "si";
  Bitacora* bitacora = new Bitacora( "bitacora.txt" );
  bitacora -> sortByIP();
  bitacora -> print();
  int i = 0;
  do{
    cout << "Ingrese la ip de inicio (Formato: ###.###.###.##:####)\n";
    cin >> myIp;
    Logs ipID1( "N/A" , "N/A" , "N/A" , myIp , "N/A" );
    cout << "Ingrese la ip final (Formato: ###.###.###.##:####)\n";
    cin >> myIp;
    Logs ipID2( "N/A" , "N/A" , "N/A" , myIp , "N/A" );
    if( ipID1.getId() <= ipID2.getId() ){
      i++;
      bitacora -> printRange( ipID1.getId() ,  ipID2.getId() , i );
      cout << "\n¿Desea continuar? <si/no>\n"; 
      cin >> continuar ;
    }
    else cout << "entradas invalidas, vuelve a intentarlo \n";
  }while(continuar == "si" || continuar == "Si" || continuar == "sI" || continuar == "SI");
  return 0;
}