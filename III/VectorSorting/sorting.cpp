/*
    El programa recibe un entero N, y despues N enteros, los cuales ordena con tres metodos diferentes
        Insertion sort
        Bubble sort
        Merge sort
    Recibe un numero Q, y despues Q numeros, los cuales busca entre los datos ordenados e imprime la posicion
    Muestra las diferentes complejidades entre algoritmos (de comparaciones)

    13/09/2020
*/
#include <iostream>
#include <vector>
using namespace std;

/**
    Bubble sort: Ordena un vector de numeros enteros cambiando de posicion dos numeros consecutivos que esten desordenados
    Entrada:
        vector<int>& array, una referencia a un vector, este debe tener dentro de si los N numeros
    Retorno:
        int, el numero de comparaciones que se necesitaron para ordenar el vector.
            El vector ya debe estar ordenado.
    Complegidad:
        Peor de los casos -> O(N^2)
        Mejor de los casos -> O(N)
        Promedio -> O(N^2)
*/
int ordenaBurbuja( vector< int > &array ){
    int aux = 0, countCondiciones = 0;
    int fin = array.size();
    bool isOrdered = false;
    for( int i = 0 ; (i < fin-1 && !isOrdered) ; i++){
        isOrdered = true;
        for( int j = 0 ; (j < fin-i-1) ; j++){
            countCondiciones++;
            if( array[j] > array[j+1]){
                aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux;
                isOrdered = false;
            }
        }
    }
    return countCondiciones;
}

/**
    Insertion sort: Ordena un vector de numeros enteros tomando un valor y posicionandolo justo detras del primer valor mayor que encuente
    Entrada:
        vector<int>& array, una referencia a un vector, este debe tener dentro de si los N numeros
    Retorno:
        int, el numero de comparaciones que se necesitaron para ordenar el vector.
            El vector ya debe estar ordenado.
    Complegidad:
        Peor de los casos -> O(N^2)
        Mejor de los casos -> O(N^2)
        Promedio -> O(N^2)
*/
int ordenaInsercion( vector< int > &array ){
    int countCondiciones = 0;
    int aux = 0;
    for( int i = 1 ; i < array.size() ; i++){
        for( int j = i ; j > 0 ; j--){
            countCondiciones++;
            if( array[j] < array[j-1] ){
                aux = array[j];
                array[j] = array[j-1];
                array[j-1] = aux;
            }
            else j = 0;
        }
    }
    return countCondiciones;
}

/**
    Merge: A partir de dos subvectores ya ordenados genera un vector combinado ya ordenado, seleccionando el menor de cada subvector
    Entrada:
        vector<int>& array, una referencia a un vector, este debe tener dentro de si los N numeros
        int ini, la posicion del primer valor que se quiere ordenar
        int fin, la posicion del ultimo valor que se quiere ordenar
    Retorno:
        int, el numero de comparaciones que se necesitaron para ordenar el vector.
            El vector ya debe estar ordenado.
    Complegidad:
        Peor de los casos -> O(N)
        Mejor de los casos -> O(N)
        Promedio -> O(N)
*/
int merge( vector< int > &array, int ini, int fin ){
    int countCondiciones = 0;
    int avg = (ini + fin) / 2;
    vector< int > aux;
    int count[] = { ini, avg+1 };
    while( count[0] <= avg && count[1] <= fin ){
        countCondiciones++;
        if(array[ count[0] ] <= array[ count[1] ]){
            aux.push_back( array[ count[0] ] );
            count[0]++;
        }
        else{
            aux.push_back( array[ count[1] ] );
            count[1]++;
        }
    }
    while( count[0] <= avg ){
        aux.push_back( array[ count[0] ] );
        count[0]++;
    }
    while( count[1] <= fin ){
        aux.push_back( array[ count[1] ] );
        count[1]++;
    }
    for( int i = 0 , j = ini ; j <= fin ; i++ , j++ )
        array[j] = aux[i];

    return countCondiciones;
}

/**
    Merge sort: De forma recursiva divide un rango en dos sub partes iguales y resuelve para cada subparte. Llama a la funcion merge
    Entrada:
        vector<int>& array, una referencia a un vector, este debe tener dentro de si los N numeros
        int ini, la posicion del primer valor que se quiere ordenar. El valor menor del rango
        int fin, la posicion del ultimo valor que se quiere ordenar. El valor mayor del rango
    Retorno:
        int, el numero de comparaciones que se necesitaron para ordenar el vector.
            El vector ya debe estar ordenado.
    Complegidad (sin incluir la llamada a merge):
        Peor de los casos -> O(Log(N))
        Mejor de los casos -> O(Log(N))
        Promedio -> O(Log(N))
*/
int ordenaMerge( vector< int > &array, int ini, int fin ){
    int countCondiciones = 0, left = 0, right = 0;
    if( ini < fin ){
        int avg = ( ini + fin ) / 2;
        left = ordenaMerge( array , ini , avg );
        right = ordenaMerge( array , avg+1 , fin );
        countCondiciones += merge( array , ini , fin );
    }
    return countCondiciones + left + right;
}

/**
    Busqueda secuencial: Itera el vector hasta que encuentre el valor buscado, o haber evaluado todas las posiciones
    Entrada:
        vector<int>& array, una referencia a un vector, este debe tener dentro de si los N numeros
        int search, el valor del numero del que se quiere saber la posicion
        int& count, una referencia a un contador para la canidad de comparaciones que se hacen
    Retorno:
        int, La posicion en la que esta guardado el numero buscado, o -1 en caso de no encontrarlo
            El contador ya debera estar cargado
    Complegidad:
        Peor de los casos -> O(N)
        Mejor de los casos -> O(1)
*/
int busqSecuencial( vector< int > &array, int search, int &count ){
    for( auto i = array.begin() ; i < array.end() ; i++ ){
        count++;
        if(*i == search) return count-1;
    }
    return -1;
}

/**
    Busqueda binaria: Determina un rango y busca en el punto medio, cada iteracion reduce el rango a la mitad
    Entrada:
        vector<int>& array, una referencia a un vector, este debe tener dentro de si los N numeros
        int search, el valor del numero del que se quiere saber la posicion
        int& count, una referencia a un contador para la canidad de comparaciones que se hacen
    Retorno:
        int, La posicion en la que esta guardado el numero buscado, o -1 en caso de no encontrarlo
            El contador ya debera estar cargado
    Complegidad:
        Peor de los casos -> O(Log(N))
        Mejor de los casos -> O(1)
*/
int busqBinaria( vector< int > &array, int search, int &count ){
    int ini = 0;
    int fin = array.size() - 1;
    int avg = 0;
    while( ini <= fin ){
        avg = ( ini + fin ) / 2;
        count++;
        if( array[avg] == search ) return avg;
        count++;
        if( array[avg] > search ) fin=avg-1;
        else ini = avg + 1;
    }
    return -1;
}

/*
    Test cases:
    I:  8 10 4 8 12 20 15 54 18 4 20 54 100 12
    O:  28 18 14
        6 7 3
        7 8 4
        -1 8 4
        3 4 1
    I:  10 10 9 8 7 6 5 4 3 2 1 5 20 10 15 0 5
    O:  45 45 15
        -1 10 8
        9 10 7
        -1 10 8
        -1 10 6
        4 5 1
    I:  5 420 69 666 911 42 7 -4 5 100 420 666 999 0
    O:  7 10 8
        -1 5 4
        -1 5 4
        -1 5 6
        2 3 1
        3 4 3
        -1 5 6
        -1 5 4
    I:  4 9 8 7 6 10 2 6 10 8 14 9 18 7 2 4
    O:  6 6 4
        -1 4 4
        0 1 3
        -1 4 6
        2 3 3
        -1 4 6
        3 4 5
        -1 4 6
        1 2 1
        -1 4 4
        -1 4 4
*/
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0); // estas dos lieas posponen la cola de impresion hasta la final de la ejecucion
    vector< int > v1, v2, v3;
    int n = 0, val = 0;
    cin >> n;
    for( int i = 0 ; i < n ; i++ ){
        cin >> val;
        v1.push_back( val );
        v2.push_back( val );
        v3.push_back( val );
    }

    cout << ordenaInsercion( v1 ) << " " << ordenaBurbuja( v2 ) << " " << ordenaMerge( v3, 0, v3.size()-1 ) << '\n';

	int q, pos;
	int cantBS, cantBB;
	cin >> q;
	for (int i = 0; i < q; i++){
		cantBS = 0;
		cantBB = 0;
		cin >> val;
		pos = busqBinaria(v1, val, cantBB);
		pos = busqSecuencial(v1, val, cantBS);
		cout << pos << " " << cantBS << " " << cantBB << "\n";
	}
    return 0;
}
