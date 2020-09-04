#include "Persona.h"
#include <string>
using std::string;
Persona::Persona(string name,int age,float height,float weight){
    nombre=name;
    edad=age;
    estatura=height;
    peso=weight;
}
string Persona::getName(){return nombre;}
