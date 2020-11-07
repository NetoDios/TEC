#include "Estudiante.h"
#include <iostream>
using namespace std;
Estudiante::Estudiante(string name,int age,float height,float weight,float gpa,string program,string id):Persona(name,age,height,weight){
    promedio=gpa;
    carrera=program;
    matricula=id;
}
void Estudiante::print(){
    cout<<nombre<<":\n";
    cout<<'\t'<<"Edad: "<<edad<<'\n';
    cout<<'\t'<<"Estatura: "<<estatura<<'\n';
    cout<<'\t'<<"Peso: "<<peso<<'\n';
    cout<<'\t'<<"Carrera: "<<carrera<<'\n';
    cout<<'\t'<<"Matricula: "<<matricula<<'\n';
    cout<<'\t'<<"Promedio: "<<promedio<<'\n';
    cout<<"\n";
}
