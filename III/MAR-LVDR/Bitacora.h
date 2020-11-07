#ifndef BITACORA_H
#define BITACORA_H

#include <vector>
#include <iostream>
#include "BST.h"
using namespace std;

class Bitacora{
    private:
        BST myBST;
        vector<string> splitString(string text, string delimiter);
		void top(Node* current, int& num);
    public:
        Bitacora(string filename);
		void top(int num);
};

#endif // BITACORA_H
