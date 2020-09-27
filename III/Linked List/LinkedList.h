#ifndef LINKED_LIST
#define LINKED_LIST

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
    public:
        LinkedList();
        LinkedList(int* array, int size);
        int length();
        void insertBeginning(int value);
        void insertEnd(int value);
        void insertAt(int value,int index);
        int getAt(int index);
        void deleteAt(int index);
};
#endif