//
// Created by daniela on 06/01/23.
//

#ifndef TP2JUAREZ_TRAVIESO_H
#define TP2JUAREZ_TRAVIESO_H
#include "Personalidad.h"

class Travieso: public Personalidad{
public:
    Travieso():Personalidad(){
    }
    virtual void aumentarHambre(){
       Personalidad::aumentarHambre();
    }
    virtual void disminurPocentajeBañado(){
        Personalidad::disminurPocentajeBañado();
        this->porcentajeBañado -= 10;
        if(this->porcentajeBañado < 0){
            this->porcentajeBañado = 0;
        }
    }
    std::string getComportamineto(){
        std::string comportamiento;
        comportamiento = "travieso";
        return comportamiento;
    }
    int getPorcentajeHambre(){
        return this->porcentajeHambre;
    }
    int getPorcentajeBañado(){
        return this->porcentajeBañado;
    }
    virtual ~Travieso(){}


};
#endif //TP2JUAREZ_TRAVIESO_H
