//
// Created by daniela on 05/01/23.
//

#ifndef TP2JUAREZ_LARGATIJA_H
#define TP2JUAREZ_LARGATIJA_H
#include "Animal.h"
class Lagartija:public Animal{
public:
    Lagartija(std::string nombre, int edad, std::string tamaño,std::string especie,Personalidad* personalidad ): Animal(nombre,edad,tamaño,especie,personalidad){

    }
    void presentar(){
        Animal::presentar();
        std::cout<<"Lagartija"<<std::endl;
    }
    void alimentar(){
        std::cout<<"Me alimneto de insectos"<<std::endl;
    }
    void bañar(){
        std::cout<<"No requiero  bañarme  porque  soy una lagartija "<<std::endl;
    }
    void disminurPocentajeBañado(){
        this->personalidadAnimal->bañar();
    }
    ~Lagartija(){}
};
#endif //TP2JUAREZ_LARGATIJA_H
