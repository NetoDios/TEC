#include <iostream>
#include <fstream>
#include <vector>
#include "Logs.h"
#include "Bitacora.h"
using namespace std;
/**
La funcionalidad de este codigo es hacer busquedas por rangos de fechas en una bitacora desordenada de logins de diversos usuarios en un archivo txt, ingresando el rango que se desea ordenar y resultando un archivo ordenado de dicho rango (con ayuda de algoritmos de ordenamiento y busqueda).


  13/09/2020
*/
// First date: Jun 1
// Last date: Oct 30


int main(){
  string mes , dia , continuar = "si";
  int endingIndex;
  Bitacora* bitacora = new Bitacora( "bitacora.txt" );
  bitacora -> sortByDate();
  bitacora -> print();
  do{
    cout << "Ingrese la fecha de inicio (Formato: MMM DD)\n";
    cin >> mes >> dia;
    Logs dateId1( mes , dia , "000000" , "N/A" , "N/A" );
    cout << "Ingrese la fecha de final (Formato: MMM DD)\n";
    cin >> mes >> dia;
    Logs dateId2( mes , dia , "235959" , "N/A" , "N/A" );
    if( dateId1.getId() <= dateId2.getId() ){
      bitacora -> printRange( dateId1.getId() ,  dateId2.getId() );
      cout << "\n¿Desea continuar? <si/no>\n"; 
      cin >> continuar ;
    }
    else cout << "entradas invalidas, vuelve a intentarlo \n";
  }while(continuar == "si" || continuar == "Si" || continuar == "sI" || continuar == "SI");
  return 0;
}