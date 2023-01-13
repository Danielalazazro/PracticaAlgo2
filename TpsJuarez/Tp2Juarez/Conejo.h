//
// Created by daniela on 05/01/23.
//

#ifndef TP2JUAREZ_CONEJO_H
#define TP2JUAREZ_CONEJO_H
#include "Animal.h"
class Conejo:public Animal{
public:
    Conejo(std::string nombre, int edad, std::string tamaño,std::string especie,Personalidad* personalidad ): Animal(nombre,edad,tamaño,especie,personalidad){

    }
    void presentar() {
        Animal::presentar();
        std::cout << "Conejo" << std::endl;
    }
    void alimentar(){
        Animal::alimentar();
        std::cout<<"Me alimentaron con lechuga"<<std::endl;
    }
    void bañar(){
        Animal::bañar();
        std::cout<<"Soy un conjejo y me bañaron"<<std::endl;
    }
    virtual ~Conejo(){
        //delete this->personalidadAnimal;
    }
};
#endif //TP2JUAREZ_CONEJO_H
