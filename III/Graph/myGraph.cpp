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

/*  topologicalSort
        Para todo nodo con grado de entrada igual a 0:
            Reducir el grado de entrada de todos los nodos
    Complegidad:
        Worst Case - cuadratica O(N²) : Recorre todos los vertices y aristas
*/
void MyGraph::topologicalSort(){
    bool visited[ this->size ];
    int daddys[ this->size ];
    queue<int> toVisit;
    int current = 0;
    for( int i = 0 ; i < this->size ; i++ ){
		visited[i] = false;
        daddys[i] = 0;
    }
    for( int i = 0 ; i < this->size ; i++ )
        for ( int ii = 0 ; ii < this->matriz[i].size() ; ii++ ){
            if( this -> matriz[i][ii] != 0 )
                daddys[ ii ]++;
        }
    for( int i = 0 ; i < this->size ; i++ ){
        if ( daddys[i] == 0 ){
            toVisit.push(i);
            visited[i] = true;
        }
    }
    while( !toVisit.empty() ){
        current = toVisit.front();
        toVisit.pop();
        cout<<current<<",";
        for( int ii = 0 ; ii < this->matriz[current].size() ; ii++ ){
            if( matriz[current][ii] != 0 ){
                daddys[ii]--;
                if( daddys[ii] == 0 ){
                    visited[ii] = true;
                    toVisit.push( ii );
                }
            }
        }
    }
}

/*  isTree
        Recorre la matriz de adyasencia
            Si encuentra dos conecciones en una columna retorna falso
                Si hay ciclos dentro del grafo retorna falso
            En caso contrario retorna verdadero
        Asume que el nodo raiz siempre sera el nodo 0
    Output:
        bool:
            Representacion de si es o no un arbol N-ario, True = si ; False = no
    Complegidad:
        Best Case - lineal O(N) : los primeros dos nodos visitados estan conectas bidireccionalmente
        Worst Case - cuadratica O(N²) : si es un arbol
*/
bool MyGraph::isTree(){
    bool visited[ this->size ];
    for( int i = 0 ; i < this->size ; i++ )
		visited[i] = false;
    queue<int> toVisit;
    int current = 0;

    visited[ 0 ] = true;
    toVisit.push( 0 );

    while( !toVisit.empty() ){
        current = toVisit.front();
        toVisit.pop();
        
        for( int ii = 0 ; ii < this->matriz[current].size() ; ii++ ){
            if( !visited[ii] && this->matriz[current][ii] != 0 ){
                toVisit.push( ii );
                visited[ii] = true;
            }
            else if( visited[ii] && this->matriz[current][ii] != 0 )
                return false;
        }
    }
    return true;
}

/*  bipartiteGraph
        Para todo nodo sin visitar:
            Lo asigna a un subconjunto de nodos
                A todas sus conecciones las asigna a un subconjunto opuesto
    Output:
        bool:
            Representacion de si es o no un grafo bipartito, True = si ; False = no
    Complegidad:
        Worst Case - cuadratica O(N²) : Recorre todos los vertices y aristas
*/
bool MyGraph::bipartiteGraph(){
    bool visited[ this->size ];
    bool type[ this->size ];
    for( int i = 0 ; i < this->size ; i++ ){
		visited[i] = false;
        type[i] = false;
    }
    queue<int> toVisit;
    int current = 0;

    for( int i = 0 ; i < this->matriz.size() ; i++ ){
		if( !visited[i] ){
		    visited[i] = true;
			toVisit.push( i );
            while( !toVisit.empty() ){
                current = toVisit.front();
                toVisit.pop();
                for( int ii = 0 ; ii < this->matriz[current].size() ; ii++ ){
                  if( this->matriz[current][ii] != 0 ){
                    if( !visited[ii]){
                        toVisit.push( ii );
                        visited[ ii ] = true;
                        type[ ii ] = !type[ current ];
                    }
                    else if( type[ii] == type[current] )
                        return false;
                }
                }
            }
        }
    }
    return true;
}

int main(){
    vector<vector<int> > mientras={
    {0,1,1,1,1,0,0,0,0},
    {0,0,0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0}};

    MyGraph grafo;
    grafo.loadGraph(mientras);
    if( grafo.isTree() )
        cout<<"Es Arbol\n";
    else
        cout<<"No es Arbol\n";

    if( grafo.bipartiteGraph() )
        cout<<"Es bipartito\n";
    else
        cout<<"No es bipartito\n";

    cout<<"---Orden Topologico\n";
    grafo.topologicalSort();
    return 0;
}