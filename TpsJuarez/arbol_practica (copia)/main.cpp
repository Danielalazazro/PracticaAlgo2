#include <iostream>
#include "NodoAB.h"
/*struct Nodo{
    int valor;
    Nodo* izquierdo;
    Nodo* medio;
    Nodo* derecho;

    Nodo(int valor){
        this->valor = valor;
        this->izquierdo = NULL;
        this->derecho = NULL;
        this->medio = NULL;
    }
};
Nodo* insert(Nodo* root, int value){
    if(root == NULL){
        return  new Nodo(value);
    }
    if(value < root->valor){
        root->izquierdo = insert(root->izquierdo, value);
    }
    else if(value > root->valor){
        root->derecho = insert(root->derecho, value);
    } else{
        root->medio = insert(root->medio,value);
    }
    return root;
}
void imprimirInOrder(Nodo* root){
    if(root == NULL){
        return;
    }
    imprimirInOrder(root->izquierdo);
    std::cout<<root->valor<<" ";
    imprimirInOrder(root->medio);
    imprimirInOrder(root->derecho);


}*/
int main() {

    NodoAB* nodos = new NodoAB(3);
    nodos->insercion(5);
    nodos->insercion(4);
    nodos->insercion(9);
    nodos->insercion(12);
    nodos->insercion(14);
    nodos->insercion(19);
    nodos->insercion(30);
    nodos->insercion(40);
    nodos->insercion(50);
    nodos->insercion(70);
    nodos->insercion(80);




    nodos->imprimir();
    //nodos->insertarDirecto(6);
    //nodos->insertarDirecto(9);
    //nodos->agregarHijo("C");

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
