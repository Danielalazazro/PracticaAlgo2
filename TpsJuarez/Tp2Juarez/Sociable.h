//
// Created by daniela on 06/01/23.
//

#ifndef TP2JUAREZ_SOCIABLE_H
#define TP2JUAREZ_SOCIABLE_H
#include <iostream>
#include "Personalidad.h"
class Sociable:public Personalidad{
public:
    Sociable(): Personalidad(){

    }
    virtual void disminurPocentajeBañado(){
        Personalidad::disminurPocentajeBañado();
        this->porcentajeBañado += 5;
        if(this->porcentajeBañado < 0){
            this->porcentajeBañado = 0;
        }
    }
    virtual void aumentarHambre(){
        Personalidad::aumentarHambre();
    }
    std::string getComportamineto(){
        std::string comportamiento;
        comportamiento = "sociable";
        return comportamiento;
    }

    int getPorcentajeHambre(){
        return this->porcentajeHambre;
    }
    int getPorcentajeBañado(){
        return this->porcentajeBañado;
    }
    virtual ~Sociable(){}
};
#endif //TP2JUAREZ_SOCIABLE_H
