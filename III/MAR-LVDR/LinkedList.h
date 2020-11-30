#ifndef LINKED_LIST
#define LINKED_LIST
#include <iostream>
#include "ListNode.h"
using namespace std;

class LinkedList{
	private:
		ListNode* head;
		int size;
	public:
		LinkedList();
    ~LinkedList();
		int length();
		bool isEmpty();

		void insertBeginning(string key, string date);
    void insertBeginning(string key, set<string> date);
		ListNode* getAt(string key);
    ListNode* getHead();
		void removeBeginning();
};
#endif