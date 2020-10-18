#include "Logs.h"
#include <string>
#include <locale>
#include <fstream>
using namespace std;

/*Constructor de la clase Logs que recibe los parametros 

Esta funcion inicializa la clase Logs con los valores dados y se manda llamar la funcion para generar el Id
  Complejidad :
    O(1): Solo construye un objeto
*/
Logs::Logs( string month , string day , string hour , string ip , string errorMsg ){
    this -> month = month;
    this -> day = day;
    this -> hour = hour;
    this -> ip = ip;
    this -> errorMsg = errorMsg;
    this -> id = crearId();
}

/**
Metodo de impresion del rango de fecha buscado en un archivo
  Entrada:
    ofstream &myFile, una referencia al documento donde se debe immprimir la informacion
  Complejidad :
    O(1): Imprime variables fijas, sin iterar
*/
void Logs::print( ofstream& myFile ){
  myFile << this -> month << " " << this -> day << '\t';
  myFile << this -> hour << '\t';
  myFile << this -> ip << '\t';
  myFile << this -> errorMsg << ' ';
  myFile << '\n';
}

/**
Metodo de impresion del rango de fecha buscado en consola
  Complejidad :
    O(1): Imprime variables fijas, sin iterar
*/
void Logs::print(){
  cout << this -> ip << ' ';
  cout << this -> month << " " << this -> day << ' ';
  cout << this -> hour << ' ';
  cout << this -> errorMsg << ' ';
  cout << '\n';
}

/**Retorna el Id
  Complejidad :
    O(1): Solo retorna un valor
*/
string Logs::getId(){
    return this -> id;
}



/**
Metodo de creacion de la variable Id 

Aqui se toman los valores string de Month Day y Hour se meten
a funciones equivalentes para convertirlos en numero enteros 
y equivalentes para nuestra funcion y luego al estar en string
concatenarlos para finalmente hacerlos int y regresar ese valor.
  Complegidad :
    O(1): Todo se hace en un solo paso
*/
/**
La funcion hour id toma el valor inicial de la variable "hour", luego busca dentro del string los ":" y utiliza una variable auxiliar "previous" para saber por donde ya ha pasado. La condicion del While es que la variable "current" sea diferente a la longitud de string.
Dentro del While 
  Complejidad :
    O(1): El while siempre se repite 3 veces
*/
string Logs::crearId(){
  string id="",auxId="";
  size_t current = ip.find( "." );
  size_t previous = 0;
  while( current != string::npos ){ //108.57.27.85:5491
    auxId = this -> ip.substr( previous, current - previous );
    previous = current + 1;
    current = ip.find( ".", previous );
    if (auxId.size()==2)
      auxId="0"+auxId;
    else if (auxId.size()==1)
      auxId="00"+auxId;
    id+=auxId;
  }
  auxId= ip.substr( previous, current );
  if (auxId.size()==6)
    auxId="0"+auxId;
  id +=auxId;
  return id;
}