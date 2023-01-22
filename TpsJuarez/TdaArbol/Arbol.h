//
// Created by daniela on 20/01/23.
//

#ifndef EJERCICIOSARBOLES_ABOLES_H
#define EJERCICIOSARBOLES_ABOLES_H
#include <string>
#include <iostream>

class Arbol{
private:
    Arbol* izquierdo;
    Arbol* derecha;
    std::string clave;
    int dato;
    int tamanio;

public:
    Arbol(std::string clave, int dato){
        this->clave = clave;
        this->dato = dato;
        this->tamanio = 1;
        this->izquierdo = NULL;
        this->derecha = NULL;
    }
    void agregar(std::string claveNueva, int nuevoValor){
        Arbol*padre = NULL;
        std::string nuevaOrinetacion = " ";
        Arbol* nodoNuevo = buscarClaveInterna(claveNueva,&padre,&nuevaOrinetacion);
        if(nodoNuevo != NULL){
            std::cout <<"No se puede agregar este nodo "<<std::endl;
            return;
        }
        if(nuevaOrinetacion == "I" ){
            padre->izquierdo = new Arbol(claveNueva, nuevoValor);
        }
        else if(nuevaOrinetacion == "D"){
            padre->derecha = new Arbol(claveNueva, nuevoValor);
        }

    }

    Arbol* buscarClaveInterna(std::string claveBuscada, Arbol** padre, std::string* orientacion ){
        if(claveBuscada < this->clave){
            (*orientacion) = "I";
            if(this->izquierdo == NULL){
                (*padre) = this;

                return NULL;
            }
            (*padre) = this;
            return this->izquierdo->buscarClaveInterna(claveBuscada, padre, orientacion);
        }
        else if( claveBuscada > this->clave){
            (*orientacion) = "D";
            if(this->derecha == NULL){
                (*padre) = this;
                return NULL;
            }
            (*padre) = this;
            return this->derecha->buscarClaveInterna(claveBuscada, padre, orientacion);
        }
        return this;
    }

    bool buscarClave(std::string claveBuscada){
        std::string orientacion = "";
        Arbol* padre = NULL;
        Arbol* arbolRetornado = buscarClaveInterna(claveBuscada, &padre, &orientacion);
        return (arbolRetornado != NULL);
    }
    int cantidadHijos( ){
        int contador = 0;
        if( this->izquierdo ) contador++;
        if( this->derecha ) contador++;

        return contador;
    }

    void eliminarSinHijos(Arbol *arbolAeliminar, Arbol *padre, std::string orientacion) {

            if(padre == NULL){
                delete arbolAeliminar;

            }
            if(orientacion == "I"){
                padre->izquierdo = NULL;
                delete arbolAeliminar;
            }
            else{
                padre->derecha = NULL;
                delete arbolAeliminar;
            }

    }

    void eliminarConUnHijo(Arbol *arbolAeliminar, Arbol *padre, std::string orientacion) {
        Arbol* nodoReempl = NULL;
        if(arbolAeliminar->derecha && !arbolAeliminar->izquierdo){
            nodoReempl = arbolAeliminar->derecha;
        }
        else if(!arbolAeliminar->derecha && arbolAeliminar->izquierdo) {
            nodoReempl = arbolAeliminar->izquierdo;
        }

        if(orientacion == "I"){
            padre->izquierdo= nodoReempl ;
        }
        else {
            padre->derecha = nodoReempl;
        }
        delete arbolAeliminar;
    }

    void eliminarConUnoOsinHijos(Arbol *arbolReempl, Arbol *padreReempl, std::string orientacionReempl, bool* estaEliminado) {
        int cantHijosArbolReempl = arbolReempl->cantidadHijos();
        if( cantHijosArbolReempl == 0 ){
            eliminarSinHijos(arbolReempl, padreReempl, orientacionReempl);
            *estaEliminado = true;
        }
        else if (cantHijosArbolReempl == 1 ){
            eliminarConUnHijo(arbolReempl, padreReempl, orientacionReempl);
            *estaEliminado = true;
        }
    }

    void eliminarConDosHijos(Arbol *arbolELiminar, Arbol *padre, std::string orientacion) {
        Arbol* arbolReemplazate = arbolELiminar->derecha;
        bool estaEliminado = false;
        while (arbolReemplazate->izquierdo){
            arbolReemplazate = arbolReemplazate->izquierdo;
        }
        std::string claveBackup = arbolReemplazate->getClave();
        int valorBackup = arbolReemplazate->getDato();
        Arbol* padreReemplaz = NULL;
        std::string orientReemplz = " ";
        buscarClaveInterna(claveBackup, &padreReemplaz, &orientReemplz );
        eliminarConUnoOsinHijos(arbolReemplazate, padreReemplaz, orientReemplz,&estaEliminado );
        arbolELiminar->setCambios(claveBackup,valorBackup);

    }

    void eliminar(std::string claveAEliminar){

        Arbol* padre = NULL;
        std::string orientacion = " ";
        bool estaEliminado = false;
        Arbol* arbolRetornado = buscarClaveInterna(claveAEliminar, &padre, &orientacion);
        if(arbolRetornado == NULL){
            std::cout<<"No existe la clave  " << claveAEliminar << " en el arbol\n";
            return;
        }
        eliminarConUnoOsinHijos(arbolRetornado, padre, orientacion, &estaEliminado);
        // verifico que no sea false el estaeliminado 1ª para luego ver la cantidad de hijos.
        if (  !estaEliminado && arbolRetornado->cantidadHijos() == 2  ){
            eliminarConDosHijos(arbolRetornado,padre,orientacion);
        }

    }

    void recorridoInOrder(Arbol* unArbol){
        if(unArbol == NULL) return;
        recorridoInOrder(unArbol->izquierdo);
        std::cout << unArbol->clave <<"\n";
        recorridoInOrder(unArbol->derecha);

    }

    void inorder(){
        recorridoInOrder(this);
        std::cout<<"Finalizo\n"<<std::endl;
    }

    void setCambios(std::string claveNueva, int nuevoDato){
        this->clave = claveNueva;
        this->dato = nuevoDato;
    }

    std::string getClave(){
        return clave;
    }

    int getDato(){
        return this->dato;
    }
    void recorridoPostOrder(Arbol *arbolActual){

        if(arbolActual == NULL){
            return;
        }
        recorridoPostOrder(arbolActual->izquierdo);
        recorridoPostOrder(arbolActual->derecha);
        if(arbolActual->getClave() == this->getClave() ){
            return;
        }
        this->eliminar(arbolActual->getClave());

    }
    void destruirArbol(){
        recorridoPostOrder(this);
    }
    ~Arbol(){

    }

};
#endif //EJERCICIOSARBOLES_ABOLES_H
