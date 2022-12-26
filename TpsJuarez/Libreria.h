//
// Created by daniela on 19/12/22.
//

#ifndef TPSJUAREZ_LIBRERIA_H
#define TPSJUAREZ_LIBRERIA_H
#include "Libro.h"
#include "Vector.h"
#include <iostream>
#include <fstream>
#include "Genero.h"
class Libreria {
private:

    Vector<Libro*>* libros;
    std::string generos[6];
    int cantidadMaximaLibros;
    Genero aventura ;
    Genero cienciaFiccion ;
    Genero didactica ;
    Genero policiaca ;
    Genero romance ;
    Genero terror ;

public:
    Libreria(int cantidadMaximaDeLibros){
        if(cantidadMaximaDeLibros < 0){
            throw "La cantidad maxima debe ser distinto de mayor a 0";
        }
        //
        this->aventura = Genero("A");
        this->cienciaFiccion = Genero("C");
        this->didactica = Genero("D");
        this->policiaca = Genero("P");
        this->romance = Genero("R");
        this->terror = Genero("T");
        this->cantidadMaximaLibros = cantidadMaximaDeLibros;
        this->libros = new Vector<Libro*>( cantidadMaximaDeLibros,NULL);
        this->generos[0] = "A";
        this->generos[1] = "C";
        this->generos[2] = "D";
        this->generos[3] = "P";
        this->generos[4] = "R";
        this->generos[5] = "T";
        for(int i = 1; i <= this->libros->getLongitud();i++){
            this->libros->agregar(i, NULL);
        }
    }

    void agegarLibro(Libro* unLibro){

        if(!generoValido(unLibro)){
            //throw "El genero no es valido";
            return;
        }
        for(int i = 1; i <= this->libros->getLongitud(); i++){
            if(this->libros->obtener(i) == NULL){
                this->libros->agregar(i, unLibro);
                if(unLibro->getGenero() == generos[0]){
                    this->aventura.acumularPuntaje(this->libros->obtener(i)->getPuntaje());
                }
                else if(unLibro->getGenero() == generos[1]) {
                    this->cienciaFiccion.acumularPuntaje(this->libros->obtener(i)->getPuntaje());
                }
                else if(unLibro->getGenero() == generos[2]){
                    this->didactica.acumularPuntaje(this->libros->obtener(i)->getPuntaje());
                }
                else if(unLibro->getGenero() == generos[3]){
                    this->policiaca.acumularPuntaje(this->libros->obtener(i)->getPuntaje());
                }
                else if(unLibro->getGenero() == generos[4]){
                    this->romance.acumularPuntaje(this->libros->obtener(i)->getPuntaje());
                }
                else if(unLibro->getGenero() == generos[5]){
                    this->terror.acumularPuntaje(this->libros->obtener(i)->getPuntaje());
                }
                return;
            }
        }
    }
    void listar() {
        for(int i = 1; i <= this->libros->getLongitud(); i++ ){
            if(this->libros->obtener(i) != NULL){
                this->libros->obtener(i)->imprimir();
            }
        }
    }
    void editarPuntajeLibro(int nuevoPuntaje, std::string titulo){
        for(int i = 1; i <= this->libros->getLongitud(); i++){
            if(this->libros->obtener(i) != NULL){
                if(this->libros->obtener(i)->getTitulo() == titulo){
                    this->libros->obtener(i)->setPuntaje(nuevoPuntaje);
                    return;
                }
            }
        }
    }
    int obtenerPuntajeMayor(){
        int maximoPuntaje = this->libros->obtener(1)->getPuntaje();
        for(int i = 1; i <= this->libros->getLongitud(); i++){
            if(this->libros->obtener(i) != NULL){
                if(this->libros->obtener(i)->getPuntaje() > maximoPuntaje){
                    maximoPuntaje = this->libros->obtener(i)->getPuntaje();
                }
            }
        }
        return maximoPuntaje;
    }
    void mostrarLibroFavorito(){
        for(int i = 1; i <= this->libros->getLongitud(); i++){
            if(this->libros->obtener(i) == NULL){
                return;
            }
            if(this->libros->obtener(i)->getPuntaje() == obtenerPuntajeMayor()){
                std::cout<< this->libros->obtener(i)->getTitulo() <<std::endl;
            }
        }
    }

    //ordenar elementos del vector con sus puntajes:
    void ordenarPorPuntajeDeMenorAMayor() {
        Libro *aux;
        for (int i = 1; i <= this->libros->getLongitud(); i++) {
            if (this->libros->obtener(i) != NULL) {
                for (int j = 1; j <= this->cantidadMaximaLibros - 1; j++) {
                    if(this->libros->obtener(j) !=NULL && this->libros->obtener(j + 1) != NULL){
                        if (this->libros->obtener(j)->getPuntaje() > this->libros->obtener(j + 1)->getPuntaje()) {
                            aux = this->libros->obtener(j);
                            this->libros->obtener(j) = this->libros->obtener(j + 1);
                            this->libros->obtener(j + 1) = aux;
                        }
                    }
                }
            }
        }
        //mostrarElementos();
    }
    void mostrarElementosDeLosTresLibrosDeMenorPuntaje(){
        for(int  i = 1; i <= 3; i++){
            if(this->libros->obtener(i) != NULL){
                std::cout << this->libros->obtener(i)->getTitulo() <<"\t su puntaje es: "<< this->libros->obtener(i)->getPuntaje() <<std::endl;
            }
        }
    }
    int maximo(int numero1, int numero2){
        int maximo = 0;
        if(numero1 > numero2){
            maximo =  numero1;
        }
        else if(numero1 < numero2){
            maximo = numero2;
        }
        return maximo;

    }
    void mostrarGeneroMasLeido(){
        int maximo1 = maximo(this->aventura.getContador(), this->cienciaFiccion.getContador());
        int maximo2 = maximo(this->didactica.getContador(), this->policiaca.getContador());
        int maximo3 = maximo(this->romance.getContador(), this->terror.getContador());
        int maximo4 = maximo(maximo1,maximo2);
        int maximo5 = maximo(maximo4, maximo3);
        if( maximo5 == this->aventura.getContador()) {
            std::cout << this->generos[0]<<std::endl;
        }
        else if(maximo5 == this->cienciaFiccion.getContador()){
            std::cout << this->generos[1] <<std::endl;
        }
        else if(maximo5 == this->didactica.getContador()){
            std::cout << "Genero mas leido es: "<< this->generos[2] <<std::endl;
        }
        else if(maximo5 == this->policiaca.getContador()){
            std::cout << "Genero mas leido es: "<<this->generos[3] << std::endl;
        }
        else if(maximo5 == this->romance.getContador()){
            std::cout << "Genero mas leido es: "<<this->generos[4] <<std::endl;
        }
        else if(maximo5 == this->romance.getContador()){
            std::cout <<"Genero mas leido es: "<<this->generos[5] <<std::endl;
        }
    }
    bool generoValido(Libro* unLibro){
        bool esIgualAlGenero = false;
        std::string generos[6] = {"A","C","D","P","R","T"};
        for(int i = 0; i < 6; i++){
            if(unLibro->getGenero() == generos[i]){
                esIgualAlGenero = true;
            }
        }
        return esIgualAlGenero;
    }
    void  mostrarGeneroFavorito(){
        int promedioAventura = this->aventura.getPromedio();
        int promedioCienciaFiccion = this->cienciaFiccion.getPromedio();
        int promedioDidactica = this->didactica.getPromedio();
        int promedioPoliciaca = this->policiaca.getPromedio();
        int promedioRomance = this->romance.getPromedio();
        int promedioTerror = this->terror.getPromedio();
        int maxPromedio1 = maximo(promedioAventura, promedioCienciaFiccion);
        int maxPromedio2 = maximo(promedioDidactica,promedioPoliciaca);
        int maxPromedio3 = maximo(promedioRomance,promedioTerror);
        int maximoProm1 = maximo(maxPromedio1,maxPromedio2);
        int maximoProm2 = maximo(maximoProm1,maxPromedio3);
        if(promedioAventura == maximoProm2){
            std::cout <<"genero favorito:" <<this->generos[0]<<std::endl;
        }
        else if(promedioCienciaFiccion == maximoProm2){
            std::cout<< "genero favorito:" <<this->generos[1] <<std::endl;
        }
        else if(promedioDidactica == maximoProm2){
            std::cout << "genero favorito:" <<this->generos[2] <<std::endl;
        }
        else if(promedioPoliciaca == maximoProm2){
            std::cout << "genero favorito:" <<this->generos[3]<<std::endl;
        }
        else if(promedioRomance == maximoProm2){
            std::cout<< "genero favorito:" <<this->generos[4] <<std::endl;
        }
        else if(promedioTerror == maximoProm2){
            std::cout << "genero favorito:" <<this->generos[5] <<std::endl;
        }
    }
    void guardarArchivoConCambios(){
        std::ofstream archivo;
        archivo.open("libros.csv");
        for(int i = 1 ;i <= this->libros->getLongitud(); i++){
            if(this->libros->obtener(i) == NULL){
                archivo.close();
                return;
            }
            Libro* unlibro = this->libros->obtener(i);
            archivo << unlibro->getTitulo() << ",";
            archivo << unlibro->getGenero() << ",";
            archivo << unlibro->getPuntaje() << "\n";
        }
        archivo.close();
    }
    void leerArchivo(){
        std::ifstream  archivo("libros.csv");
        if (! archivo.is_open()) {
            std::cout << "Error al abrir archivo.csv\"\n";
        }
        std::string nombre;
        std::string genero;
        std::string puntaje;

        while( !archivo.eof()  ){

            getline(archivo,nombre,',');
            if(nombre == ""){
                break;
            }
            getline(archivo,genero,',');
            getline(archivo,puntaje);
            Libro* libro = new Libro(std::stoi( puntaje), nombre, genero);
            agegarLibro(libro);
        }
    }
    void mostrarMenuDeJuego(){
        bool continuar = true;
        int numero = 0;
        std::cout << "Bienvenidos al eterno dilema del lector"<<std::endl;
        std::cout<<"Menu del eterno delimea del lector:"<<std::endl;
        std::cout<<"1.Listar libros leidos"<<std::endl;
        std::cout<<"2.Agregar libro"<<std::endl;
        std::cout<<"3.Editar el puntaje de un libro por titulo"<<std::endl;
        std::cout<<"4.Mostrar libro favorito"<<std::endl;
        std::cout<<"5.Mostrar los 3 libros con menor puntaje "<<std::endl;
        std::cout<<"6.Mostrar gènero màs leido "<<std::endl;
        std::cout<<"7.Mostrar genero favorito"<<std::endl;
        std::cout<<"8.Guardar y salir"<<std::endl;
        std::cout<<"Ingrese un numero del menu: "<<std::endl;
        std::cin>>numero;
        continuarJuego(numero);
        std::string palabra ;

        while (continuar){
            std::cout <<"\nDesea continuar (8 para salir) : "<<std::endl;
            std::cin>> palabra;
            if(palabra == "s"){
                std::cout<<"Ingrese un numero del menu: "<<std::endl;
                std::cin >>numero;
                continuarJuego(numero);
            }
            else if(palabra == "8"){
                guardarArchivoConCambios();
                std::cout<<"Gracias por participar en el dilema del lector"<<std::endl;
                continuar = false;
            }
        }
    }
    void continuarJuego(int numero){
        if(numero == 1){
            listar();
        }
        else if(numero == 2){
            int nuevoPuntaje = 0;
            std::string nuevoTitulo = "";
            std::string nuevoGenero = "";
            std::cout<<"Ingrese un puntaje para agregarlo al nuevo libro:"<<std::endl;
            std::cin>>nuevoPuntaje;
            std::cout<<"Ingrese nombre del titulo del libro:  "<<std::endl;
            std::cin>>nuevoTitulo;
            std::cout<<"Ingrese el genero del libro: "<<std::endl;
            std::cin>>nuevoGenero;
            agegarLibro(new Libro(nuevoPuntaje,nuevoTitulo,nuevoGenero));

        }
        else if(numero == 3){
            int numeroPuntaje;
            std::string nombreTitulo;
            std::cout<<"Ingrese un numero nuevo para el puntaje"<<std::endl;
            std::cin>>numeroPuntaje;
            std::cout<<"Ingrese el titulo del libro para editar su puntaje"<<std::endl;
            std::cin>>nombreTitulo;
            editarPuntajeLibro(numeroPuntaje,nombreTitulo);

        }
        else if(numero == 4){
            mostrarLibroFavorito();
        }
        else if(numero == 5){
            mostrarElementosDeLosTresLibrosDeMenorPuntaje();
        }
        else if(numero == 6){
            std::cout<<"Genero mas leido es:"<<std::endl;
            mostrarGeneroMasLeido();
        }
        else if(numero == 7) {
            mostrarGeneroFavorito();
        }
    }
    void iniciarJuego(){
        leerArchivo();
        mostrarMenuDeJuego();
    }
    ~Libreria(){
        for(int i = 1; i <= this->libros->getLongitud(); i++){
            if(this->libros != NULL){
                delete this->libros->obtener(i);
            }
        }
        delete this->libros;

    }
};
#endif //TPSJUAREZ_LIBRERIA_H
