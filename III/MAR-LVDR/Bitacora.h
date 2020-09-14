#ifndef BITACORA_H
#define BITACORA_H

#include <vector>
#include <iostream>
#include <fstream>
#include "Logs.h"
using namespace std;

class Bitacora{
    private:
        vector<Logs*> myLogs;
        void merge(int ini,int fin);
        void sortByDate(int ini,int fin);
        vector<string> splitString(string text, string delimiter);
    public:
        Bitacora(string filename);
        void print();
        void printRange(int starting,int ending);
        void sortByDate();
        int busquedaBinariaMenor(int valor);
        int busquedaBinariaMayor(int valor);
};

#endif // BITACORA_H
