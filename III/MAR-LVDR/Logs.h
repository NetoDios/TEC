#ifndef LOGS_H
#define LOGS_H

#include <iostream>
using namespace std;
class Logs{
  private:
    string month;
    string day;
    string hour;
    string ip;
    string id;
    string errorMsg;
    string crearId();
  public:
    Logs( string month , string day , string hour , string ip , string errorMsg );
    string getIP();
};

#endif // LOGS_H
