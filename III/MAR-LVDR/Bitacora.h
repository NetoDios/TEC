#ifndef BITACORA_H
#define BITACORA_H

#include <vector>
#include <iostream>
#include <fstream>
#include "Logs.h"
#include "DoubleLinkedList.h"
using namespace std;

class Bitacora{
    private:
        DoubleLinkedList myLogs;
        void merge(int ini,int fin);
        void sortByIP(int ini,int fin);
        vector<string> splitString(string text, string delimiter);
    public:
        Bitacora(string filename);
        void print();
        void printRange(string starting,string ending, int index);
        void sortByIP();
        int busquedaBinariaMenor(int valor);
        int busquedaBinariaMayor(int valor);
};

#endif // BITACORA_H
