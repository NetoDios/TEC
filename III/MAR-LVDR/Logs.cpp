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
Metodo de creacion de la variable Id 

Aqui se toman los valores string de Month Day y Hour se meten
a funciones equivalentes para convertirlos en numero enteros 
y equivalentes para nuestra funcion y luego al estar en string
concatenarlos para finalmente hacerlos int y regresar ese valor.
  Complegidad :
    O(1): Todo se hace en un solo paso
*/
int Logs::crearId(){
    string idAux = "";
    idAux = monthId( this -> month ) + dayId( this -> day ) + hourId();
    return stoi( idAux );
}

/**
Metodo de impresion del rango de fecha buscado en un archivo
  Entrada:
    ofstream &myFile, una referencia al documento donde se debe immprimir la informacion
  Complejidad :
    O(1): Imprime variables fijas, sin iterar
*/
void Logs::print( ofstream& myFile ){
    myFile << this -> month << " " << this -> day << ' ';
    myFile << this -> hour << ' ';
    myFile << this -> ip << ' ';
    myFile << this -> errorMsg << ' ';
    myFile << '\n';
}

/**
Metodo de impresion del rango de fecha buscado en consola
  Complejidad :
    O(1): Imprime variables fijas, sin iterar
*/
void Logs::print(){
    cout << this -> month << " " << this -> day << ' ';
    cout << this -> hour << ' ';
    cout << this -> ip << ' ';
    cout << this -> errorMsg << ' ';
    cout << '\n';
}

/**Retorna el Id
  Complejidad :
    O(1): Solo retorna un valor
*/
int Logs::getId(){
    return this -> id;
}

/**
Metodo de asignacion de valor al mes 

Asignando un valor a cada mes  y con esto generar monthId para posteriormente asignar el id
  Complejidad :
    O(1): Despues de entrar a una condicional evita las demas y se retorna
*/
string Logs::monthId( string month ){
    string monthId = "0";
    if(month == "Jan") monthId = "1";
    else if(month == "Feb") monthId = "2";
    else if(month == "Mar") monthId = "3";
    else if(month == "Apr") monthId = "4";
    else if(month == "May") monthId = "5";
    else if(month == "Jun") monthId = "6";
    else if(month == "Jul") monthId = "7";
    else if(month == "Aug") monthId = "8";
    else if(month == "Sep") monthId = "9";
    else if(month == "Oct") monthId = "10";
    else if(month == "Nov") monthId = "11";
    else if(month == "Dec") monthId = "12";
    return monthId;
}

/**
Metodo de conversion del dia de string a numero

Si la longitud del dia es de 1 se agrega un 0 para sumar correctamente dayId
  Complejidad :
    O(1): No hay nada que se repita o dependa de algun iterador
*/
string Logs::dayId( string dia ){
    string dayId = "";
    if( dia.size() == 1 ){
        dayId = "0";
    }
    dayId += dia;
    return dayId;
}

/**
La funcion hour id toma el valor inicial de la variable "hour", luego busca dentro del string los ":" y utiliza una variable auxiliar "previous" para saber por donde ya ha pasado. La condicion del While es que la variable "current" sea diferente a la longitud de string.
Dentro del While 
  Complejidad :
    O(1): El while siempre se repite 3 veces
*/
string Logs::hourId(){
  string hourId;
  size_t current = hour.find( ":" );
  size_t previous = 0;
  while( current != string::npos ){
    hourId += this -> hour.substr( previous, current - previous );
    previous = current + 1;
    current = hour.find( ":", previous );
  }
  hourId += hour.substr( previous, current );
  return hourId;
}