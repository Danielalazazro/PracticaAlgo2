//
// Created by daniela on 05/01/23.
//

#ifndef TP2JUAREZ_ERIZO_H
#define TP2JUAREZ_ERIZO_H
#include "Animal.h"
class Erizo:public Animal{
public:
    Erizo(std::string nombre, int edad, std::string tamaño,std::string especie,Personalidad* personalidad ): Animal(nombre,edad,tamaño,especie,personalidad){

    }
    void presentar(){
        Animal::presentar();
        std::cout<<"Erizo"<<std::endl;
    }
    void alimentar(){
       Animal::alimentar();
        std::cout<<"Me alimnetaron con insectos"<<std::endl;
    }
    void bañar(){
        Animal::bañar();
        std::cout<<"Soy un Erizo y me bañaron"<<std::endl;
    }
    virtual ~Erizo(){}

};
#endif //TP2JUAREZ_ERIZO_H
