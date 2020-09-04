#ifndef PERSONA_H
#define PERSONA_H
#include <string>
using std::string;

class Persona
{
    public:
        Persona(string,int,float,float);
        string getName();
        virtual void print(){};
    protected:
        string nombre;
        int edad;
        float estatura, peso;
};

#endif // PERSONA_H
