//
// Created by daniela on 19/12/22.
//

#ifndef TPSJUAREZ_LIBRO_H
#define TPSJUAREZ_LIBRO_H
#include <string>

class Libro {
private:
    int puntaje;
    int contadorGenenro;
    int puntajeTotal;
    std::string titulo;
    std::string genero;
public:
    Libro(int puntaje, std::string titulo, std::string genero){
        this->puntaje = puntaje;
        this->puntajeTotal = 0;
        this->titulo = titulo;
        this->genero = genero;
    }
    int getPuntaje(){
        return this->puntaje;
    }
    std::string getTitulo(){
        return this->titulo;
    }
    std::string getGenero(){
        return this->genero;
    }
    void setPuntaje(int nuevoPuntaje){
        this->puntaje = nuevoPuntaje;
    }
    void imprimir(){
        std::cout << this->titulo << std::endl;
        std::cout << this->genero << std::endl;
        std::cout << this->puntaje << std::endl;
    }

};


#endif //TPSJUAREZ_LIBRO_H
