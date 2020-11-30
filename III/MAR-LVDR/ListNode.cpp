#include <iostream>
#include <limits>
#include "ListNode.h"
using namespace std;

/*
Constructor Nodo
Input:
  ip- Puerto que intento acceder
  fecha- Fecha que intento acceder
  next- Apuntador al siguiente nodo (ya que es Linked List)
Decripcion:
  Asigna la ip, asigna una fecha de acceso dentro de un nodo, apunta al siguiente nodo e inicializa el numero de accesos en 1
Complejidad:
  O(1)
*/
ListNode::ListNode(string ip, string fecha, ListNode* next){
  this->ip = ip;
  this->fecha.insert(fecha);
  this->next = next;
  this->accesos = 1;
}

/*
Constructor Nodo
Input:
  ip- Puerto que intento acceder
  fecha- Fecha que intento acceder
Decripcion:
  Asigna la ip, asigna una fecha de acceso dentro de un nodo, apunta al siguiente nodo e inicializa el numero de accesos en 1
Complejidad:
  O(1)
*/
ListNode::ListNode(string ip, string fecha){
  this->ip = ip;
  this->fecha.insert(fecha);
  this->next = nullptr;
  this->accesos = 1;
}

/*
Constructor Nodo
Input:
  ip- Puerto que intento acceder
  fecha- El conjunto de fechas asociadas a una ip
  next- Apuntador al siguiente nodo (ya que es Linked List)
Decripcion:
  Asigna la ip, asigna una fecha de acceso dentro de un nodo, apunta al siguiente nodo e inicializa en+l numero de accesos en 1
Complejidad:
  O(1)
*/
ListNode::ListNode(string ip, set<string> fecha, ListNode* next){
  this->ip = ip;
  this->fecha=fecha;
  this->next = next;
  this->accesos = this->fecha.size();
}

/*
Insert (fecha)
Input:
fecha- La fecha asociada a una ip en el registro
Descripcion:
  Inserta la fecha en un nodo e incrementa el numero de accesos
Complejidad:
O(1)
*/
void ListNode::insert(string fecha){
  this->fecha.insert(fecha);
  this->accesos++;
}
