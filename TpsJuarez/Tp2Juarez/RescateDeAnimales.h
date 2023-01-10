//
// Created by daniela on 30/12/22.
//

#ifndef TP2JUAREZ_RESCATEDEANIMALES_H
#define TP2JUAREZ_RESCATEDEANIMALES_H
#include <fstream>
#include "Animal.h"
#include "Perro.h"
#include "Gato.h"
#include "Caballo.h"
#include "Largatija.h"
#include "Conejo.h"
#include "Erizo.h"
#include "Roedor.h"
#include "Personalidad.h"
#include "Sociable.h"
#include "Jugueton.h"
#include "Dormilon.h"
#include "Travieso.h"
class RescateDeAnimales{
private:
    Lista<Animal*>* animales;
    int cantidadTurnos = 0;
    Personalidad* pesonalidad;

public:
    RescateDeAnimales(){
        this->animales = new Lista<Animal*>();
        this->pesonalidad = NULL;
    }


    Personalidad* obtenerPersonalidad(std::string personalidaStr){
        Personalidad* nuevaPersonalidad = NULL;
        if(personalidaStr == "jugueton"){
            nuevaPersonalidad = new Jugueton();
        }
        else if(personalidaStr == "dormilon"){
            nuevaPersonalidad = new Dormilon();

        }
        else if(personalidaStr == "sociable"){
            nuevaPersonalidad = new Sociable();
        }
        else if(personalidaStr == "travieso"){
            nuevaPersonalidad = new Travieso();
        }
        return nuevaPersonalidad;

    }
    void leerArchivo() {
        std::ifstream archivo("animales.csv");
        if (!archivo.is_open()) {
            std::cout << "Error al abrir animales.csv\n";
        }
        std::string nombre;
        std::string edad;
        std::string tamaño;
        std::string especie;
        std::string personalidad;
        while (!archivo.eof()) {
            getline(archivo, nombre, ',');
            if (nombre == "") {
                break;
            }
            getline(archivo, edad, ',');
            getline(archivo, tamaño, ',');
            getline(archivo, especie, ',');
            getline(archivo, personalidad);
            Personalidad* unaPersonalidad = obtenerPersonalidad(personalidad);
            if(especie == "P" ){


                Perro* perro = new Perro(nombre,std::stoi(edad),tamaño,especie, unaPersonalidad);
                animales->agregar(perro);


            }
            else if (especie == "G"){
                Gato* gato = new Gato(nombre, std::stoi(edad), tamaño, especie, unaPersonalidad);
                animales->agregar(gato);

            }
            else if(especie == "E"){
                Erizo* erizo = new Erizo(nombre, std::stoi(edad),tamaño,especie, unaPersonalidad);
                animales->agregar(erizo);

            }
            else if(especie == "C"){
                Caballo* caballo = new Caballo(nombre, std::stoi(edad), tamaño, especie, unaPersonalidad );
                animales->agregar(caballo);

            }
            else if(especie == "R"){
                Roedor* roedor = new Roedor(nombre, std::stoi(edad), tamaño, especie, unaPersonalidad);
                animales->agregar(roedor);

            }
            else if(especie == "O"){
                Conejo* conejo = new Conejo(nombre, std::stoi(edad), tamaño, especie, unaPersonalidad);
                animales->agregar(conejo);

            }
            else if(especie == "L"){
                Lagartija* lagartija = new Lagartija(nombre, std::stoi(edad), tamaño, especie, unaPersonalidad);
                animales->agregar(lagartija);

            }
        }
    }
    void listar(){
        animales->iniciarCursor();
        while (animales->avanzarCursor()){
            animales->obtenerCursor()->imprimirDatos();
        }
    }

    bool verificarNombre(std::string nombreNuevoAnimal) {
        bool distinto = false;
        unsigned int contador = 0;
        animales->iniciarCursor();
        while (animales->avanzarCursor() && !distinto) {
            Animal *animalActual = animales->obtenerCursor();
            if (animalActual->getNombre() != nombreNuevoAnimal) {
                contador++;
                if (contador == animales->contarElemntos()) {
                    distinto = true;
                }
            }
        }
        return distinto;
    }
    void recatarAnimales(){
        std::string nombreNuevo;
        std::string tamaño;
        int edad;
        std::string personalidad;
        std::string especie;
        std::cout << "Ingrese el nombre del animal a ingrsar : "<<std::endl;
        std::cin>> nombreNuevo;
        while(!verificarNombre(nombreNuevo)){
            std::cout<<"Ingresed otro nombre para el animal a rescatar: "<<std::endl;
            std::cin >> nombreNuevo;
        }
        std::cout<<"Ingrese la edad del nuevo animal a ingresar : "<<std::endl;
        std::cin>>edad;
        std::cout<<"Ingrese el tamaño del animal a ingresar: "<<std::endl;
        std::cin>>tamaño;
        std::cout <<"Ingrese la personalidad del nuevo animal: " <<std::endl;
        std::cin>>personalidad;
        std::cout<<"Ingrese la especie del nuevo animal a ingresar: "<<std::endl;
        std::cin>>especie;
        if(especie == "P"){
            Perro* unPerro = new Perro(nombreNuevo, edad, tamaño, especie, obtenerPersonalidad(personalidad));
            agregarAnimal(unPerro);

        }
        else if(especie == "G"){
            Gato* gato = new Gato(nombreNuevo, edad, tamaño, especie, obtenerPersonalidad(personalidad));
            agregarAnimal(gato);

        }
        else if(especie == "C"){
            Caballo* caballo = new Caballo(nombreNuevo,edad, tamaño,especie, obtenerPersonalidad(personalidad));
            agregarAnimal(caballo);

        }
        else if(especie == "R"){
            Roedor* roedor = new Roedor(nombreNuevo, edad, tamaño, especie, obtenerPersonalidad(personalidad));
            agregarAnimal(roedor);

        }
        else if(especie == "O"){
            Conejo* conejo = new Conejo(nombreNuevo, edad, tamaño, especie, obtenerPersonalidad(personalidad));
            agregarAnimal(conejo);

        }
        else if(especie == "L"){
            Lagartija* lagartija = new Lagartija(nombreNuevo, edad, tamaño, especie, obtenerPersonalidad(personalidad));
            agregarAnimal(lagartija);

        }
        else if(especie == "E"){
            Erizo* erizo = new Erizo(nombreNuevo, edad, tamaño, especie, obtenerPersonalidad(personalidad));
            agregarAnimal(erizo);

        }
    }
    void agregarAnimal(Animal* unAnimal){
        bool agregadoAnimal = false;
        animales->iniciarCursor();
        while (animales->avanzarCursor()){
            Animal * animalActual = animales->obtenerCursor();
            if(animalActual->getNombre() != unAnimal->getNombre() && !agregadoAnimal ){
                animales->agregar(unAnimal);
                agregadoAnimal = true;
            }
        }
    }

    void buscarAnimal(std::string nombreAnimal){
        unsigned int contador = 0;
        animales->iniciarCursor();
        while (animales->avanzarCursor()){
            Animal* unAnimal = animales->obtenerCursor();
            contador++;
            if(unAnimal->getNombre() == nombreAnimal ){
                unAnimal->imprimirDatos();
                return;
            }
            else if(animales->contarElemntos() == contador ){
                if(nombreAnimal != unAnimal->getNombre()){
                    std::cout<< "EL nombre no exite en la lista" <<std::endl;
                    std::cout << "Ingrese un nombre valido: "<<std::endl;
                    std::cin>>nombreAnimal;
                    animales->iniciarCursor();
                }
            }
        }
    }
    //void continuarConElegirAnimal(int numeroElegirAnimal , bool* seEligio)
    void continuarConElegirAnimal(int numeroElegirAnimal ,Animal* animalActual){
        animalActual->mostrarEstadisticasDeCuidado();
        if(numeroElegirAnimal == 1){
            animalActual->bañar();

            //*seEligio = true;
        }
        else if(numeroElegirAnimal == 2){
            animales->obtenerCursor()->alimentar();
            //*seEligio = true;
        }

    }

    //void menuAnimal(bool* seEligio)
    void menuAnimal(Animal* animalActual){
        int numeroEleccionAnimal;
        std::cout<<"1.Se desea bañar "<<std::endl;
        std::cout<<"2.alimentar "<<std::endl;
        std::cout<<"3.Saltear"<<std::endl;
        std::cout<<"Ingrese una opcion:"<<std::endl;
        std::cin>>numeroEleccionAnimal;
        continuarConElegirAnimal(numeroEleccionAnimal, animalActual);
        //continuarConElegirAnimal(numeroEleccionAnimal, seEligio);
    }
    void continuarCuidar(int numeroCuidar) {
        if(numeroCuidar == 1){
            std::string elegirAnimal;
            unsigned int contador = 0;
            bool seEligio = false;
            animales->iniciarCursor();
            while (animales->avanzarCursor() && !seEligio ){
                Animal* unAnimal = animales->obtenerCursor();
                unAnimal->imprimirDatos();
                contador++;
                menuAnimal(unAnimal);
                //menuAnimal(&seEligio);
                if(contador == animales->contarElemntos()){
                    cuidarAnimales();
                }
            }
        }
        else if(numeroCuidar == 2){
            animales->iniciarCursor();
            while (animales->avanzarCursor()){
                Animal* animalActual = animales->obtenerCursor();
                animalActual->alimentar();
            }
        }
        else if(numeroCuidar == 3){
            animales->iniciarCursor();
            while (animales->avanzarCursor()){
                Animal* animalActual = animales->obtenerCursor();
                animalActual->bañar();
            }
        }
    }

    void cuidarAnimales(){
        int numeroCuidar;
        std::cout<<"Menu de cuidar animales: "<<std::endl;
        std::cout<<"1.Elegir individualmente "<<std::endl;
        std::cout<<"2.Alimentar a todos "<<std::endl;
        std::cout<<"3.Bañar a todos"<<std::endl;
        std::cout<<"4.Regresar al inicio"<<std::endl;
        std::cout<<"Ingrese una opcion: "<<std::endl;
        std::cin>>numeroCuidar;
        continuarCuidar(numeroCuidar);
    }

    void removerAnimaleImprimir(std::string eleccionElegida, int posicionAnimal,Animal* animal) {
        animal->imprimirDatos();
        std::cout << "Desea elegir este animal(s/n)?: " << std::endl;
        std::cin>>eleccionElegida;
        if (eleccionElegida == "s") {
            std::cout<<"Se elimino de la lista de animales en adopcion a: "<<animal->getNombre();
            animales->remover(posicionAnimal);
        }
    }

    void adoptarAnimal() {
        int cantidadDeEspacio = 0;
        std::string eleccion;
        std::cout<<"¿Cuanto es el espacio disponible que tiene para adoptar a su nueva mascota (en metros cuadrados)? "<<std::endl;
        std::cin>>cantidadDeEspacio;
        if(cantidadDeEspacio < 2 && cantidadDeEspacio > 0) {
            int i = 0;
            animales->iniciarCursor();
            while (animales->avanzarCursor()) {
                Animal *animalActual = animales->obtenerCursor();
                i++;
                if (animalActual->getTamaño() == "diminuto") {
                    removerAnimaleImprimir(eleccion, i, animalActual);
                }
            }
        }
        else if(cantidadDeEspacio  < 10 && cantidadDeEspacio >= 2){
            int j = 0;
            animales->iniciarCursor();
            while (animales->avanzarCursor()){
                Animal* unAnimal = animales->obtenerCursor();
                j++;
                if(unAnimal->getTamaño() == "pequeño"){
                    removerAnimaleImprimir(eleccion,j,unAnimal);
                }
                else if(unAnimal->getTamaño() != "mediano" && unAnimal->getTamaño() != "gigante" && unAnimal->getTamaño() != "gigante"){
                    removerAnimaleImprimir(eleccion,j,unAnimal);
                }
            }
        }
        else if(cantidadDeEspacio >= 10 && cantidadDeEspacio < 20){
            int k = 0;
            animales->iniciarCursor();
            while (animales->avanzarCursor()){
                Animal* animal = animales->obtenerCursor();
                k++;
                if(animal->getTamaño() == "mediano"){
                    removerAnimaleImprimir(eleccion,k,animal);
                }
                else if(animal->getTamaño() != "mediano" && animal->getTamaño() != "grande" && animal->getTamaño() != "gigante"){
                    removerAnimaleImprimir(eleccion,k,animal);
                }

            }
        }
        else if(cantidadDeEspacio >= 20 && cantidadDeEspacio < 50){
            int l = 0;
            animales->iniciarCursor();
            while (animales->avanzarCursor()){
                Animal* esteAnimal = animales->obtenerCursor();
                l++;
                if(esteAnimal->getTamaño() == "grande"){
                    std::cout<<"Este animal seria el adecuado para su espacio "<<std::endl;
                    removerAnimaleImprimir(eleccion,l,esteAnimal);
                }
                else if(esteAnimal->getTamaño() != "grande" && esteAnimal->getTamaño() != "gigante"){
                    std::cout<<"Puede adoptar a cualquier animal de la lista de adopcion  que no sean gigante: "<<std::endl;
                    removerAnimaleImprimir(eleccion,l,esteAnimal);
                }
            }
        }
        else if(cantidadDeEspacio >= 50){
            int m = 0;
            animales->iniciarCursor();
            while (animales->avanzarCursor()){
                Animal* aquelAnimal = animales->obtenerCursor();
                m++;
                if(aquelAnimal->getTamaño() == "gigante"){
                    removerAnimaleImprimir(eleccion,m,aquelAnimal);
                }
                else if(aquelAnimal->getTamaño() != "gigante"){
                    removerAnimaleImprimir(eleccion,m,aquelAnimal);
                }
            }
        }
    }
    void guardarYsalir() {
        std::ofstream archivo;
        archivo.open("animales.csv");
        animales->iniciarCursor();
        while (animales->avanzarCursor()){
            if(animales->obtenerCursor() != NULL){
                Animal* animalActual = animales->obtenerCursor();
                archivo << animalActual->getNombre() << ",";
                archivo << animalActual->getEdad() << ",";
                archivo << animalActual->getTamaño() << ",";
                archivo << animalActual->getEspecie() << ",";
                archivo << animalActual->getComportamineto() << "\n";
            }
            else if(animales->obtenerCursor() == NULL){
                return;
            }
        }
        archivo.close();
    }
    void continuar(int numero) {
        if(numero == 1){
            listar();
        }
        else if(numero == 2){
            recatarAnimales();
        } else if(numero == 3){
            std::string nombreAnimal;
            std::cout<<"Ingrese el nombre del animal: "<<std::endl;
            std::cin>>nombreAnimal;
            buscarAnimal(nombreAnimal);
        }
        else if(numero == 4){
            cuidarAnimales();
        }
        else if(numero == 5){
            adoptarAnimal();
        }
    }
    void verificarNumero(int numero) {
        bool eleccionNumero = false;
        while (!eleccionNumero){
            if((numero > 0)  && (numero < 7)){
                eleccionNumero = true;
                continuar(numero);
            }
            else{
                std::cout<<"Ingrese un valor valido: "<<std::endl;
                std::cin>>numero;
            }
        }
    }
    void aumnetarHambreDeAnimales() {
        animales->iniciarCursor();
        while (animales->avanzarCursor()){
            Animal* unAnimal = animales->obtenerCursor();
            //
            unAnimal->aumentarHambre();
        }
    }
    void disminuirHigineDeAnimales() {
        animales->iniciarCursor();
        while (animales->avanzarCursor()){
            Animal* animalActual = animales->obtenerCursor();
            animalActual->disminurPocentajeBañado();

        }
    }

    void opcionesDelMenuYincrementoDeHambreYdecrmetoBañado() {
        aumnetarHambreDeAnimales();
        disminuirHigineDeAnimales();
        this->cantidadTurnos++;
        std::cout<<"\n1.Listar animales "<<std::endl;
        std::cout<<"2.Rescatar animal "<<std::endl;
        std::cout<<"3.Buscar animal "<<std::endl;
        std::cout<<"4.Cuidar animal"<<std::endl;
        std::cout<<"5.Adoptar animal "<<std::endl;
        std::cout<<"6.Guardar y salir"<<std::endl;
        std::cout<<"Ingrese una opcion del menu: "<<std::endl;

    }

    void menu(){
        bool continuarJuego = true;
        std::string eleccionJuego;
        int numero = 0;
        std::cout<<"Bienvenidos al menu de la reserva de animales: "<<std::endl;
        opcionesDelMenuYincrementoDeHambreYdecrmetoBañado();
         //REPITE VARIABLE AL PEDO MAL JODIDA
        std::cin>>numero;
        verificarNumero(numero);
        while (continuarJuego) {
            opcionesDelMenuYincrementoDeHambreYdecrmetoBañado();
            std::cin >> numero;
            verificarNumero(numero);

            if (numero == 6) {
                guardarYsalir();
                std::cout << "Gracias por participar en el rescate de animales y la adopcion" << std::endl;
                continuarJuego = false;
            }
        }
    }
    void iniciarRescateYAdopccion(){
        leerArchivo();
        menu();
    }
    virtual ~RescateDeAnimales(){

        animales->iniciarCursor();
        while (animales->avanzarCursor()){
            Animal* animal = animales->obtenerCursor();
            delete animal;
        }
        delete this->animales;
        
    }
};
#endif //TP2JUAREZ_RESCATEDEANIMALES_H
