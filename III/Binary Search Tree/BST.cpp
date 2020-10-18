/*
    Implementacion de un Arbol de Busqueda Binaria Simple (ABB)
        Permite utilizarse como un ADT con sus correspondientes funciones

    
    17 de Octubre de 2020
*/

#include <iostream>
#include <limits>
#include <queue>
#include "BST.h"
using namespace std;

/*
    Constructor:
        Inizializa una nueva instancia con valores fijos
    Complegidad constante O(1)
*/
MyBST::MyBST(){
    this -> size = 0;
    this -> root = nullptr;
}

/*
    Destructor:
        Manda a llamar al metodo recursivo destruct, inisializandolo en la raiz
        Destruye rastro alguno del arbol
    Complegidad constante O(1)
        -Sin contar los metodos llamados dentro de sí
*/
MyBST::~MyBST(){
    destruct(this->root);
}

/* 
    destruct:
        De forma recursiva, elimina todas las posiciones del arbol
        comienza por el hijo izquierdo, hijo derecho, el nodo
    Input:
        pointer a MyNodeBST: El nodo a eliminar (puede ser nullptr)
    Compelgidad lineal O(N)
*/
void MyBST::destruct(MyNodeBST* current){
    if(current){
        destruct(current->left);
        destruct(current->right);
        current->left = nullptr;
        current->right = nullptr;
        delete current;
    }
}
/* 
    lenght:
        Retorna el numero de elementos dentro del arbol
    Compelgidad constante O(1)
*/
int MyBST::length(){
    return this->size;
}

/* 
    isEmpty:
        Determina si hay o no elementos en el arbol
    Compelgidad constante O(1)
*/
bool MyBST::isEmpty(){
    return this->size == 0;
}

/* 
    search:
        Inicializa el metodo recursivo search comenzando con la raiz del arbol
    Input:
        int value: El entero que se desea buscar en el arbol
    Returno:
        Bool, True en caso de encontrar el valor
            False en caso contrario
    Compelgidad constante O(1)
        -Sin contar los metodos llamados dentro de sí
*/
bool MyBST::search(int value){
    return search(value, this->root);
}

/* 
    search:
        Determina, de forma recursiva, si un numero se encuentra dentro del arbol
    Input:
        int value: El entero que se desea buscar en el arbol
        pointer a MyNodeBST: El nodo que se analiza en cada nivel de recursión
    Returno:
        Bool, True en caso de encontrar el valor
            False en caso contrario
    Compelgidad:
        Best Case - O(1)
        Average Case - O(log(N))
        Worst Case - O(N)
*/
bool MyBST::search(int value, MyNodeBST* current){
    if(current){
        if(current->data == value)
            return true;
        if(current->data < value)
            return search(value, current->right);
        else
            return search(value, current->left);
    }
    return false;
}

/* 
    insert:
        Inicializa el metodo recursivo insert comenzando con la raiz del arbol
        Cuando el arbol esta vacio lo comienza
    Input:
        int value: El entero que se desea buscar en el arbol
    Returno:
        Bool, True en caso de incertatr el valor por primera vez
            False en caso de ya haber teido el valor en el arbol
    Compelgidad constante O(1)
        -Sin contar los metodos llamados dentro de sí
*/
bool MyBST::insert(int value){
    if(this->size == 0){
        this->root = new MyNodeBST(value);
        this->size++;
        return true;
    }
    return insert(value, this->root);
}

/* 
    insert:
        Determina, de forma recursiva, si un numero se encuentra dentro del arbol
        En caso de no estar lo inserta como hoja
    Input:
        int value: El entero que se desea insertar en el arbol
        pointer a MyNodeBST: El nodo que se analiza en cada nivel de recursión (potencial padre)
    Returno:
        Bool, True en caso de incertatr el valor por primera vez
            False en caso de ya haber teido el valor en el arbol
    Compelgidad:
        Best Case - O(1)
        Average Case - O(log(N))
        Worst Case - O(N)
*/
bool MyBST::insert(int value, MyNodeBST* current){
    if(current->data == value)
        return false;
    if(current->data < value){
        if(current->right)
            return insert(value, current->right);
        current->right = new MyNodeBST(value);
        this->size++;
        return true;
    }
    else{
        if(current->left)
            return insert(value, current->left);
        current->left = new MyNodeBST(value);
        this->size++;
        return true;
    }
}

/* 
    remove:
        Busca el elemento solicitado y lo elimina
            0 hijos-Hace nulos los hijos del padre
            1 hijos-Redirije al unico hijo
            2 hijos-Sustituye el nodo eliminado con el hijo menor de los hijos mayores
    Input:
        int value: el valor del nodo a eliminar
    Returno:
        Bool, True en caso de eliminar el valor
            False en caso de no encontrarlo
    Compelgidad:
        Best Case: O(1)
        Average Case: O(log(N))
        Worst Case: O(N)
*/
bool MyBST::remove(int value){
    MyNodeBST* current = this->root;
    MyNodeBST* prev = nullptr;
    while(current){
        if(current->data ==  value){
            if(current->right){
                MyNodeBST *menor = current->right,
                          *padre = current;

                while(menor->left){
                    padre = menor;
                    menor = menor->left;
                }
                if(padre->left){
                    padre->left = menor->right;
                    menor->right = nullptr;
                    current->data = menor->data;
                }else{
                    padre->data = menor->data;
                    padre->right = menor->right;
                    menor->right = nullptr;
                }
                delete menor;
                this->size--;
                return true;
            }else if(current->left){
                prev->left = current->left;
                current->left = nullptr;
            }else{
                if(prev){
                    if(prev->data > value){
                        prev->left = nullptr;
                    }else{
                        prev->right = nullptr;
                    }
                }else{
                    this->root = nullptr;
                }
            }
            delete current;
            this->size--;
            return true;
        }
        prev = current;
        if(current->data > value)
            current = current->left;
        else
            current = current->right;
    }
    return false;
}

/* 
    preorder:
        Inicializa el metodo recursivo preorder comenzando con la raiz del arbol
    Compelgidad constante O(1)
        -Sin contar los metodos llamados dentro de sí
*/
void MyBST::preorder(){
    preorder(this->root);
    cout << '\n';
}

/* 
    preorder:
        De forma recursiva, recorre todas las posiciones del arbol
        comienza por el nodo, hijo izquierdo, hijo derecho
    Input:
        pointer a MyNodeBST: El nodo a imprimir (puede ser nullptr)
    Compelgidad lineal O(N)
*/
void MyBST::preorder(MyNodeBST* current){
    if(current){
        cout << current->data << " ";
        preorder(current->left);
        preorder(current->right);
    }
}

/* 
    inorder:
        Inicializa el metodo recursivo inorder comenzando con la raiz del arbol
    Compelgidad constante O(1)
        -Sin contar los metodos llamados dentro de sí
*/
void MyBST::inorder(){
    inorder(this->root);
    cout << '\n';
}

/* 
    inorder:
        De forma recursiva, recorre todas las posiciones del arbol
        comienza por el hijo izquierdo, el nodo, hijo derecho
    Input:
        pointer a MyNodeBST: El nodo a imprimir (puede ser nullptr)
    Compelgidad lineal O(N)
*/
void MyBST::inorder(MyNodeBST* current){
    if(current){
        inorder(current->left);
        cout << current->data << " ";
        inorder(current->right);
    }
}

/* 
    postorder:
        Inicializa el metodo recursivo postorder comenzando con la raiz del arbol
    Compelgidad constante O(1)
        -Sin contar los metodos llamados dentro de sí
*/
void MyBST::postorder(){
    postorder(this->root);
    cout << '\n';
}

/* 
    postorder:
        De forma recursiva, recorre todas las posiciones del arbol
        comienza por el hijo izquierdo, hijo derecho, el nodo
    Input:
        pointer a MyNodeBST: El nodo a imprimir (puede ser nullptr)
    Compelgidad lineal O(N)
*/
void MyBST::postorder(MyNodeBST* current){
    if(current){
        postorder(current->left);
        postorder(current->right);
        cout << current->data << " ";
    }
}

/* 
    level:
        Aplica un BFS en el arbol, imprimiendo cada nodo
        Comenzando por la raiz
    Compelgidad lineal O(N)
*/
void MyBST::level(){
    MyNodeBST* current;
    queue <MyNodeBST*> toVisit;
    toVisit.push(this->root);
    while(!toVisit.empty()){
        current = toVisit.front();
        toVisit.pop();
        if(current){
            cout << current->data << " ";
            toVisit.push(current->left);
            toVisit.push(current->right);
        }
    }
    cout << '\n';
}

/* 
    visit:
        Redirige a otras funciones segun lo solicitado
    Input:
        int type: un valor entre 1 y 4
        1->preorder
        2->inorder
        3->postorder
        4->level
    Compelgidad constante O(1)
        -Sin contar los metodos llamados dentro de sí
*/
void MyBST::visit(int type){
    if(type == 1)
        preorder();
    else if(type == 2)
        inorder();
    else if(type == 3)
        postorder();
    else if(type == 4)
        level();
}

/* 
    height:
        Inicializa el metodo recursivo height comenzando con la raiz del arbol
    Retorno:
        Int: La altura del arbol
    Compelgidad constante O(1)
        -Sin contar los metodos llamados dentro de sí
*/
int MyBST::height(){
    return height(this->root);
}

/* 
    height:
        De forma recursiva, recorre todas los elementos del arbol
        Encuentra al altura de cada nodo en el arbol
            La determina en base a la altura maxima de sus hijos
    Input:
        pointer a MyNodeBST: El nodo que se analiza en cada nivel de recursión (potencial padre)
    Retorno:
        Int: La altura del arbol
    Compelgidad lineal O(N)
*/
int MyBST::height(MyNodeBST* current){
    if(current){
        int left = height(current->left);
        int right = height(current->right);
        return max(left, right) + 1;
    }
    return 0;
}

/* 
    ancestors:
        Busca el elemento solicitado
            Si lo encuentra imprime todos los valores desde la raiz hasta el nodo pedido
            En caso contrario no hace nada
    Input:
        int value: el valor del que se quiere saber los ancestros
    Compelgidad:
        Best Case - O(1)
        Average Case - O(log(N))
        Worst Case - O(N)
*/
void MyBST::ancestors(int value){
    MyNodeBST* current = this->root;
    queue <int> ancestors;
    while(current){
        ancestors.push(current->data);
        if(current->data == value){
            while(!ancestors.empty()){
                cout << ancestors.front() << " ";
                ancestors.pop();
            }
            cout << '\n';
            return;
        }
        if(current->data < value)
            current = current->right;
        else
            current = current->left;
    }
    cout << '\n';
}

/* 
    whatLevelAmI:
        Busca el elemento solicitado
    Input:
        int value: el valor del que se quiere saber el nivel
    Retorno:
        int: el nivel donde se encuentra el nodo (raiz = 1)
            Si no encuentra el elemento retorna -1
    Compelgidad:
        Best Case - O(1)
        Average Case - O(log(N))
        Worst Case - O(N)
*/
int MyBST::whatLevelAmI(int value){
    MyNodeBST* current = this->root;
    int lvl=0;
    while(current){
        lvl++;
        if(current->data == value){
            return lvl;
        }
        if(current->data < value)
            current = current->right;
        else
            current = current->left;
    }
    return -1;
}