#include <iostream>
#include "LinkedList.h"
using namespace std;

/*
Constructor Linked List
  Descripcion:
    Inicializa la lista con tamaño cero y la cabeza apuntando a nulo.
  Complejidad:
  
*/
LinkedList::LinkedList(){
    this->size=0;
    this->head=nullptr;
}

/*
Destructor Linked List
Descripcion: 
 Manda llamar la funcion removeBeginning que elimina todos los nodos uno a la vez.
Complejidad:
  O(N)
*/
LinkedList::~LinkedList(){
  while( this->size > 0 )
    removeBeginning();
  delete this->head;
}

/*
Length
  Descripcion:
    Regresa el tamaño de la lista enlazada
  Complejidad:
    O(1)
*/
int LinkedList::length(){
    return this->size;
}

/*
isEmpty
  Descripcion:
    Determina si hay o no nodos en la lista
  Complejidad:
    O(1)
*/
bool LinkedList::isEmpty(){
    return this->size==0;
}

/*
insertBeginning
  Descripcion:
   Inserta un nuevo nodo en la cabeza de la lista e incrementa el tamaño 
  Input:
    -key: La llave con la que se identificaran los datos
    -date: La primer fecha asociada a la llave
  Complejidad:
    O(1)
*/
void LinkedList::insertBeginning(string key, string date){
    this->head = new ListNode(key, date, this->head);
    this->size++;
}

/*
insertBeginning
 Descripcion:
   Inserta un nuevo nodo en la cabeza de la lista e incrementa el tamaño 
  Input:
    -key: La llave con la que se identificaran los datos
    -date: El conjunto de fechas asociadas a la llave
  Complejidad:
    O(1)
*/
void LinkedList::insertBeginning(string key, set<string> date){
    this->head = new ListNode(key, date, this->head);
    this->size++;
}

/*
getAt
  Descripcion:
    Itera la lista hasta encontrar el nodo que contiene la llave asociada
  Input:
    -key: La llave asociada a los datos
  Output:
    ListNode*: Retorna el nodo asociado a la llave
  Complejidad:
    O(N)
*/
ListNode* LinkedList::getAt(string key){
    ListNode* current=this->head;
    while(current && current->ip != key)
      current = current->next;
    return current;
}

/*
getHead
  Descripcion:
    Retorna el primer nodo de la lista enlazada
  Complejidad:
    O(1)
*/
ListNode* LinkedList::getHead(){
    return this->head;
}

/*
removeBeginning
  Descripcion:
    Elimina el primer nodo de la lista enlazada si hay nodos en la lista y decrementa su tamaño
  Complejidad:
    O(1)
*/
void LinkedList::removeBeginning(){
    if( this->size > 0 ){
        ListNode* first = this->head;
        this->head = this->head->next;
        this->size--;
        delete first;
    }
    else
        throw invalid_argument("Can't remove an element when the list is empty");
}