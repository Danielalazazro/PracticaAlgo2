//
// Created by daniela on 06/01/23.
//

#ifndef TP2JUAREZ_DORMILON_H
#define TP2JUAREZ_DORMILON_H
#include "Personalidad.h"

class Dormilon: public Personalidad{
public:
    Dormilon():Personalidad(){

    }
     void aumentarHambre() {
        Personalidad::aumentarHambre();
        this->porcentajeHambre -= 5;
    }
    void disminurPocentajeBañado(){
        Personalidad::disminurPocentajeBañado();
    }
    std::string getComportamineto(){
        std::string comportamiento;
        comportamiento = "dormilon";
        return comportamiento;
    }
    virtual ~Dormilon(){}

};
#endif //TP2JUAREZ_DORMILON_H
