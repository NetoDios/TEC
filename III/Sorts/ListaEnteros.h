#ifndef LISTAENTEROS_H
#define LISTAENTEROS_H

class ListaEnteros{
    private:
        int* valores;
        int length;
        int size;

        void swap(int i,int j);
        void merge(int ini,int fin);
        void mergeSort(int ini,int fin);
    public:
        ListaEnteros();
        ListaEnteros(int valores[],int lenght);
        void print();
        void bubbleSort();
        void selectionSort();
        void insertionSort();
        void mergeSort();

};

#endif // LISTAENTEROS_H