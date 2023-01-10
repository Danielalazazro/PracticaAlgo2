//
// Created by daniela on 05/01/23.
//

#ifndef TP2JUAREZ_GATO_H
#define TP2JUAREZ_GATO_H
#include "Animal.h"
class Gato:public Animal{
public:

    Gato(std::string nombre, int edad, std::string tamaño, std::string especie, Personalidad* personalidad)
            : Animal(nombre, edad, tamaño, especie, personalidad) {

    }

    void presentar() override{
        Animal::presentar();
        std::cout<<" Gato"<<std::endl;
    }
    void alimentar() override{
        Animal::alimentar();
        std::cout<< "Me alimnentaron con atun"<<std::endl;
    }
    void bañar(){
        std::cout<< "Soy un gato y no requiero bañarme"<<std::endl;
    }
    void disminurPocentajeBañado(){
        this->personalidadAnimal->bañar();
    }

};
#endif //TP2JUAREZ_GATO_H
