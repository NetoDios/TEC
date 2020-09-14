#include "Logs.h"
#include "Bitacora.h"
#include <string>
using namespace std;

/*Constructor:
  Abre el archivo y lee los registros dentro de el para almacenarlos en myLogs
  Entrada: string filename, nombre del archivo con extension txt
  Complejidad:
    O(N): Depende directamente de los registros del archivo
*/
Bitacora::Bitacora( string filename ){
    fstream archivo( filename );
    if( archivo.is_open() ) {
        string linea;
        while(getline( archivo , linea )) {
            vector<string> entrada = splitString( linea, " " );
            Logs* registro = new Logs( entrada[0] , entrada[1] , entrada[2] , entrada[3] , entrada[4] );
            this -> myLogs.push_back( registro );
        }
    }
}

/*Separa un registro en las 5 partes mas importantes
  Entradas: 
      string text, recibe la linea a seprar 
      string delimiter, conjunto de caracteres donde se separara el registro
  Salidas: un vector con los 5 elementos del registro separados en variables
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

/*Metodo de impresion de Bitacora Ordenada en un archivo txt
  Llama al metodo print de la clase Logs
  Complejidad (sin incluir las llamadas a funciones):
    O(N): Al imprimir todos los registros debe iterarlos a todos
*/
void Bitacora::print(){
    ofstream myFile;
    myFile.open ( "bitacoraOrdenada.txt" );
    for(int i = 0; i < this -> myLogs.size() ; i++)
        this -> myLogs[i] -> print( myFile );
    myFile.close();
}

/* Metodo que imprime en orden descendiente todos los registros dentro del rango para lo que utiliza los valores retornados por busquedaBinariaMenor y busquedaBinariaMayor.
Manda llamar el metodo print de la clase Logs
  Entradas: 
      int starting, id del dia de inicio del rango buscado
      int ending, id del dia de fin del rango buscado
  Complegidad (sin incluir las llamadas a funciones):
    O(N): Itera un rango, cada posicion de ese rango
*/
void Bitacora::printRange(int starting, int ending){
    int startingIndex = busquedaBinariaMenor( starting );
    int endingIndex = busquedaBinariaMayor( ending );
    for(int i = endingIndex; i >= startingIndex ; i--){
        this -> myLogs[i] -> print();
    }
}

/**Metodo merge (Parte de algoritmo de ordenamiento)

Toma una lista que tiene dos sublistas ordenadas para juntarlas en una sola
  Entradas: 
    int ini, la posicion del primer elemento a ordenar
    int fin, la posicion del ultimo elemento a ordenar
  Complejidad:
    O(N): Itera el rango dos veces
*/
void Bitacora::merge( int ini , int fin ){
    int avg = (ini + fin) / 2;
    Logs* aux[ fin - ini + 1 ];
    int count[] = { ini , avg + 1 };
    for(int i = 0 ; i <= fin - ini ; i++){
        if( ( count[1] != fin + 1 ) &&
        (count[0] == avg + 1 || this -> myLogs[ count[1] ] -> getId() < this -> myLogs[ count[0] ] -> getId() ) ){
            aux[i] = this -> myLogs[ count[1] ];
            count[1] ++;
        }
        else{
            aux[i] = this -> myLogs[ count[0] ];
            count[0] ++;
        }
    }
    for(int i = 0 , j = ini ; j <= fin ; i++ , j++)
        this -> myLogs[j] = aux[i];
}

/*Llamadas recursivas de Merge Sort
  Llama al metodo merge
  Entradas:
    int ini, posicion desde la cual que quiere empezar a ordenar
    int fin, posicion en la se quiere dejar de ordenar
  Complejidad (sin incluir las llamadas a funciones):
    O(Log(N)): Por la naturaleza divide los casos a la mitas en cada iteracion
*/
void Bitacora::sortByDate( int ini , int fin ){
    if( ini < fin ){
        int avg = (ini + fin) / 2;
        sortByDate( ini , avg );
        sortByDate( avg + 1, fin );
        merge( ini , fin );
    }
}

/**
Funcion de preparacion para inicializar Merge Sort en sortByDate
  Complegidad (sin incluir las llamadas a funciones):
    O(1): Solo hace un paso
*/
void Bitacora::sortByDate(){
    sortByDate( 0 , myLogs.size() - 1 );
}

/**
Método de Busqueda Binaria (Algoritmo de Busqueda)

Donde se busca el primer registro del dia pedido
  Parmetros: int valor, que es el ID con el primer segundo del dia
  Salida: posicion del registro que cumple con las condiciones anteriores
  Complejidad :
    O(Log(N)): Divide a la mitad el rango posible en cada iteracion
*/
int Bitacora::busquedaBinariaMenor( int valor ){
    int min = 0;
    int max = this -> myLogs.size() - 1 ;
    int avg;
    if( valor < this -> myLogs[0] -> getId() ) return 0;
    if( valor > this -> myLogs[this -> myLogs.size() - 1 ] -> getId() ) return this -> myLogs.size();
    while( min <= max ){
        avg = ( min + max ) / 2;
        if ( this -> myLogs[avg] -> getId() >= valor && this -> myLogs[ avg - 1 ] -> getId() < valor)
            return avg;
        else if( valor < this -> myLogs[avg] -> getId() )
            max = avg - 1;
        else
            min = avg + 1;
    }
    return 0;
}

/**
Método de Busqueda Binaria (Algoritmo de Busqueda)

Donde se busca el ultimo registro del dia pedido
  Parmetros: int valor, que es el ID con el ultimo segundo del dia
  Salida: posicion del registro que cumple con las condiciones anteriores
  Complejidad :
    O(Log(N)): Divide a la mitad el rango posible en cada iteracion
*/
int Bitacora::busquedaBinariaMayor( int valor ){
  int min = 0;
  int max = this -> myLogs.size() - 1;
  int avg;
  if( valor < this -> myLogs[0] -> getId() ) return - 1;
  if( valor > this -> myLogs[this -> myLogs.size() - 1] -> getId()) return this -> myLogs.size() - 1;
  while(min <= max){
      avg = (min + max) / 2;
      if (this -> myLogs[avg] -> getId() <= valor && this -> myLogs[avg + 1] -> getId() > valor)
          return avg;
      else if(valor < this -> myLogs[avg] -> getId())
          max = avg - 1;
      else
          min = avg + 1;
  }
  return 0;
}
