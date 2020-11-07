#include "Logs.h"
#include "Bitacora.h"
#include <fstream>
#include <string>
using namespace std;

/*Constructor:
  Abre el archivo y lee los registros dentro de el y cuenta cuantas veces se repite cada IP
	Una vez que encuentra dos IPs consecutivas diferentes almacena la primera en myBST
  Entrada: string filename, nombre del archivo con extension txt
  Complejidad:
    O(N): Depende directamente de los registros del archivo
*/
Bitacora::Bitacora( string filename ){
  int cnt = 0;
  string anterior = "0";
  fstream archivo( filename );
  Logs* registro=nullptr;
  if( archivo.is_open() ) {
    string linea;
    while(getline( archivo , linea )) {
      vector<string> entrada = splitString( linea, " ");
      registro = new Logs( entrada[0] , entrada[1] , entrada[2] , entrada[3] , entrada[4] );
      if(anterior=="0"){
        anterior = registro->getIP();
      }
      if (registro->getIP() != anterior){
        this -> myBST.push(anterior, cnt);
				anterior = "0";
        cnt = 1;
      }
      else{
        anterior = registro->getIP();
        cnt++;
      }
	  delete registro;
    }
  }
}

/*Separa un registro en las 5 partes mas importantes
  Entradas: 
      string text, recibe la linea a seprar 
      string delimiter, conjunto de caracteres donde se separara el registro
  Salidas: Un vector con los 5 elementos del registro separados en variables
  Complejidad (sin incluir las llamadas a funciones):
    O(1): A pesar de parecer de orden lineal, el ciclo while solo se repite 4 veces sin importar la entrada
*/
vector<string> Bitacora::splitString( string text , string delimiter ){
    int  i = 0;
    vector<string> lines;
    size_t current = text.find( delimiter );
    size_t previous = 0;
    while( current != string::npos ){
        i += 1;
        lines.push_back( text.substr( previous , current - previous ) );
        previous = current + 1;
        current = text.find( delimiter , previous );
        if (i == 4) break;
    }
    lines.push_back( text.substr( previous , current ) );
    return lines;
}

/*Metodo de preparacion para top recursivo
	Entrada:
		int num: El numero de registros que se espera imprimir (puede recibir valores mayores a la cantidad de nodos en el BST, pero no los mostraria)
  Complejidad (sin incluir las llamadas a funciones):
    O(1): Lineal, solo llama a otro metodo
*/
void Bitacora::top( int num ){
	top(myBST.top(), num);
}

/*Metodo top recursivo
	Entrada:
		Apuntador a Node current: el nodo con el que se esta trabajando en cada nivel de recursion
		Referencia a int num: El numero de registros que se espera imprimir (puede recibir valores mayores a la cantidad de nodos en el BST, pero no los mostraria)
  Complejidad:
    Best Case: O(log(N)): Solo un valor, va hasta la derecha
	  Worst Case: O(N): Recorre todos los nodos, y los imprime
*/
void Bitacora::top( Node* current, int& num ){
	if(current){
		top(current -> right , num);
		if(num == 0) return;
		cout << current -> ip << " -> " << current->cnt << "\n";
		num--;
		if(num == 0) return;
		top(current -> left , num);
	}
}