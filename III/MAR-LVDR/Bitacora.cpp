#include "Bitacora.h"
#include "LinkedList.h"
#include <fstream>
#include <string>
using namespace std;

/*Constructor Bitacora
Descripcion:
  Abre el archivo, para cada registro dentro de el y guarda los datos dentro de la tabla hash. 
    El tamaño de la tabla sera de 245 para hacer exactamente 2 rehashings y cumplir con la propiedad de que la tabla sea de tamaño primo para mayor eficiencia
  Entrada:
    -string filename: Nombre del archivo con extension txt
  Complejidad:
    O(N): Depende directamente de los registros del archivo
*/
Bitacora::Bitacora( string filename ){
  this->len = 245;
  this->size = 0;
  this->table = new LinkedList[ this->len ];
  string linea;
  fstream archivo( filename );
  if( archivo.is_open() ) {
    while( getline( archivo , linea ) ) {
      vector<string> entrada = splitString( linea, " ");
      string tmpIP = entrada[1];
      string tmpDate = entrada[0];
      int pos = getPosition( tmpIP );
      ListNode* tmp = this->table[pos].getAt( tmpIP );

      if( tmp )
        tmp->insert(tmpDate);
      else{
        if( this->size/this->len > 0.75 )
          rehash();
        this->table[pos].insertBeginning( tmpIP, tmpDate );
        this->size++;
      }
    }
  }
}

/*Separa un registro en las 5 partes mas importantes
  Entradas: 
      string text: Recibe la linea a separar 
      string delimiter: Conjunto de caracteres donde se separara el registro
  Salidas: Un vector con los 2 elementos importantes del registro(la direccion ip y la fecha) 
  Complejidad (sin incluir las llamadas a funciones):
    O(1)
*/
vector<string> Bitacora::splitString( string text , string delimiter ){
    int  i = 0;
    vector<string> lines;
    size_t current = text.find( delimiter );
    size_t previous = 0;
    // -- Mes
    string mes = text.substr( previous , current - previous );
    previous = current + 1;
    current = text.find( delimiter , previous );
    // -- Dia
    string dia = text.substr( previous , current - previous );
    previous = current + 1;
    current = text.find( delimiter , previous );
    // -- Hora
    string hora = text.substr( previous , current - previous );
    previous = current + 1;
    current = text.find( ":" , previous );
    // -- IP
    lines.push_back( createDate(mes, dia, hora) );
    lines.push_back( text.substr( previous , current - previous ) );
    return lines;
}

/*
 rehash
 Descripcion:
  Incrementa el tamaño de la tabla, toma todos los valores de este y los vuelve a posicionar en base al nuevo tamaño
 Complejidad:
  O(N) - Visitas cada nodo exactamente 1 vez
*/
void Bitacora::rehash(){
  int pos = 0;
    this->len = this->len * 2 + 1;
    LinkedList* aux = new LinkedList[ this->len ];
    for( int i = 0 ; i < (this->len / 2) ; i++ ){
        while( !this->table[i].isEmpty() ){
            ListNode* tem = this->table[i].getHead();
            int pos = getPosition( tem->ip );
            aux[pos].insertBeginning( tem->ip, tem->fecha );
            this->table[i].removeBeginning();
        }
        this->table[i].~LinkedList();
    }
    delete[] table;
    this->table = aux;
}

/*
getPosition
  Descripcion:
    Asigna un valor numerico unico  a la llave pasada y a partir de este lo limita al tamaño de la tabla
  Input:
    -key: Una IP, de la que se quiere su posicion
  Output:
    -La posicion donde deberia estar la llave
  Complejidad:
    O(1)
*/
int Bitacora::getPosition( string key ){
  size_t hashT = hash<string>{}(key);
    int hashCode = static_cast<int>(hashT);
    return abs(hashCode) % this->len;
}

/*
createDate
  Descripcion:
    Le da formato para almacenar la fecha de los registros
      MM DD AAAA Hora
  Input:
    -month: Las primeras tres letras del mes [en ingles]
    -day: El dia en el que se quizo acceder [1-31]
    -time: La hora en la que se quizo acceder
  Output:
    -Un solo string con todos los datos formatados de forma estandarizada
  Complejidad:
    O(1)
*/
string Bitacora::createDate( string month, string day, string time ){
  string date = monthId( month ) + " ";
  date += day.size() == 1 ? "0" + day : day;
  date += " " + time;
  return date;
}

/*
monthId
  Descripcion:
    Asocia el nombre de un mes con el numero del mismo 
  Input:
    -month: Las primeras tres letras del mes
  Output:
    El numero del mes, con dos caracteres
  Complejidad:
    O(1)
*/
string Bitacora::monthId( string month ){
    string monthId = "0";
    if(month == "Jan") monthId = "01";
    else if(month == "Feb") monthId = "02";
    else if(month == "Mar") monthId = "03";
    else if(month == "Apr") monthId = "04";
    else if(month == "May") monthId = "05";
    else if(month == "Jun") monthId = "06";
    else if(month == "Jul") monthId = "07";
    else if(month == "Aug") monthId = "08";
    else if(month == "Sep") monthId = "09";
    else if(month == "Oct") monthId = "10";
    else if(month == "Nov") monthId = "11";
    else if(month == "Dec") monthId = "12";
    return monthId;
}