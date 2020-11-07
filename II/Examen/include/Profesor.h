#ifndef PROFESOR_H
#define PROFESOR_H
#include "Persona.h"
#include <string>
using std::string;

class Profesor:public Persona
{
    public:
        Profesor(string,int,float,float,string,string,float);
        void print();
    protected:
        string escuela,nomina;
        float salario;
    private:
};
#endif // PROFESOR_H
