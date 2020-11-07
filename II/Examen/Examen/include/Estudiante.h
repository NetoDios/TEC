#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include "Persona.h"
#include <string>
using std::string;

class Estudiante:public Persona
{
    public:
        Estudiante(string,int,float,float,float,string,string);
        void print();
    protected:
        float promedio;
        string carrera,matricula;
    private:
};

#endif // ESTUDIANTE_H
