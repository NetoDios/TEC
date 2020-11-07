#include "Profesor.h"
#include <iostream>
using namespace std;
Profesor::Profesor(string name,int age,float height,float weight,string school,string id,float salary):Persona(name,age,height,weight){
            escuela=school;
            nomina=id;
            salario=salary;
        }
void Profesor::print(){
    cout<<nombre<<":\n";
    cout<<'\t'<<"Edad: "<<edad<<'\n';
    cout<<'\t'<<"Estatura: "<<estatura<<'\n';
    cout<<'\t'<<"Peso: "<<peso<<'\n';
    cout<<'\t'<<"Escuela: "<<escuela<<'\n';
    cout<<'\t'<<"Nomina: "<<nomina<<'\n';
    cout<<'\t'<<"Salario: "<<salario<<'\n';
    cout<<"\n";
}
