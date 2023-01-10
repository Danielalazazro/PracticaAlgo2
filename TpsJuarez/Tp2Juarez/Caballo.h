//
// Created by daniela on 05/01/23.
//

#ifndef TP2JUAREZ_CABALLO_H
#define TP2JUAREZ_CABALLO_H
#include "Animal.h"
class Caballo:public Animal{
public:
    Caballo(std::string nombre, int edad, std::string tamaño,std::string especie,Personalidad* personalidad ): Animal(nombre,edad,tamaño,especie,personalidad){

    }
    void presentar(){
        Animal::presentar();
        std::cout<<"Caballo"<<std::endl;
    }
    void alimentar(){

        std::cout<<"Me alimnto de manzanas"<<std::endl;
    }
    void bañar(){

        std::cout<<"Me bañaron y soy un caballo"<<std::endl;
    }

};
#endif //TP2JUAREZ_CABALLO_H
