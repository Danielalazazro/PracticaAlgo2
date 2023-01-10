//
// Created by daniela on 05/01/23.
//

#ifndef TP2JUAREZ_PERRO_H
#define TP2JUAREZ_PERRO_H
#include "Animal.h"
class Perro :public Animal {
public:
    Perro(std::string nombre, int edad, std::string tamaño, std::string especie, Personalidad* personalidad)
            : Animal(nombre, edad, tamaño, especie, personalidad) {

    }

    void alimentar(){
        this->personalidadAnimal->alimentar() ;
        std::cout<<"Me alimnetaron con huesos"<<std::endl;
    }
    void presentar() override{
        Animal::presentar();
        std::cout<<"Perro"<<std::endl;
    }

    void bañar(){

        this->personalidadAnimal->bañar();
        std::cout<< "Soy un perro y me bañaron"<<std::endl;
    }


};
#endif //TP2JUAREZ_PERRO_H
