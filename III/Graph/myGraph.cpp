/*  MyGraph
    Implementacion de busquedas en grafos, tanto BFS como DFS, ambos imprimen el recorrido
        Para ambos casos el usuario puede seleccionar el nodo en el que incia la busqueda

    9 de Nov de 2020
*/
#include "myGraph.h"
#include <iostream>
#include <queue>
using namespace std;

/*  loadGraph
        Inicializa la matriz de adyasencia y el numero de nodos del arbol
    Input:
        Referencia vector<vector<int>> matriz:
            La matriz de adyasencia con la que se planea trabajar
    Complegidad constante O(1)
*/
void MyGraph::loadGraph(vector<vector<int> >& matriz ){
    this -> matriz = matriz;
    this -> size = this -> matriz.size();
}

/*  DFS (publico) - Depth First Search
        Recorre todos los nodos del grafo (exactamente una vez)
            Para todo nodo sin visitar llama a la contraparte recursiva
    Input:
        int starting:
            El nodo a partir del cual se comienza la busqueda
    Complegidad lineal O(N)
        No incluye la complegidad de los metodos llamados dentro de si
*/
void MyGraph::DFS( int starting ){
    bool visited[ this->size ];
    for( int i = 0 ; i < this->size ; i++ ) visited[i] = false;
    visited[starting] = true;
    DFS( starting, visited );
    for( int i = 0 ; i < this->matriz.size() ; i++ ){
        if( !visited[i] ){
            visited[i] = true;
            DFS( i, visited );
        }
    }
}

/*  DFS (privado, recursivo)
        Recorre todas las conecciones de un nodo
            Para toda coneccion con un nodo sin visitar inicia un nuevo nivel de recurcion
        Imprime cada nodo visitado
    Input:
        int current:
            El nodo actual, del cual visitaremos las conecciones
        Puntero a bool visited:
            Un array indicando los nodos que ya fueron visitados
    Complegidad:
        Best Case: lineal O(N) - No tiene conecciones (o pocas)
        Worst Case: cuadratica O(N²) - Todo tiene conecciones
*/
void MyGraph::DFS( int current, bool* visited ){
    cout << current << ",";
    for( int i = 0 ; i < this->matriz[current].size() ; i++ ){
        if( !visited[i] && this->matriz[current][i] != 0 ){
            visited[i] = true;
            DFS( i, visited );
        }
    }
}

/*  BFS - Breadth First Search
        Recorre todos los nodos (exactamente una vez)
            Para todo nodo sin visitar
                Recorre todas las conecciones a nodos que no han sido visitados antes
                Repite el ultimo paso las veces necesarias
        int starting:
            El nodo a partir del cual se comienza la busqueda
        Imprime cada nodo visitado
    Complegidad cuadratica O(N²)
*/
void MyGraph::BFS( int starting ){
    bool visited[ this->size ];
    for( int i = 0 ; i < this->size ; i++ )
		visited[i] = false;
    queue<int> toVisit;
    int current = 0;
    visited[starting] = true;
    toVisit.push(starting);

    for( int i = 0 ; i <= this->matriz.size() ; i++ ){
        while( !toVisit.empty() ){
            current = toVisit.front();
            toVisit.pop();
            char aux = current + 65;
            cout << aux << ",";
            
            for( int ii = 0 ; ii < this->matriz[current].size() ; ii++ ){
                if( !visited[ii] && this->matriz[current][ii] != 0){
                    toVisit.push( ii );
                    visited[ii] = true;
                }
            }
		}
		if( !visited[i] ){
		    visited[i] = true;
			toVisit.push( i );
        }
    }
}

int main(){
    vector<vector<int> > yes={{0,1,1,1,1,0,0,0,0},
                            {0,0,0,0,0,1,0,0,0},
                            {0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,1,0,0},
                            {0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,1,0},
                            {0,0,0,0,0,0,0,0,1},
                            {0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0}};
  
  MyGraph grafo;
	grafo.loadGraph( yes );
	cout << "\n--------DFS--------\n";
    grafo.DFS( 1 );
	cout << "\n--------BFS--------\n";
	grafo.BFS( 1 );
	cout << "\n";
    return 0;
}