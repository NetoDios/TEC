#include <iostream>
#include <limits>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList(){
    this->size=0;
    this->head=nullptr;
    this->last=nullptr;
}
LinkedList::LinkedList(int* a, int size){
    this->head=nullptr;
    this->last=nullptr;
    for(int i=0;i<size;i++){
        insertEnd(a[i]);
    }
}
LinkedList::~LinkedList(){
    cout<<"DESTRUCTING...\n";
    destruct(this->head);
}
void LinkedList::destruct(ListNode* current){
    if(current->next!=nullptr)
        destruct(current->next);
    this->size--;
    delete current;
    return;
}
int LinkedList::length(){
    return this->size;
}
bool LinkedList::isEmpty(){
    return this->size==0;
}
int LinkedList::start(){
    return this->head->value;
}
int LinkedList::end(){
    return this->last->value;
}
void LinkedList::insertBeginning(int value){
    this->head = new ListNode(value,this->head);
    if(this->last==nullptr)
        this->last=this->head;
    this->size++;
}
void LinkedList::insertEnd(int value){
    if(this->last==nullptr){
        insertBeginning(value);
        return;
    }
    this->last->next=new ListNode(value);
    this->last=this->last->next;
    this->size++;
}
void LinkedList::insertAt(int value,int index){
    if(index>this->size || index<0)
        throw invalid_argument("index out of range");
    ListNode* current=head;
    for(int i=1;i<index;i++) current=current->next;
    ListNode* newNode= new ListNode(value,current->next);
    current->next=newNode;
    this->size++;
}
void LinkedList::setAt(int value,int index){
    if(index>this->size || index<0)
        throw invalid_argument("index out of range");
    ListNode* current=head;
    for(int i=0;i<index;i++) current=current->next;
    current->value=value;
}
int LinkedList::getAt(int index){
    if(index>this->size || index<0)
        throw invalid_argument("index out of range");
    ListNode* current=head;
    for(int i=0;i<index;i++) current=current->next;
    return current->value;
}

void LinkedList::removeBeginning(){
    if(this->size>0){
        ListNode* first=this->head;
        head=head->next;
        this->size--;
        if(this->size==0)
            this->last=nullptr;
        delete first;
    }
    else
        throw invalid_argument("Can't remove an element when the list is empty");
}
void LinkedList::removeEnd(){
    if(this->size>0){
        ListNode* end=this->last;
        ListNode* current=this->head;
        for(int i=1;i<this->size;i++){
            current=current->next;
        }
        current->next=nullptr;
        this->last=current;
        this->size--;
        delete end;
    }
    else
        throw invalid_argument("Can't remove an element when the list is empty");
}
void LinkedList::removeAt(int index){ // solo funciona con index en el rango [1,N]
    if(index>this->size || index<0)
        throw invalid_argument("index out of range");
    else if(index==0)
        removeBeginning();
    else if(index==this->size-1)
        removeEnd();
    else{
        ListNode* current=this->head;
        for(int i=1;i<index;i++) current=current->next;
        ListNode* aux=current->next;
        current->next = current->next->next;
        delete aux;
        this->size--;
    }
}
ostream& operator<<(ostream& output, const LinkedList& list){
    ListNode* current=list.head;
    for(int i=0;i<list.size;i++){
        cout<<current->value<<", ";
        current=current->next;
    }
    cout<<'\n';
    return output;
}

int main(){
    LinkedList* start=new LinkedList();
    cout<<"\t---insertBeginning\n";
    for(int i=1;i<=5;i++){
        start->insertBeginning(i);
    }
    cout<<*start;
    start->~LinkedList();

    LinkedList* finish=new LinkedList();
    cout<<"\n\t---insertEnd\n";
    for(int i=1;i<=5;i++){
        finish->insertEnd(i);
    }
    cout<<*finish;
    finish->~LinkedList();

    int aux[]={1,3,5,7,9,11,13};
    cout<<"\n\t---initial values\n";
    LinkedList* initial=new LinkedList(aux,7);
    initial->insertAt(6,3);
    cout<<*initial;
    initial->removeAt(3);
    initial->removeEnd();
    cout<<*initial;
    initial->~LinkedList();
    
    return 0;
}
