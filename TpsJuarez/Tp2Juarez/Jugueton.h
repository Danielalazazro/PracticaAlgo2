//
// Created by daniela on 06/01/23.
//

#ifndef TP2JUAREZ_JUGUETON_H
#define TP2JUAREZ_JUGUETON_H
#include "Personalidad.h"
class Jugueton:public Personalidad{
public:
    Jugueton(): Personalidad(){

    }
    virtual void disminurPocentajeBañado(){
        Personalidad::disminurPocentajeBañado();
    }
    virtual void aumentarHambre(){
        Personalidad::aumentarHambre();
        this->porcentajeHambre += 10;
    }
    std::string getComportamineto(){
        std::string comportamineto;
        comportamineto = "jugueton";
        return comportamineto;
    }
    int getPorcentajeHambre(){
        return this->porcentajeHambre;
    }
    int getPorcentajeBañado(){
        return this->porcentajeBañado;
    }
    virtual ~Jugueton(){}
};
#endif //TP2JUAREZ_JUGUETON_H
