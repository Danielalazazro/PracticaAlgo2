//
// Created by daniela on 28/12/22.
//
#ifndef TP2JUAREZ_NODO_H
#define TP2JUAREZ_NODO_H
#include <iostream>

template  <class T> class Nodo{
private:
    T dato;
    Nodo<T>* siguiente;
public:
    /*
     * EL nodo resulta inicializado con el dato dado y sin un Nodo siguiente
     */
    Nodo(T dato){
        this->dato = dato;
        this->siguiente = NULL;
    }
    T obtenerDato(){
        return this->dato;
    }
    Nodo<T>* obtenerSiguiente(){
        return this->siguiente;
    }
    void cambiarSIguiente(Nodo<T>* nuevoSiguiente){
        this->siguiente = nuevoSiguiente;
    }
    void cambiarDato( T nuevoDato){
        this->dato = nuevoDato;
    }
};

#endif //TP2JUAREZ_NODO_H

