//
// Created by daniela on 28/12/22.
//

#ifndef TP2JUAREZ_LISTA_H
#define TP2JUAREZ_LISTA_H
#include "Nodo.h"
template<class T> class Lista{
    Nodo<T>* primero;
    unsigned int tamanio;
    Nodo<T>* cursor;
public:
    /*
     * pre: inicializamos la lista vacia
     */
    Lista();
    /*
     * pos:indica si la lista tiene algun elemento
     */
    bool estaVacia();
    /*
     * pos: devulve la cantidad de elemntos que tinene la lista
     */
    unsigned int contarElemntos();
    /*
     * pos: agrega el elemento al final de la lista , en la posicion:
     * contarElemento() + 1.
     */
    void agregar(T elemnto);
    /*
     * pre: posicion pertenece al intervalo :[1, contarElemento() + 1]
     * pos: agrega el elemnto al final de la lista , en la posicion indicada
     */
    T obtener(unsigned int posicion);
    /*
     * pre: posicion pertenece al intervalo :[1, contarElementos()]
     * pos: cambia el elemento en la posicion indicada por el elemento dado
     */
    void agregar( T elemento, unsigned int posicion );
    /*
     * pre:posicion pertence al intervalo:[1, contarElementos()]
     * pos: remueve de la lista el elemento en la posicion indicada.
     */
    void remover(unsigned int posicion);
    /*
     * pre:-
     * pos: deja el cursor de la lista preparado para hacer
     * un nuevo recorrido sobre sus elementos.
     */
    void iniciarCursor();
    /*
     * pre:se ha iniciado el recorrido(invocando el metodo iniciar cursor)
     * y desde entonces no se han agregado o remivido
     *
     * pos: mueve el cursor y lo posiciona en el siguiente elemento del
     *      recorrido. r
     *      El valor de retorno indica si el cursor quedo posicionado sobre
     *      un elemento o no (en caso de que la lista este vacia o no existan mas elementos por recorrer)
     */
    bool avanzarCursor();
    /*
     * pre: el cursor esta posicionado sobre un elemento de la lista ,
     *      (fur invocado el metodo avanzarCursor() y devolvio true)
     * pos: devulve el elemento en la posicion del cursor.
     */
    T obtenerCursor();

    /*
     * pos: libera  los recursos asociados a la lista
     */
    ~Lista();
private:
    /*
     * pre: posicion pertenece al intervalo :[1,contarElemento()]
     * pos: devulve el nodo en la posicion indicada
     */
    Nodo<T>* obtenerNodo(unsigned int posisicon);
};
template<class T> Lista<T>::Lista(){
    this->primero = NULL;
    this->tamanio = 0;
    this->cursor = NULL;

}
template<class T> bool Lista<T>::estaVacia() {
    return (this->tamanio == 0);
}
template<class T> unsigned int Lista<T>::contarElemntos() {
    return this->tamanio;
}
template<class T> void Lista<T>::agregar(T elemnto, unsigned int posicion) {
    //agrega adelante de la lista
    if ((posicion > 0) && (posicion <= this->tamanio + 1 )) {
        Nodo<T> *nuevo = new Nodo<T>(elemnto);
        if (posicion == 1) {
            nuevo->cambiarSIguiente(this->primero);
            this->primero = nuevo;

        } else {
            Nodo<T> *anterior = this->obtenerNodo(posicion - 1);
            nuevo->cambiarSIguiente(anterior->obtenerSiguiente());
            anterior->cambiarSIguiente(nuevo);

        }
        this->tamanio++;
        //delete nuevo;
        /* cualquier recorrido actual queda invalido*/
        this->iniciarCursor();
    }
}
template<class T> T Lista<T>::obtener(unsigned int posicion) {
    T elemento;
    if((posicion > 0) && (posicion <= this->tamanio)){
        elemento = this->obtenerNodo(posicion)->obtenerDato();
    }
}
template<class T> void Lista<T>::remover(unsigned int posicion) {
    if((posicion > 0 ) && (posicion <= this->tamanio)){
        Nodo<T>* removido;
        if(posicion == 1){
            removido = this->primero;
            this->primero = removido->obtenerSiguiente();
        }
        else{
            Nodo<T>* anterior = this->obtenerNodo(posicion - 1);
            removido = anterior->obtenerSiguiente();
            anterior->cambiarSIguiente(removido->obtenerSiguiente());

        }
        delete removido;
        this->tamanio--;

        this->iniciarCursor();
    }
}
template<class T> Lista<T>:: ~Lista() {
    while (this->primero != NULL){
        Nodo<T>* aBorrar = this->primero;
        this->primero = this->primero->obtenerSiguiente();
        delete aBorrar;
    }
}
template<class T> Nodo<T>* Lista<T>::obtenerNodo(unsigned int posisicon) {
    Nodo<T>* actual = this->primero;
    for(unsigned int i = 1; i < posisicon; i++){
        actual = actual->obtenerSiguiente();
    }
    return actual;
}
template<class T> void Lista<T>::iniciarCursor() {
    this->cursor = NULL;
}
template<class T> T Lista<T>::obtenerCursor() {
    T elemento;
    //agrgar un if cuando a sea null colocar null
    if(this->cursor != NULL){
        elemento = this->cursor->obtenerDato();
    }
    return elemento;
}
template<class T> bool  Lista<T>::avanzarCursor() {
    if(this->cursor == NULL){
        this->cursor = this->primero;
    }
    else{
        this->cursor = this->cursor->obtenerSiguiente();
    }
    /*puedo avanzar si el cursor ahora apunta a un nodo*/
    return (this->cursor !=NULL);
}
template<class T> void Lista<T>::agregar(T elemnto) {
    this->agregar(elemnto, this->tamanio + 1);
}
#endif //TP2JUAREZ_LISTA_H
