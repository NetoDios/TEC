#include <iostream>
#include "BST.h"
using namespace std;

/*Constructor de la clase BST

Esta funcion inicializa el BST sin elementos y por lo tanto es de tamaño 0
    Complejidad:
    O(1): Solo construye un objeto
*/
BST::BST(){
    this -> root =nullptr;
    this -> len = 0;
}

/*Metodo insercion de un nuevo nodo

Si la lista esta vacia (len==0) crea e inserta un nuevo nodo al inicio, si ya hay elementos inserta el nuevo nodo al final y aumenta su tamaño.
	Entrada:
		string ip: La ip (sin puerto) que se inserta dentro del BST
		int cnt: La cantidad de veces que se encontro la ip en el documento txt
  Complejidad:
  O(log(N)): Recorre un elemento del BST por nivel y lo inserta como hoja.
*/
void BST::push(string ip, int cnt){ 
	if( this -> len == 0 ){
		this -> root = new Node( ip, cnt );
		this -> len++;
	}
	Node *current = this -> root;
	Node *prev = nullptr;
	while( current != nullptr ){
	  prev = current;
		current = cnt < current -> cnt ? current -> left : current -> right;
	}
	if( cnt < prev -> cnt )
		prev -> left = new Node( ip, cnt );
	else
		prev -> right = new Node( ip, cnt );
	this -> len++;
}

/*Metodo size

Regresa el numero de nodos que tiene el BST
  Complejidad:
  O(1): Solo retorna el len
*/
int BST::size(){
  return this -> len;
}

/*Metodo top

Regresa la raiz nodos del BST
  Complejidad:
  O(1): Solo retorna la raiz
*/
Node* BST::top(){
  return this -> root;
}