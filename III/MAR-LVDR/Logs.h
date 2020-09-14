#ifndef LOGS_H
#define LOGS_H

#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
class Logs{
    private:
        string month;
        string day;
        string hour;
        string ip;
        string errorMsg;
        int id;
        
        int crearId();
        string hourId();
        string dayId( string dia );
        string monthId( string month );
    public:
        Logs( string month , string day , string hour , string ip , string errorMsg );
        void print( ofstream& myFile );
        void print();
        int getId();
};

#endif // LOGS_H
