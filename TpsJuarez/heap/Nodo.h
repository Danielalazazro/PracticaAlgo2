//
// Created by daniela on 25/01/23.
//

#ifndef TDA_COLA_NODO_H
#define TDA_COLA_NODO_H
#include <iostream>
template <class T> class Nodo{
private:
    T dato;
    Nodo<T>* siguiente;
public:
    Nodo(T dato){
        this->dato = dato;
        this->siguiente = NULL;
    }
    void cambiarSiguiente(Nodo<T>* nuevoNodo){
        this->siguiente = nuevoNodo;
    }

    T getDato(){
        return this->dato;
    }
    void cambiarDato(T nuevoDato){
        this->dato = nuevoDato;
    }
    Nodo<T>* getSiguiente(){
        return this->siguiente;
    }
};

#endif //TDA_COLA_NODO_H
