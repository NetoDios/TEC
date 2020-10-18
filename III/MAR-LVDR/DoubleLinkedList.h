#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <vector>
#include <iostream>
#include <fstream>
#include "Logs.h"
using namespace std;

struct ListNode{
    Logs* me;
    ListNode* prev;
    ListNode* next;
    ListNode(Logs* me, ListNode* next, ListNode* prev){
        this->me = me;
        this->next = next;
        this->prev = prev;
    }
    ListNode(Logs* me):ListNode(me, nullptr, nullptr){}
    ListNode(Logs* me, ListNode* prev):ListNode(me, nullptr, prev){}
};

class DoubleLinkedList{
    private:
        ListNode* first;
        ListNode* last;
        int len;
    public:
        DoubleLinkedList();
        ~DoubleLinkedList();
        int size();
        void push(Logs* next);
        void swap(ListNode* a, ListNode* b);
        ListNode* front();
        Logs* operator [] (int pos);
};

#endif // LOGS_H
