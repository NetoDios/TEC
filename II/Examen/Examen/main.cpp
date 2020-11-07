#include <iostream>
#include "Persona.h"
#include "Estudiante.h"
#include "Profesor.h"
using namespace std;
int main()
{
    Persona* comunidad[5];
    comunidad[1]= new Profesor("Ken Bauer",32,1.76,81.4,"Ingenierias","L00700700",200);;
    comunidad[3]= new Profesor("Fernando Rea",40,1.83,75,"Ingenierias","L09999999",250);
    comunidad[0]= new Estudiante("Ernesto Alvarez",19,1.95,90,95.24,"ITC","A00227490");
    comunidad[2]= new Estudiante("Aldair Ramirez",19,1.70,68.12,98.5,"I2D","A00227525");
    comunidad[4]= new Estudiante("Alvaro Wilson",19,1.65,65,97,"I2D","A00227515");
    for(int i=0;i<5;i++) comunidad[i]->print();
    return 0;
}
