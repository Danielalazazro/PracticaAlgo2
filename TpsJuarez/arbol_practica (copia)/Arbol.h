//
// Created by daniela on 14/02/23.
//

#ifndef ARBOL_PRACTICA_ARBOL_H
#define ARBOL_PRACTICA_ARBOL_H
#include "Nodo.h"
#include "NodoAB.h"
#include <iostream>
class Arbol{
private:
    Nodo* raiz;
    int capacidadMaximaDelNodo;
    Nodo* primerHijo;
    Nodo* segundoHijo;
    Nodo* tercerHijo;

public:
    Arbol(int capacidad){
        this->capacidadMaximaDelNodo = capacidad;
        this->raiz = NULL;
    }

    void recorrer(Nodo* nodo){
        std::cout<< nodo->getNombre()<<std::endl;
        if(nodo->getCantidadHijo() > 0){
            Nodo* i = nodo->getHijo();
            while (i != NULL){
                recorrer(i);
                i = i->getSiguiente();
            }
        }
    }

    const Nodo* getRaiz(){
        return this->raiz;
    }
    void setRaiz( Nodo* raiz){
        this->raiz = raiz;
    }
    void agregarNodo(std::string nombre){
        Nodo* nuevo = new Nodo(nombre);
    }
};
#endif //ARBOL_PRACTICA_ARBOL_H
