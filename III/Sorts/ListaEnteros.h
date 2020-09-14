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
        int partition(int ini,int fin);
        void quickSort(int ini,int fin);
    public:
        ListaEnteros();
        ListaEnteros(int valores[],int lenght);
        void print();
        void secuentialQuerry();
        void binaryQuerry();
        void bubbleSort();
        void selectionSort();
        void insertionSort();
        void mergeSort();
        void quickSort();
};

#endif // LISTAENTEROS_H