#include <iostream>
#include "Heap.h"
int main() {
    Heap* unHeap = new Heap(10);
    unHeap->encolar(1);
    unHeap->encolar(15);
    unHeap->encolar(11);
    unHeap->encolar(9);
    unHeap->encolar(12);
    unHeap->desencolar();
    unHeap->desencolar();
    unHeap->desencolar();
    unHeap->imprimir();
    //std::cout<<"EL maximo es:"<<unHeap->heapVerMax()<<std::endl;
    delete unHeap;
    return 0;
}
