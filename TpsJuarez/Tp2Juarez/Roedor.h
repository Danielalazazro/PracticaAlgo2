//
// Created by daniela on 05/01/23.
//

#ifndef TP2JUAREZ_ROEDOR_H
#define TP2JUAREZ_ROEDOR_H
#include "Animal.h"
class Roedor:public Animal{
public:
    Roedor(std::string nombre, int edad, std::string tamaño,std::string especie,Personalidad* personalidad ):Animal( nombre, edad,tamaño,especie,personalidad){

    }
    void presentar(){
        Animal::presentar();
        std::cout<<"Roedor"<<std::endl;
    }
    void alimentar(){
        this->personalidadAnimal->alimentar();
        std::cout<<"Me alimento de queso"<<std::endl;
    }
    void bañar(){

        std::cout<<"No requiero bañarme porque soy un roedor"<<std::endl;
    }
    void disminurPocentajeBañado(){
        this->personalidadAnimal->bañar();
    }
    ~Roedor(){}
};
#endif //TP2JUAREZ_ROEDOR_H
