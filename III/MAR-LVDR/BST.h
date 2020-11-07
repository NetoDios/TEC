#ifndef BST_H
#define BST_H

#include <iostream>
#include "Logs.h"
using namespace std;

struct Node{
    string ip;
    int cnt;
    Node* left;
    Node* right;
    Node( string ip, int cnt, Node* left, Node* right ){
			this -> ip = ip;
			this -> left = left;
			this -> right = right;
      this -> cnt = cnt;
    }
    Node( string ip, int cnt ):Node( ip, cnt, nullptr, nullptr ){}
};

class BST{
    private:
        Node* root;
        int len;
    public:
        BST();
        int size();
        void push( string ip, int cnt );
				Node* top();
};

#endif // LOGS_H