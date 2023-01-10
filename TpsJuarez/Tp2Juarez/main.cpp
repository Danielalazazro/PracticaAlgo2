#include <iostream>
#include "RescateDeAnimales.h"
#include "Gato.h"
#include "Perro.h"
#include "Conejo.h"
#include "Caballo.h"
#include "Erizo.h"
#include "Largatija.h"
#include "Roedor.h"
int main(){

    RescateDeAnimales* rescateDeAnimales = new RescateDeAnimales();
    rescateDeAnimales->iniciarRescateYAdopccion();
    delete rescateDeAnimales;
    return 0;
}
