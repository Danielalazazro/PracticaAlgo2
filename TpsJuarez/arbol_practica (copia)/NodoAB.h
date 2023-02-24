
// Created by daniela on 17/02/23.
//
#ifndef ARBOL_PRACTICA_NODOAB_H
#define ARBOL_PRACTICA_NODOAB_H
#include "iostream"
#include "insertarDirecto.h"
class NodoAB{
private:
    NodoAB* hijos[3];
    NodoAB* padre;
    int tamanio;
    int capacidadMax;
    int claves[3];
    int cantHijos;
public:
    NodoAB(int maximoVias){
        for(int i = 0; i < maximoVias; i++){
            this->hijos[i] = NULL;
            this->claves[i] = 0;
        }
        this->padre = NULL;
        this->capacidadMax = maximoVias;
        this->cantHijos = 0;
        this->tamanio = 0;
    }
    bool esHoja(){
        return (this->hijos[0] == NULL && this->hijos[1] == NULL && this->hijos[2] == NULL);

    }
    int cantidadHijos(){
        int contador = 0;
        if( hijos[0] != NULL) contador++;
        if( hijos[1] != NULL) contador++;
        if( hijos[2] != NULL) contador++;
        return contador; // cambiar nombre a camtodad de hjijos
    }

    NodoAB* buscarElemento(NodoAB* nodoBuscar, int clave){
        int valorIzq = nodoBuscar->claves[0];
        int valorCentr = nodoBuscar->claves[1];
        int valorDer = nodoBuscar->claves[2];
        if(nodoBuscar->tamanio == 3 ){
            return nodoBuscar->padre;
        }
        if( nodoBuscar->tamanio <= 2 && nodoBuscar->esHoja() ){
            return nodoBuscar;
        }
        else if (nodoBuscar->tamanio == 1 && nodoBuscar->cantidadHijos() == 2 ){
            if(clave < valorIzq ){
                return buscarElemento(nodoBuscar->hijos[0], clave);
            }
            else{
                return buscarElemento(nodoBuscar->hijos[1], clave);
            }
        }

        else if (nodoBuscar->tamanio == 2 && nodoBuscar->cantidadHijos() == 3 ){
            if( clave < valorIzq ){
                return buscarElemento(nodoBuscar->hijos[0], clave);
            }
            else if ( clave > valorIzq && clave < valorCentr){
                return buscarElemento(nodoBuscar->hijos[1], clave);
            }
            else{
                return buscarElemento(nodoBuscar->hijos[2], clave);
            }
        }
    }

    void buscar(int clave){
        NodoAB* nodoAB = buscarElemento(this, clave);
    }
    void ordenarClaves() {
        for(int i = 1; i < this->capacidadMax; i++){
            for(int j = 0; j < this->capacidadMax-1 ; j++){
                if(this->claves[j] > this->claves[j + 1]){
                    int aux = this->claves[j];
                    this->claves[j] = this->claves[j + 1];
                    this->claves[j + 1] = aux;
                }
            }
        }

    }
    void insertarDirecto(int valor){
        int i = 0;
        while (i < this->capacidadMax) {
            if (this->claves[i] == 0) {
                this->claves[i] = valor;
                break;
            }
            i++;
        }
        this->tamanio++;
        this->ordenarClaves();
    }

    bool sePuedeAgregar() {
        return(this->tamanio <= 2);
    }

    void vaciarNodo() {
        for(int i = 0; i < this->capacidadMax; i++ ) {
            this->claves[i] = 0;
        }
        this->tamanio = 0;

    }
    void insercion(int valor){
        NodoAB* posAgregar = buscarElemento(this, valor);

        if(posAgregar->sePuedeAgregar() && posAgregar->esHoja()){
            posAgregar->insertarDirecto(valor);
            if(posAgregar->tamanio == 3 ){
                if(posAgregar->padre == NULL){
                    NodoAB* izquierdo = new NodoAB(3);
                    NodoAB* derecho = new NodoAB(3);
                    int valorDenuevoPadre = posAgregar->claves[1];
                    int valorIzq = posAgregar->claves[0];
                    int valorDer = posAgregar->claves[2];
                    posAgregar->hijos[0] = izquierdo;
                    posAgregar->hijos[1] = derecho;
                    izquierdo->insertarDirecto(valorIzq);
                    derecho->insertarDirecto(valorDer);
                    posAgregar->vaciarNodo();
                    posAgregar->insertarDirecto(valorDenuevoPadre);
                    izquierdo->padre = posAgregar;
                    derecho->padre = posAgregar;
                    return;
                }
                else if(posAgregar->padre){
                        NodoAB* nodoMedio = new NodoAB(3);
                        int valorAgregarPadre = posAgregar->claves[1];
                        int valorAgregarMedio = posAgregar->claves[0];
                        int valorAgregarDerecho = posAgregar->claves[2];
                        bool padreSplit = false;
                        if(posAgregar->padre->tamanio == 2 ){
                            padreSplit = true;
                        }
                        posAgregar->padre->insercion(valorAgregarPadre);
                        if(padreSplit){
                            posAgregar->padre == NULL;
                            //delete posAgregar;
                            return;
                        }
                        else{
                            posAgregar->padre->hijos[1] = nodoMedio;
                            nodoMedio->insercion(valorAgregarMedio);
                            posAgregar->padre->hijos[2] = posAgregar;
                            posAgregar->vaciarNodo();
                            posAgregar->insercion(valorAgregarDerecho);
                        }
                }
            }
        }
        // entro aca cuando soy raiz y tengo tamanio == 2  y 3 hijos. (por supuesto que no soy hoja)
        else if(posAgregar->tamanio <= 2 ){
            if(posAgregar->tamanio == 1 ){
                posAgregar->insertarDirecto(valor);
                return;
            }
            posAgregar->insertarDirecto(valor);
            //tenia tamanio 2 y ahora agrege un elemento y tiene tamanio 3
            // y aca vamos a splitear
            //valor de nuevo padre:
            // esto haces  cuando tenes el padre null. pero cuando no lo tenes que haces?
            if(!posAgregar->padre){
                int valorPadreNuevo = posAgregar->claves[1];
                int valorIzq = posAgregar->claves[0];
                int valorDer = posAgregar->claves[2];
                int valorHijoIzq = posAgregar->hijos[2]->claves[0];
                //int valorHijoMedio = posAgregar->hijos[2]->claves[1];
                int valorHijoDerech = posAgregar->hijos[2]->claves[2];
                //Creo los hijos del padre:
                NodoAB* izqueirdo = new NodoAB(3);
                NodoAB* derecho = new NodoAB(3);
                NodoAB* izqDelHijoDer = new NodoAB(3);
                //inserto sus valores de los hijos del nuevo padre:
                izqueirdo->insertarDirecto(valorIzq);
                derecho->insertarDirecto(valorDer);
                //inserto un valor al hijo iz del padre que a su vezz es el hijosizq del izq:
                izqDelHijoDer->insertarDirecto(valorHijoIzq);
                // realizo los enlaces a los padres con los hijos:
                izqueirdo->hijos[0] = posAgregar->hijos[0];
                posAgregar->hijos[0]->padre = izqueirdo;
                izqueirdo->hijos[1] = posAgregar->hijos[1];
                posAgregar->hijos[1]->padre = izqueirdo;
                derecho->hijos[0] = izqDelHijoDer;
                izqDelHijoDer->padre = derecho;
                posAgregar->hijos[2]->vaciarNodo();
                posAgregar->hijos[2]->insertarDirecto(valorHijoDerech);
                derecho->hijos[1] = posAgregar->hijos[2];
                posAgregar->hijos[2]->padre = derecho;
                posAgregar->vaciarNodo();
                posAgregar->insertarDirecto(valorPadreNuevo);
                posAgregar->hijos[0] = izqueirdo;
                posAgregar->hijos[1] = derecho;
                posAgregar->hijos[2] = NULL;
                izqueirdo->padre = posAgregar;
                derecho->padre = posAgregar;
                //posAgregar->hijos[2]->padre = NULL;
                return;
            } else if(posAgregar->padre){
                int valorPrimero = posAgregar->claves[0];
                int valorSeg = posAgregar->claves[1];
                int valorUltimo = posAgregar->claves[2];
                int valorIzqDelHijo = posAgregar->hijos[2]->claves[0];
                int valorMedDelHijo = posAgregar->hijos[2]->claves[1];
                int valorDerDelHijo = posAgregar->hijos[2]->claves[2];
                posAgregar->padre->insertarDirecto(valorSeg);
                if(posAgregar->tamanio == 3){
                    NodoAB* nodoMedioHijo = new NodoAB(3);
                    NodoAB* izqHijoDer = new NodoAB(3);
                    nodoMedioHijo->insertarDirecto(valorPrimero);
                    izqHijoDer->insertarDirecto(valorIzqDelHijo);
                    posAgregar->padre->hijos[1] = nodoMedioHijo;
                    nodoMedioHijo->padre = posAgregar->padre;
                    nodoMedioHijo->hijos[0] = posAgregar->hijos[0];
                    nodoMedioHijo->hijos[1] = posAgregar->hijos[1];
                    posAgregar->hijos[0]->padre = nodoMedioHijo;
                    posAgregar->hijos[1]->padre = nodoMedioHijo;
                    posAgregar->vaciarNodo();
                    posAgregar->insertarDirecto(valorUltimo);
                    posAgregar->padre->hijos[2] = posAgregar;
                    posAgregar->hijos[2]->vaciarNodo();
                    posAgregar->hijos[2]->insertarDirecto(valorDerDelHijo);
                    posAgregar->hijos[0] = izqHijoDer;
                    izqHijoDer->padre = posAgregar;
                    posAgregar->hijos[1] = posAgregar->hijos[2];
                }
            }
        }
        else if (tamanio == 1 ){
            posAgregar->insertarDirecto(valor);
        }
    }
    void imprimirNodo(NodoAB* unNodo){
        std::cout << " [ ";
        std::cout << unNodo->claves[0] << " ";
        std::cout << unNodo->claves[1] << " ";
        std::cout << unNodo->claves[2] << " ";
        std::cout << " ] \n";

    }
    // hacer el in order.
    void imprimiArbol(NodoAB* unNodo){
        if(!unNodo) return;
        imprimirNodo(unNodo);
        if(unNodo->hijos[0]){
            std::cout << "Primer Hijo cuyo Padre arranca en  " << unNodo->claves[0] << "  " ;
            imprimiArbol(unNodo->hijos[0]);
        }
        if(unNodo->hijos[1]){
            std::cout << "Segundo Hijo cuyo Padre arranca en   " << unNodo->claves[0] << "  ";
            imprimiArbol(unNodo->hijos[1]);
        }
        if(unNodo->hijos[2]){
            std::cout << "Tercer Hijo cuyo Padre arranca en  " << unNodo->claves[0] << "  " ;
            imprimiArbol(unNodo->hijos[2]);
        }
    }
    void imprimir(){
        imprimiArbol(this);
   }


};
#endif //ARBOL_PRACTICA_NODOAB_H
