#include <iostream>
#include <stdexcept>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList(){
    this->size=0;
    this->head=nullptr;
    this->last=nullptr;
}
LinkedList::LinkedList(int* a, int size){
    this->size=size;
    for(int i=0;i<size;i++){
        insertEnd(a[i]);
    }
}
int LinkedList::length(){
    return this->size;
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
    try{
        if(index>this->size || index<0){
            throw invalid_argument("index out of range");
        }
        ListNode* current=head;
        for(int i=1;i<index;i++) current=current->next;
        ListNode* newNode= new ListNode(value,current->next);
        current->next=newNode;
        this->size++;
    }
    catch(const invalid_argument& ia){
        cerr << "Invalid argument: " << ia.what() << '\n';
    }
}
int LinkedList::getAt(int index){
    try{
        if(index>this->size || index<0){
            throw invalid_argument("index out of range");
        }
        ListNode* current=head;
        for(int i=0;i<index;i++) current=current->next;
        return current->value;
    }
    catch(const invalid_argument& ia){
        cerr << "Invalid argument: " << ia.what() << '\n';
    }

}
void LinkedList::deleteAt(int index){ // solo funciona con index en el rango [1,N]
     try{
        if(index>this->size || index<0){
            throw invalid_argument("index out of range");
        }
        ListNode* current=head;
        for(int i=1;i<index;i++) current=current->next;
        ListNode* aux=current->next;
        current->next = current->next->next;
        delete[] aux;
        this->size--;
    }
    catch(const invalid_argument& ia){
        cerr << "Invalid argument: " << ia.what() << '\n';
    }
}

int main(){
    LinkedList start,finish;
    cout<<"\t---insertBeginning\n";
    for(int i=1;i<=5;i++){
        start.insertBeginning(i);
    }
    for(int i=0;i<start.length();i++){
        cout<<start.getAt(i)<<", ";
    }
    cout<<"\n\t---insertEnd\n";
    for(int i=1;i<=5;i++){
        finish.insertEnd(i);
    }
    for(int i=0;i<finish.length();i++){
        cout<<finish.getAt(i)<<", ";
    }

    int aux[]={1,3,5,7,9,11,13};
    cout<<"\n\t---initial values\n";
    LinkedList initial(aux,7);
    initial.insertAt(6,3);
    for(int i=0;i<initial.length();i++){
        cout<<initial.getAt(i)<<", ";
    }
    return 0;
}