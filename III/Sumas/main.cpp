/**
    Funciones iterativas y recursivas:
        -Dado un número N, encuentra la sumatoria de todos los valores en en rango [1,N]
        -Metodos diferentes: Iterativo, Recursivo, Matematico
        -Analisis de complejidad
        -Recibe un solo número por ejecución
    Ernesto Adrián Alvarez Salzar - A00227490
    Fecha: 23/08/2020
*/

#include <iostream>
using namespace std;

/**
    sumaIterativa(int n) -> O(n)
    int n -> el valor el que se va a sumar
    return -> la sumatoria de 1 hasta n
        Un solo ciclo dependiente de la variable n
*/
long long int sumaIterativa(unsigned int n){
    long long int value = 0;
    while(n){
        value += n;
        n--;
    }
    return value;
}

/**
    sumaRecursiva(int n) -> O(n)
    int n -> el valor el que se va a sumar
    return -> la sumatoria de 1 hasta n
        Cada nivel de recurción llama hasta a 1 solo nivel nuevo
        -Valor maximo posible: 32504 (*Puede depender de la maquina)
*/
long long int sumaRecursiva(unsigned int n){
    if(n==0) return n;
    return n + sumaRecursiva(n - 1);
}

/**
    sumaDirecta(int n) -> O(1)
    int n -> el valor el que se va a sumar
    return -> la sumatoria de 1 hasta n
        Una ecuación matematica determina la sumatoria
        -Separada en if/else para evitar desbordar el tamaño de un long long int
        -Procesos separados para evitar desbordar el tamaño de un long long int
*/
long long int sumaDirecta(int n){
    long long int value = 0;
    if(n % 2){
        value = (n + 1) / 2;
        value *= n;
    }
    else{
        value = (n / 2);
        value *= (n + 1);
    }
    return value;
}
/**
    Casos de prueba:
    Input: 525
    Output: 138075
    ---
    Input: 5
    Output: 15
    ---
    Input: 2532
    Output: 3206778
    ---
    Input: 777
    Output: 302253
    ---
**/
int main(){
    int input = 0; // Entero simple (2^31) -> Su sumatoria es por definicion es > 2^63 (entero largo)
    do{
        cout << "Ingrese un numero entero positivo: ";
        cin >> input;
    }
    while(input <= 0);
    cout << "sumaIterativa( " << input << " )\t-> " << sumaIterativa(input) << endl;
    cout << "sumaRecursiva( " << input << " )\t-> " << sumaRecursiva(input) << endl;
    cout << "sumaDirecta  ( " << input << " )\t-> " << sumaDirecta(input) << endl;
    return 0;
}
