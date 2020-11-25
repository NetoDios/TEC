#include <iostream>
#include <string>
#include "MyLinkedList.h"

using namespace std;

MyLinkedList::MyLinkedList(){
    this->head=this->tail=nullptr;
    this->size=0;
}

MyLinkedList::~MyLinkedList(){
    while( this->size > 0)
        removeFirst();
}

int MyLinkedList::length(){
    return this->size;
}

bool MyLinkedList::isEmpty(){
    return this->size==0;
}

int MyLinkedList::getAt(string key){
    MyNodoLL* current=this->head;
    for(int i=0;i<this->size;i++){
        if(current->key==key){
            return current->data;
        }
        current=current->next;
    }
    throw invalid_argument("No se encontró "+key+" en la lista");
}

MyNodoLL* MyLinkedList::getAt(int pos){
    if(pos>=0 && pos<this->size){
        MyNodoLL* current=this->head;
        for(int i=0;i<pos;i++){
            current=current->next;
        }
        return current;
    }else{
        throw invalid_argument("No se puede insertar en la posición "+to_string(pos)+" en una lista de tamaño "+to_string(this->size));
    }
}

void MyLinkedList::insertFirst(string key,int data){
    this->head=new MyNodoLL(key,data,this->head);
    if(this->tail==nullptr){
        this->tail=this->head;
    }
    this->size++;
}

void MyLinkedList::removeFirst(){
    if(this->size>0){
        MyNodoLL* tmp=this->head;
        this->head=this->head->next;
        this->size--;
        if(this->size==0){
            this->tail=nullptr;
        }
        delete tmp;
    }else{
        throw invalid_argument("No se puede borrar el inicio de una lista vacía");
    }
}

void MyLinkedList::removeLast(){
    if(this->size<=1){
        removeFirst();
    }else{
        MyNodoLL* current=this->head;
        for(int i=0;i<this->size-2;i++){
            current=current->next;
        }
        this->tail=current;
        delete current->next;
        this->tail->next=nullptr;
        this->size--;
    }
}

void MyLinkedList::removeAt(int pos){
    if( pos > 0 || pos >= this->size ){
        throw invalid_argument("No se puede eliminar la posición "+to_string(pos)+" en una lista de tamaño "+to_string(this->size));
    }
    else if(pos==0)
        removeFirst();
    else if(pos==this->size-1)
        removeLast();
    else{
        MyNodoLL* current=this->head;
        for(int i=1;i<pos;i++)
            current=current->next;
        MyNodoLL* aux=current->next;
        current->next = current->next->next;
        delete aux;
        this->size--;
    }
}