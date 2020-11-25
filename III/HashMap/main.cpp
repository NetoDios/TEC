#include <iostream>
#include <vector>
#include "MyHashTable.h"

using namespace std;

int main(){
    cout<<"Hola mundo HashTable"<<endl;
    MyHashTable ht;
    ht.put("Pablo",1);
    ht.put("Jaime",2);
    ht.put("Simon",3);
    ht.put("Sareli",4);
    ht.put("Marisol",5);
    ht.put("Neto",6);
    ht.put("German",7);
    ht.put("Vale",8);
    ht.put("Sauce",9);
    ht.put("Carlos",10);
    ht.put("Llamas",11);
    ht.put("Willy",12);
    ht.put("Parada",13);
    ht.put("Trini",14);
    ht.put("Anito",15);
    ht.put("Andy",16);
    ht.put("Babuka",17);
    ht.put("Itzel",18);
    ht.put("Maju",19);
    ht.put("Servando",20);
    ht.put("Juventino",21);
    ht.put("Many",22);
    ht.put("Lidice",23);
    vector<string> names={"Pablo","Jaime","Simon","Sareli","Marisol","Neto","German","Sauce","Vale","Carlos","Llamas","Parada","Willy","Trini","Anito","Andy","Babuka","Itzel","Maju","Servando","Juventino","Many","Lidice"};
    
    for(int i =0;i<names.size();i++){
    string nombre=names[i];
    cout<<"La matricula de "<<nombre<<" es "<<ht.get(nombre)<<endl;
    }
    

    cout<<"FIN"<<endl;
    return 0;
} 