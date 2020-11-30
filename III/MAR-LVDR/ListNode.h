#ifndef LIST_NODE
#define LIST_NODE
#include <iostream>
#include <set>
using namespace std;

struct ListNode{
  int accesos;
  set<string> fecha;
  string ip;
  ListNode* next;

  ListNode(string ip, string fecha, ListNode* next);
  ListNode(string ip, string fecha);
  ListNode(string ip, set<string> fecha, ListNode* next);
  
  void insert(string fecha);
  friend ostream& operator<<(ostream& output, const ListNode* nodo){
    cout << nodo->ip << " -> " << nodo->accesos;
    cout << "\n\t" << "MM DD Hora[24h]";
    for( auto i = nodo->fecha.begin(); i != nodo->fecha.end(); ++i )
        cout << "\n\t" << *i;
    return output;
  }
};

#endif