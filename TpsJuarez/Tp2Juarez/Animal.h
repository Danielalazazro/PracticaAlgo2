//
// Created by daniela on 28/12/22.
//

#ifndef TP2JUAREZ_ANIMAL_H
#define TP2JUAREZ_ANIMAL_H
#include <iostream>
#include <fstream>
#include "Lista.h"
#include "Personalidad.h"
class Animal{
protected:
    std::string nombre ;
    int edad;
    std::string tamaño;
    std::string especie;
    Personalidad* personalidadAnimal;
    //int porcentajeBañado ;
    //int porcentajeHambre ;

public:
    Animal(std::string nombre, int edad, std::string tamaño,std::string especie,Personalidad* personalidad ){
        this->nombre = nombre;
        this->edad = edad;
        this->especie = especie;
        this->tamaño = tamaño;
        this->personalidadAnimal = personalidad;
        //this->porcentajeBañado = 100;
        //this->porcentajeHambre = 0;


    }
    std::string getNombre(){
        return this->nombre;
    }
    std::string getEspecie(){
        return this->especie;
    }

    int getEdad(){
        return this->edad;
    }
    void imprimirDatos(){
        std::cout<< "El nombre del animal es: "<<getNombre() <<"\t";
        std::cout<< "La especie del animal es: "<<getEspecie() <<"\t\t";
        std::cout<< "La personalidad del animal es :"<<personalidadAnimal->getComportamineto()<<"\t\t";
        std::cout<< "La edad del animal es: "<<getEdad() <<"\t\t";
        std::cout << "EL porcentaje del hambre: " << personalidadAnimal->getPorcentajeHambre() <<"\t\t";
        std::cout << "El porcentaje de bañado de un animal es: "<<personalidadAnimal->getPorcentajeBañado() <<"\t\t";
        std::cout<<"EL tamaño es: "<<getTamaño()<<"\n";

    }
    std::string getTamaño(){
        return this->tamaño;
    }
    /*
     * pre: se debera listar todos los animales con su nombre, edad, tamaño,especie en forma completa
     *      personalidad hambre e higiene
     */
    virtual void presentar(){
        std::cout<<"Hola soy un animal del tipo: ";
    }
    virtual void alimentar(){

    }

    virtual void bañar() {

    }
    //Animal le delega a la personalidad:
    std::string getComportamineto() {
        return personalidadAnimal->getComportamineto();
    }

    virtual void aumentarHambre() {
        personalidadAnimal->aumentarHambre();
    }

    virtual void disminurPocentajeBañado() {
        personalidadAnimal->disminurPocentajeBañado();

    }

    void mostrarEstadisticasDeCuidado() {
        std::cout<<"Estado de bañado: " <<personalidadAnimal->getPorcentajeBañado()<<std::endl;
        std::cout<<"Estado de hambre: "<<personalidadAnimal->getPorcentajeHambre()<<std::endl;

    }
    ~Animal(){
        delete this->personalidadAnimal;
    }
};
#endif //TP2JUAREZ_ANIMAL_H
