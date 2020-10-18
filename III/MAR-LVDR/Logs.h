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
    string id;
    
    string crearId();

  public:
    Logs( string month , string day , string hour , string ip , string errorMsg );
    void print( ofstream& myFile );
    void print();
    string getId();
};

#endif // LOGS_H
