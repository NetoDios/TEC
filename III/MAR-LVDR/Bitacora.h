#ifndef BITACORA_H
#define BITACORA_H

#include <vector>
#include <limits>
#include <iostream>
#include "LinkedList.h"
using namespace std;

class Bitacora{
    private:
        LinkedList* table;
        int size, len;
        
        vector<string> splitString(string text, string delimiter);
        int getPosition( string key );
        string createDate( string month, string day, string time );
        string monthId( string month );
        void rehash();
    public:
        Bitacora(string filename);
        ListNode* operator [](string key){
          int pos = getPosition( key );
          ListNode* aux = this->table[pos].getAt(key);
          if(aux)
            return aux;
          throw invalid_argument("Key not found: There is no key value " + key);
        }
};

#endif // BITACORA_H
