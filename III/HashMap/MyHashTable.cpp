/*
    Implementacion de un HashMap
        Permite utilizarse como un ADT con sus correspondientes funciones
        Utiliza intermanete una lista ligada para el encadenamiento
    
    24 de Noviembre de 2020
*/

#include <iostream>
#include <string>
#include <functional>
#include <cmath>
#include "MyHashTable.h"

using namespace std;

/*
    Constructor:
        Inizializa una nueva instancia con valores fijos
        Asigna un tamaño a la tabla
    Complegidad constante O(1)
*/
MyHashTable::MyHashTable(){
    this->size = 0;
    this->sizeA = 11;
    this->tabla = new MyLinkedList[ this->sizeA ];
}

/*
    Destructor:
        Para toda posision en la tabla de hash
            Eliminar todos los Nodos de la Lista
                Siempre elimina el primero
    Complegidad lineal O(N)
        -El ciclo while solo se ejecuta N veces
*/
MyHashTable::~MyHashTable(){
    for( int i = 0 ; i < this->sizeA ; i++ ){
        while( !this->tabla[i].isEmpty() )
            this->tabla[i].removeFirst();
        this->tabla[i].~MyLinkedList();
    }
    delete[] tabla;
}

/* 
    isEmpty:
        Determina si hay o no elementos en la tabla
    Compelgidad constante O(1)
*/
bool MyHashTable::isEmpty(){
    return this->size==0;
}

/* 
    rehashing:
        Crea una nueva tabla de hashing
        Para todo dato insertado en la tabla anterior
            Le asigna un nuevo lugar en la tabla nueva
            Lo remueve de la tabla anterior
        Reasigna la tabla
    Compelgidad lineal O(N)
        -El for se itera N veces
            -El while solo se ejecuta N veces (sin importar la iteraciones del for)
*/
void MyHashTable::rehashing(){
    int pos = 0;
    this->sizeA = this->sizeA * 2 + 1;
    MyLinkedList* aux = new MyLinkedList[ this->sizeA ];
    for( int i = 0 ; i < (this->sizeA / 2) ; i++ ){
        while( !this->tabla[i].isEmpty() ){
            MyNodoLL* tem = this->tabla[i].getAt(0);
            int pos=getPos( tem->key );
            aux[pos].insertFirst( tem->key, tem->data );
            this->tabla[i].removeFirst();
        }
        this->tabla[i].~MyLinkedList();
    }
    delete[] tabla;
    this->tabla = aux;
}

/* 
    getPos:
        Asigna un valor numerico a una cadena
            Limita el valor a un rango
                El rango depende del tamaño de la tabla
    Input:
        string key:
            La cadena de la que se quiere el valor numerico
    Output:
        int
            El valor que le corresponde a la cadena ingresada
    Compelgidad constante O(1)
        -Sin incluir los metodos que se llamen dentro
*/
int MyHashTable::getPos(string key){
    size_t hashT = hash<string>{}(key);
    int hashCode = static_cast<int>(hashT);
    return abs(hashCode) % this->sizeA;
}

/* 
    put:
        Inserta un valor a la tabla
            El valor tiene su corespondiente llave
        Cuando la tabla este cerca de estar llena
            Se llama al metodo rehashing y continua con lo normal
    Input:
        string key:
            La cadena es la llave unica con la que se relaciona
        int value:
            El valor numerico que esta vinculado a la llave
    Compelgidad constante O(1)
        -Sin incluir los metodos que se llamen dentro
*/
void MyHashTable::put(string key,int value){
    int aux = this->size / this->sizeA;
    if( aux > 0.75 )
        rehashing();
    int pos=getPos(key);
    this->tabla[pos].insertFirst(key,value);
    this->size++;
}

/* 
    get:
        Recupera un valor basado en la llave que tiene vinculada
    Input:
        string key:
            La cadena es la llave unica con la que se relaciona
    Output:
        int:
            El valor ligado a la llave pasada
    Compelgidad constante O(1)
        -Sin incluir los metodos que se llamen dentro
*/
int MyHashTable::get(string key){
    int pos = getPos(key);
    MyLinkedList* lista = &this->tabla[pos];
    return lista->getAt(key);
}

/* 
    remove:
        Elimina un dato de la tabla
    Input:
        string key:
            La cadena es la llave unica con la que se relaciona
    Compelgidad constante O(1)
        -Sin incluir los metodos que se llamen dentro
*/
void MyHashTable::remove(string key){
    int pos = getPos(key);
    MyLinkedList* aux = &this->tabla[pos];
    try{
        int del = aux->getAt(key);
        aux->removeAt(del);
        this->size--;
        return;
    }catch( exception& e ){
      throw e;
    }
}