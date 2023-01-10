//
// Created by daniela on 06/01/23.
//

#ifndef TP2JUAREZ_PERSONALIDAD_H
#define TP2JUAREZ_PERSONALIDAD_H
#include <string>
class Personalidad{
protected:
    int porcentajeHambre;
    int porcentajeBañado;

public:
    Personalidad(){
        this->porcentajeBañado = 100;
        this->porcentajeHambre = 0;
    }
     virtual void aumentarHambre(){
         this->porcentajeHambre += 10;
     }
     virtual void disminurPocentajeBañado(){
        this->porcentajeBañado -= 10;
     }

    // vistrual: el compilardor lo resulve en tiempo de ejecuicion
     virtual std::string getComportamineto() = 0;

    virtual int getPorcentajeHambre() {
        return this->porcentajeHambre;
    }
    virtual int getPorcentajeBañado() {
        return this->porcentajeBañado;
    }

    void alimentar() {
        this->porcentajeHambre = 0;
    }

    void bañar() {
        this->porcentajeBañado = 100;
    }

};
#endif //TP2JUAREZ_PERSONALIDAD_H
