#include <iostream>
#include <time.h>
#include "ListaEnteros.h"
using namespace std;

ListaEnteros::ListaEnteros(){
    this->valores= new int[0];
    this->length=0;
    this->size=0;
}
ListaEnteros::ListaEnteros(int valores[],int length){
    this->valores= new int[length];
    this->length=length-1;
    this->size=length;
    for(int i=0;i<size;i++) this->valores[i]=valores[i];
}
void ListaEnteros::print(){
    for(int i=0;i<size;i++) cout<<this->valores[i]<<", ";
    cout<<'\n';
}
void ListaEnteros::swap(int i,int j){
    int aux=this->valores[j];
    this->valores[j]=this->valores[i];
    this->valores[i]=aux;
}
void ListaEnteros::bubbleSort(){
    bool isOrdered=false;
    for(int i=0;i<size-1 && !isOrdered;i++){
        isOrdered=true;
        for(int j=0;j<size-i-1;j++){
            if(this->valores[j]>this->valores[j+1]){
                swap(j,j+1);
                isOrdered=false;
            }
        }
    }
}
void ListaEnteros::selectionSort(){
    int lowest=0;
    for(int i=0;i<size-1;i++){
        lowest=i;
        for(int j=i+1;j<size;j++){
            if(this->valores[j]<this->valores[lowest]) lowest=j;
        }
        swap(i,lowest);
    }
}
void ListaEnteros::insertionSort(){
    int j=0;
    for(int i=1;i<size;i++){
        j=i-1;
        while(this->valores[j]>this->valores[j+1] && j>=0){
            swap(j,j+1);
            j--;
        }
    }
}
void ListaEnteros::merge(int ini,int fin){
    int avg=(ini+fin)/2;
    int aux[fin-ini+1];
    int count[]={ini,avg+1};
    for(int i=0;i<=fin-ini;i++){
        if((count[1]!=fin+1) && (count[0]==avg+1 || this->valores[count[1]]<this->valores[count[0]])){
            aux[i]=valores[count[1]];
            count[1]++;
        }
        else{
            aux[i]=valores[count[0]];
            count[0]++;
        }
    }
    for(int i=0,j=ini;j<=fin;i++,j++)
        this->valores[j]=aux[i];
}
void ListaEnteros::mergeSort(int ini,int fin){
    if(ini<fin){
        int avg=(ini+fin)/2;
        mergeSort(ini,avg);
        mergeSort(avg+1,fin);
        merge(ini,fin);
    }
}
void ListaEnteros::mergeSort(){
    mergeSort(0,this->size-1);
}
int ListaEnteros::partition(int ini,int fin){
    srand(time(NULL));
    int pivote=rand() % (fin-ini) + ini;
    swap(pivote,ini);
    int i=ini+1;
    for(int j=ini+1;j<=fin;j++){
        if(this->valores[j] < this->valores[ini]){
            i++;
            swap(i,j);
        }
    }
    swap(ini,i);
    return i;
}
void ListaEnteros::quickSort(int ini,int fin){
    if(ini<fin){
        int pivote=partition(ini,fin);
        quickSort(ini, pivote-1);
        quickSort(pivote+1,fin);
    }
}
void ListaEnteros::quickSort(){
    quickSort(0,this->size-1);
}

int main(){
    //int placeholder[]={420,17,16,42,69,911,666};
    int placeholder[]={911,666,420,96,42,17,16};
    ListaEnteros myList(placeholder,7);
    myList.print();
    myList.mergeSort();
    myList.print();
    return 0;
}