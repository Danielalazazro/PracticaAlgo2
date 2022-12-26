//
// Created by daniela on 22/12/22.
//
#ifndef TPSJUAREZ_GENERO_H
#define TPSJUAREZ_GENERO_H
#include <string>
class Genero{
private:
    std::string generos[6] = {"A","C","D","P","R","T"};
    int contador;
    int acumuladorPuntaje;
    std::string genero;
public:
    Genero(std::string genero){
        if(!verificarGneroValido(genero)){
            throw "Genero no es valido";
        }
        this->genero = genero;
        this->contador = 0;
        this->acumuladorPuntaje = 0;
    }

    Genero() {}

    void acumularPuntaje( int puntaje){
        this->acumuladorPuntaje += puntaje;
        this->contador++;
    }
    int getPromedio(){
        int promedio = 0;
        if(this->acumuladorPuntaje <= 0 && this->contador <= 0){
            return 0;
        }
        promedio = this->acumuladorPuntaje/ this->contador;
        return promedio;
    }
    bool verificarGneroValido(std::string genero){
        bool esValido = false;
        for(int i = 0;i < 6;i++){
            if( this->generos[i] == genero){
                esValido = true;
            }
        }
        return esValido;
    }
    std::string getGenero(){
        return this->genero;
    }
    int getContador(){
        return this->contador;
    }



};
#endif //TPSJUAREZ_GENERO_H
