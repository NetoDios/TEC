#include "Logs.h"
#include <string>
using namespace std;

/*Constructor de la clase Logs que recibe los parametros 
Esta funcion inicializa la clase Logs con los valores dados y se manda llamar la funcion para generar el Id (Ip sin puerto)
  Complejidad (sin incluir las llamadas a funciones):
    O(1): Solo construye un objeto
*/
Logs::Logs( string month , string day , string hour , string ip , string errorMsg ){
	this -> month = month;
	this -> day = day;
	this -> hour = hour;
	this -> errorMsg = errorMsg;
	this -> ip = ip;
	this -> id = crearId();
}

/**Retorna el Id 
  Complejidad :
    O(1): Solo retorna la IP sin registro
*/
string Logs::getIP(){
	return this -> id;
}

/**
Metodo de creacion de la variable Id 

Divide el contenido de la variable "ip" en dos, separandola por el caracter ":"
	Salida:
		retorna un string con el contenido de la ip sin puerto
  Complejidad :
    O(1): No se hace nunguna iteracion
*/
string Logs::crearId(){
	string id = "" , auxId = "" ;
	size_t current = this -> ip.find( ":" );
	size_t previous = 0;
	auxId = this -> ip.substr( previous, current );
	id = auxId;
	return id;
}