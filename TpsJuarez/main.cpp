#include <iostream>
#include <fstream>
#include <string>
#include "Libro.h"
#include "Libreria.h"
using namespace std;
int main() {
    Libreria* libreria = new Libreria(10);
    libreria->iniciarJuego();
    delete libreria;

     return 0;
}
