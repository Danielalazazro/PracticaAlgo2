//
// Created by daniela on 21/02/23.
//
#ifndef ARBOL_PRACTICA_NODOPOSYACTUAL_H
#define ARBOL_PRACTICA_NODOPOSYACTUAL_H
#include "NodoAB.h"
class NodoPosyAct{
private:
    NodoAB* actual;
    int posicionActual;
public:
    NodoPosyAct(){
        this->actual = NULL;
        this->posicionActual = 0;
    }
    void setearActual(NodoAB* nodoNuevo){
        this->actual = nodoNuevo;
    }
    void setearPoscion(int pos){
        this->posicionActual = pos;
    }
    int getPosicion(){
        return this->posicionActual;
    }
    NodoAB* getActual(){
        return this->actual;
    }
};
#endif //ARBOL_PRACTICA_NODOPOSYACTUAL_H
