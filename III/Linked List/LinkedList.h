#ifndef LINKED_LIST
#define LINKED_LIST
#include <iostream>
using namespace std;
struct ListNode{
    int value;
    ListNode* next;

    ListNode(int value,ListNode* next){
        this->value=value;
        this->next=next;
    }
    ListNode(int value):ListNode(value,nullptr){}
};

class LinkedList{
    private:
        ListNode* head;
        ListNode* last;
        int size;
        void destruct(ListNode* current);
    public:
        LinkedList();
        LinkedList(int* array, int size);
        ~LinkedList();
        int length();
        bool isEmpty();
        int start();
        int end();
        void insertBeginning(int value);
        void insertEnd(int value);
        void insertAt(int value,int index);
        void setAt(int value,int index);
        int getAt(int index);
        void removeBeginning();
        void removeEnd();
        void removeAt(int index);

        friend ostream& operator<<(ostream& output, const LinkedList& list){
            ListNode* current=list.head;
            for(int i=0;i<list.size;i++){
                cout<<current->value<<", ";
                current=current->next;
            }
        }
};
#endif