#include <iostream>
#include "Arbol.h"
int main() {
    Arbol* arbol = new Arbol("pepe",5);
    arbol->agregar("mago",7);
    arbol->agregar("mari",2);
    arbol->agregar("tito",10);
    arbol->agregar("beto",1);
    arbol->agregar("alfa",12);
    arbol->agregar("queca",6);
    arbol->agregar("quiko",8);
    arbol->inorder();
    arbol->eliminar("mago");
    arbol->eliminar("pepe");
    arbol->eliminar("lolo");
    arbol->inorder();
    arbol->destruirArbol();
    delete arbol;
    return 0;
}
