
#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H
#include <iostream>
class Heap{
private:

    int cantidad;
    int* vec;
    int tope;

public:
    Heap(int maximoDeVec){
        this->cantidad = 0;
        this->vec = new int [maximoDeVec];
        this->tope = maximoDeVec;
    }

    int heapCantidad( ){
        return this->cantidad;
    }

    bool heapEstaVacio(){
        return this->cantidad == 0;
    }
    void heapSwap(int posicionPadre, int posicionHijo){

        int auxValorPadre = this->vec[posicionPadre];
        this->vec[posicionPadre] = this->vec[posicionHijo];
        this->vec[posicionHijo] = auxValorPadre;

    }

    void uphead(int posicionHijo){

        if(posicionHijo <= 0 ){
            return;
        }
        int posicionPadre = getPosicionPadre(posicionHijo);
        if(this->vec[posicionPadre] > this->vec[posicionHijo]){
            heapSwap(posicionPadre , posicionHijo);
            uphead(posicionPadre);
        }
    }

    bool encolar(int elemento){
        if(cantidad == tope) return false;
        int poscionAgregar = this->cantidad;
        this->vec[poscionAgregar] = elemento;
        this->cantidad++;
        uphead(poscionAgregar);

        return true;
    }

    int heapVerMax(){
        if(this->cantidad == 0){
            return 0;
        }
        int maximo = this->vec[0];
        for(int i = 0; i < this->cantidad; i++){
            if(this->vec[0] < vec[i]){
                maximo = this->vec[i];
            }
        }
        return maximo;


    }

    int minimoNum(int numero1, int numero2){
        int minimo1 = numero1;

        if(this->vec[numero1] < this->vec[numero2]){
            minimo1 = numero1;
        }
        else if(this->vec[numero2] < this->vec[numero1]){
            minimo1 = numero2;
        } //recibes poosicones no numeros ojo !
        return minimo1;
    }
    int buscarMinimo( int posPadre, int posHijoIzq, int posHijoDer){

        int minimo1 = minimoNum(posPadre, posHijoIzq);
        int minimoTotal = minimoNum( minimo1, posHijoDer);
        return minimoTotal;
        // es posMin lkas variables
    }


    void downheap(int posicionPadre){
        //En una funcion recursiva tengo que evaluar el argument que me pasan , si no llega a la final de arreglo
        if(posicionPadre == this->cantidad-1){
            return;
        }
        int hijoIzquierdo = getPosHijoIzq(posicionPadre);
        int hijoDerecho = getPosHijoDerch(posicionPadre);

        int min = buscarMinimo(posicionPadre,hijoIzquierdo, hijoDerecho);
        if(min != posicionPadre ){
            heapSwap(posicionPadre, min);
            downheap(min);
        }
    }

    void desencolar(){

        this->vec[0] = this->vec[cantidad - 1];
        cantidad--;
        int posPadre = getPosicionPadre(getPosElemento(vec[0]));
        downheap(posPadre);


    }
    int getPosElemento(int elemento){
        if(cantidad == tope) return -1;
        for(int i =  0 ; i < tope ; i++ ){
            if(elemento == vec[i]){
                return i;
            }
        }
        return -1;
    }
    int getPosicionPadre(int unaPosicion){
        int posPadre = (unaPosicion - 1)/2;
        return posPadre;
    }
    int getPosHijoIzq(int posicionPadre){

        int posicionHijo = 2 * posicionPadre + 1;
        return posicionHijo;
    }
    int getPosHijoDerch(int posicionPadre){

        int posicionHijoDer = 2 * posicionPadre + 2;
        return posicionHijoDer;
    }
    void imprimir(){
        if(this->cantidad == 0){
            return;
        }
        for(int i = 0; i < this->cantidad; i++){
            std::cout<< this->vec[i]<<std::endl;
        }
    }


    ~Heap(){
        delete[] this->vec;
    }

};
#endif //HEAP_HEAP_H
