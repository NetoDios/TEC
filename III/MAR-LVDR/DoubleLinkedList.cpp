#include <iostream>
#include <limits>
#include "DoubleLinkedList.h"
using namespace std;

DoubleLinkedList::DoubleLinkedList(){
    this -> first =nullptr;
    this -> last =nullptr;
    this -> len = 0;
}

DoubleLinkedList::~DoubleLinkedList(){
}

void DoubleLinkedList::push(Logs* log){ 
    if(this -> len == 0){
        this -> first = new ListNode(log);
        this -> last = this -> first;
    }
    else{
        this -> last -> next = new ListNode(log, this -> last);
        this -> last = this -> last -> next;
    }
    this -> len ++;
}

int DoubleLinkedList::size(){
    return this -> len;
}

void DoubleLinkedList::swap(ListNode* a, ListNode* b){
    ListNode* aux = b;
    b->me = a->me;
    a->me = aux->me;
}

Logs* DoubleLinkedList::operator [](int pos){
    ListNode* current = this->first;
    for(int i=0 ; i < pos ; i++) current = current->next;
    return current->me;
}

ListNode* DoubleLinkedList::front(){
    return this->first;
}