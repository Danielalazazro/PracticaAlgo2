// Created by daniela on 14/02/23.
#ifndef ARBOL_PRACTICA_NODO_H
#define ARBOL_PRACTICA_NODO_H
#include <string>
enum EstadoDeNodo{
    Ocupado,
    Desocupado,
};
class Nodo{
private:
    Nodo* siguiente;
    int valor;
    EstadoDeNodo estado;
public:
    Nodo(int valor){
        this->valor = valor;
        this->siguiente = NULL;
        this->estado = Desocupado;
    }
    Nodo* getSiguiente(){
        return this->siguiente;
    }
    void setSiguiente(Nodo* nuevoSiguiente){
        this->siguiente = nuevoSiguiente;
    }
    const int & getValor() const{
        return this->valor;
    }
    void setAnterior( Nodo* nuevoAnterior){
        this->siguiente = nuevoAnterior;
    }
    void setValor(int valorNuevo){
        this->valor = valorNuevo;
    }
    bool estaDesocupada() {
        return this->estado == Desocupado;
    }
};
#endif //ARBOL_PRACTICA_NODO_H
